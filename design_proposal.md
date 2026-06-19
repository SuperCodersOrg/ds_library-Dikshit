# Design Proposal

## Project Overview

This project implements three fundamental data structures in C++:

1. Dynamic Array
2. Singly Linked List
3. Hash Map (using Separate Chaining)


---

# Section 1 — Public API

The public API includes all methods that users can call. The APIs are designed to provide the most important operations.

## DynamicArray:
A Dynamic Array is a contiguous memory data structure that automatically grows when its capacity becomes full. Unlike a fixed-size array, a dynamic array can resize itself during runtime, allowing flexible storage of elements while still providing O(1) index-based access.

### Methods

```cpp
template <typename T>
class DynamicArray {
private:
    T* data_;
    int size_;
    int capacity_;

    void resize(int newCapacity);

public:
    // Constructors
    DynamicArray();
    

    // Rule of Three
    ~DynamicArray(); 
    DynamicArray(const DynamicArray& other);
    DynamicArray& operator=(const DynamicArray& other);

    // Element operations
    void append(T value);
    void insert(int index, T value);
    void remove(int index);

    T get(int index) const;
    void set(int index, T value);

    // Capacity / Size
    int size() const;
    int capacity() const;
    bool empty() const;

    // Utility
    void clear();
};
```

### Why this API?

The DynamicArray API includes methods for adding, removing, and accessing elements. The `get()` and `set()` methods make it easy to read and modify values while keeping the array data private. The `size()` and `capacity()` methods allow users to see how many elements are stored and how much memory is available. Copy constructor and assignment operator are included to support deep copying.

---

## LinkedList:
A Linked List is a linear data structure consisting of nodes connected through pointers. Each node stores data and links to neighboring nodes. In a Doubly Linked List, every node contains both a next pointer and a previous pointer, allowing traversal in both directions.

### Methods

```cpp
template <typename T>
class LinkedList {
private:
    struct Node {
        T data;
        Node* prev;
        Node* next;

        Node(T value)
            : data(value),
              prev(nullptr),
              next(nullptr) {}
    };

    Node* head_;
    Node* tail_;
    int size_;

public:
    // Constructors
    LinkedList();

    // Rule of Three
    ~LinkedList();
    LinkedList(const LinkedList& other);
    LinkedList& operator=(const LinkedList& other);

    // Insertion
    void insertFront(T value);
    void insertBack(T value);
    void insert(int index, T value);

    // Deletion
    void deleteFront();
    void deleteBack();
    void remove(int index);

    // Search
    bool search(T value) const;

    // Capacity
    int size() const;
    bool empty() const;

    // Utility
    void clear();
};
```


### Why this API?

The LinkedList API is implemented as a doubly linked list. Each node stores pointers to both the next and previous nodes, allowing traversal in both directions. This makes insertion and deletion operations easier because neighboring nodes can be accessed directly without always traversing from the head.

---

## HashMap:
A Hash Map is a key-value data structure that uses a hash function to map keys to storage locations called buckets. It provides O(1) average-time insertion, lookup, and deletion operations.

### Methods

```cpp
template <typename K, typename V>
class HashMap {
private:
    struct Entry {
        K key;
        V value;
        Entry* next;

        Entry(const K& k, const V& v)
            : key(k), value(v), next(nullptr) {}
    };

    Entry** buckets_;
    int size_;
    int capacity_;

    int hash(const K& key) const;
    void resize(int newCapacity);

public:
    // Constructors
    HashMap();
   

    // Rule of Three
    ~HashMap();
    HashMap(const HashMap& other);
    HashMap& operator=(const HashMap& other);

    // Insert / Update
    void set(const K& key,
             const V& value);

    // Lookup
    V get(const K& key) const;
    bool exists(const K& key) const;

    // Removal
    void remove(const K& key);

    // Information
    int size() const;
    double loadFactor() const;

    // Utility
    void clear();
};
```

### Why this API?

The HashMap API stores data as key-value pairs. The `set()` method is used for both inserting new data and updating existing data. The `get()` method retrieves a value using its key. The `exists()` method checks whether a key is present. The `loadFactor()` method is included because it helps show when the table should be resized. Hashing and collision handling are kept private because users do not need to interact with those details directly.

---

## Redis Lite:
Redis Lite is a simplified in-memory key-value database built on top of the HashMap implementation. It stores data in memory and provides fast operations such as SET, GET, EXISTS, and DELETE.

## Methods

```cpp

template <typename K, typename V>
class RedisLite {
private:
    HashMap<K, V> database;

public:
    // Constructor
    RedisLite();

    // Key-Value operations
    void set(
        const K& key,
        const V& value);

    V get(
        const K& key) const;

    bool exists(
        const K& key) const;

    void remove(
        const K& key);

    // Information
    int size() const;

    // Utility
    void clear();
};/
```

### Why this API?

The API provides the main operations expected from a key-value database. The `set()` method is used to add a new key-value pair or update the value of an existing key. The `get()` method retrieves a stored value using its key, while `exists()` checks whether a key is present in the database without returning its value. The `remove()` method deletes a key-value pair from storage. The `size()` method returns the number of stored records, and `clear()` removes all data from the database.

---

# Section 2 — Internal Representation

## Dynamic Array

<p align="center"> 
<img src= "Memory_Diagram/dynamic_array.jpeg" width = "450">
</p>

## Memory Management:

The destructor will use delete[] to free the dynamically allocated array.

The copy constructor and assignment operator will perform deep copying.
A deep copy creates a new array and copies all elements into it.

A shallow copy only copies the pointer address, causing two objects to share
the same memory. This can lead to data changes affecting both objects and
double deletion errors.

The Rule of Three is implemented:
- Destructor
- Copy Constructor
- Copy Assignment Operator

## Linked List

<p align="center"> 
<img src= "Memory_Diagram/linked_list.jpeg" width = "450">
</p>

## Memory Management: 
The destructor will start from the head node and delete each node one by one until the end of the list is reached.

The copy constructor and copy assignment operator will perform deep copying. New nodes will be allocated for the copied list, ensuring that two LinkedList objects never share the same memory.

A shallow copy would only copy the head and tail pointers, causing multiple lists to point to the same nodes. This could lead to accidental data modification, dangling pointers, and double deletion errors when destructors are executed.

The Rule of Three will be implemented:

Destructor
Copy Constructor
Copy Assignment Operator

## Hash Map:

<p align="center"> 
<img src= "Memory_Diagram/hash_map.jpeg" width = "450">
</p>

## Memory Management:

The HashMap destructor will first go through every bucket and delete all HashNodes
inside each chain. After deleting all nodes, it will delete the bucket array.

The copy constructor and assignment operator will use deep copying. A new bucket
array and new HashNodes will be created, and all key-value pairs will be copied.

A shallow copy would only copy the bucket pointer, causing two HashMaps to share
the same nodes. This can cause data corruption and double deletion when objects
are destroyed.

The Rule of Three will be implemented:
- Destructor
- Copy Constructor
- Copy Assignment Operator

---

# Section 3 — Complexity Estimates

## DynamicArray

| Operation              | Best Case | Average Case   | Worst Case | Reason                                                                                                                 |
| ---------------------- | --------- | -------------- | ---------- | ---------------------------------------------------------------------------------------------------------------------- |
| `get(index)`           | O(1)      | O(1)           | O(1)       | Direct access using the index; no traversal required.                                                                  |
| `set(index, value)`    | O(1)      | O(1)           | O(1)       | Value is written directly to the memory location corresponding to the index.                                           |
| `append(value)`        | O(1)      | O(1) amortized | O(n)       | Adding at the end is constant time if space exists. Resizing requires allocating a new array and copying all elements. |
| `insert(index, value)` | O(1)      | O(n)           | O(n)       | Inserting at the end without resizing is constant time. Otherwise, elements must be shifted.                           |
| `remove(index)`        | O(1)      | O(n)           | O(n)       | Removing the last element requires no shifting. Removing elsewhere requires shifting elements.                         |
| `size()`               | O(1)      | O(1)           | O(1)       | Returns a stored size value.                                                                                           |
| `capacity()`           | O(1)      | O(1)           | O(1)       | Returns a stored capacity value.                                                                                       |
| `empty()`              | O(1)      | O(1)           | O(1)       | Checks whether the stored size is zero.                                                                                |
| `clear()`              | O(1)      | O(1)           | O(1)       | Resets the size counter without removing elements individually.                                                        |

---

## LinkedList

| Operation              | Best Case | Average Case | Worst Case | Reason                                                                                                       |
| ---------------------- | --------- | ------------ | ---------- | ------------------------------------------------------------------------------------------------------------ |
| `insertFront(value)`   | O(1)      | O(1)         | O(1)       | A new node is added at the beginning and the head pointer is updated.                                        |
| `insert(index, value)` | O(1)      | O(n)         | O(n)       | Inserting at the front is constant time. Otherwise, the list must be traversed to find the correct position. |
| `deleteFront()`        | O(1)      | O(1)         | O(1)       | The head pointer is moved to the next node and the old node is deleted.                                      |
| `remove(index)`        | O(1)      | O(n)         | O(n)       | Removing the first node is constant time. Removing elsewhere requires traversal.                             |
| `search(value)`        | O(1)      | O(n)         | O(n)       | The value may be found in the first node, but in the worst case every node must be checked.                  |
| `size()`               | O(1)      | O(1)         | O(1)       | Returns a stored size counter.                                                                               |
| `empty()`              | O(1)      | O(1)         | O(1)       | Checks whether the list size is zero or the head is `nullptr`.                                               |
| `clear()`              | O(n)      | O(n)         | O(n)       | Every node must be visited and deleted.                                                                      |
---

## HashMap

| Operation         | Best Case | Average Case | Worst Case | Reason                                                                                                                                                                                 |
| ----------------- | --------- | ------------ | ---------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| `set(key, value)` | O(1)      | O(1)         | O(n)       | A good hash function distributes keys evenly among buckets, allowing quick insertion. In the worst case, all keys collide into the same bucket and a full chain traversal is required. |
| `get(key)`        | O(1)      | O(1)         | O(n)       | The hash function directly identifies the bucket. If many collisions occur, the entire chain may need to be searched.                                                                  |
| `exists(key)`     | O(1)      | O(1)         | O(n)       | Searches the bucket chain for the key. Performance depends on the number of collisions.                                                                                                |
| `remove(key)`     | O(1)      | O(1)         | O(n)       | Removing a key is fast when it is near the beginning of a bucket chain. In the worst case, the entire chain must be searched.                                                          |
| `size()`          | O(1)      | O(1)         | O(1)       | Returns a stored count of key-value pairs.                                                                                                                                             |
| `loadFactor()`    | O(1)      | O(1)         | O(1)       | Calculated using stored size and bucket count variables.                                                                                                                               |
| `clear()`         | O(n)      | O(n)         | O(n)       | Every node in every bucket must be deleted.                                                                                                                                            |
| `rehash()`        | O(n)      | O(n)         | O(n)       | All existing key-value pairs must be moved into a new bucket array and reinserted using the new hash table size.                                                                       |

---

## Redis Lite

| Operation         | Best Case | Average Case | Worst Case | Reason                                                                                                                                                                                                                             |
| ----------------- | --------- | ------------ | ---------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| `set(key, value)` | O(1)      | O(1)         | O(n)       | The key is converted into a hash value to find the correct bucket. Normally the bucket contains a short chain, making insertion constant time. If many keys collide into the same bucket, the linked list may need to be searched. |
| `get(key)`        | O(1)      | O(1)         | O(n)       | The hash function directly finds the bucket containing the key. If collisions occur, the linked list inside that bucket must be searched.                                                                                          |
| `exists(key)`     | O(1)      | O(1)         | O(n)       | It checks the bucket containing the key. The operation is fast when the key is found immediately but slower when many collisions exist.                                                                                            |
| `remove(key)`     | O(1)      | O(1)         | O(n)       | The key location is found using hashing. If the key is inside a long collision chain, the chain must be traversed before deletion.                                                                                                 |
| `size()`          | O(1)      | O(1)         | O(1)       | The number of stored elements is maintained as a variable and returned directly.                                                                                                                                                   |
| `clear()`         | O(n)      | O(n)         | O(n)       | Every key-value pair stored in the HashMap must be deleted.                                                                                                                                                                        |

---

# Section 4 — Design Decisions

## DynamicArray

### Choose: Dynamic Array

I chose a **dynamic array** because it can grow when more elements are added and allows fast access to elements using an index. It is more flexible because the size does not need to be decided in advance. When the array becomes full, its size is **doubled** because it reduces the number of resizing operations and copying of elements, making the process faster. Although it may use some extra memory, the better performance makes it a good choice.

Initial Capacity: 5

Growth Strategy:
capacity = capacity * 2

Shrink Strategy:
No shrinking will be performed when elements are removed.

Error Handling:
Out-of-bounds access will throw std::out_of_range.

### Alternative: Fixed-Size Array

I considered a **fixed-size array**, but rejected it because the size must be decided before starting. It cannot increase when more elements are needed, which makes it less flexible.

---

## LinkedList

### Chosen Design: Doubly Linked List

I chose a **doubly linked list** because it supports traversal in both **forward and backward** directions. Each node stores pointers to both the next and previous nodes, which simplifies insertion and deletion operations because neighboring nodes can be accessed directly.

The implementation also maintains both head and tail pointers. This allows efficient insertion and deletion at both ends of the list and improves overall flexibility.




### Alternative: Singly Linked List

I considered using a **singly linked list** because it requires less memory per node and is simpler to implement. However, it only supports **forward traversal** and requires additional work when deleting nodes or moving backward through the list.


---

## HashMap

### Choose: Hash Map with Separate Chaining

I chose a **hash map with separate chaining** because it is simple to implement and handles collisions efficiently. When multiple keys have the same hash value, they are stored in a linked list inside the same bucket. This avoids long searching sequences and keeps operations like insertion, searching, and deletion efficient.

I chose an **initial bucket size of 4** and a **load factor of 0.75**. When the load factor goes above 0.75, the hash map increases its size and rehashes the elements. This helps maintain good performance as more elements are added.

Initial Bucket Count: 4

Collision Strategy:
Separate Chaining

Load Factor Threshold:
0.75

Rehash Strategy:
Double the bucket count

Missing Key Behavior:
get() throws std::out_of_range.

## Hash Function Design

hash = hash * 53 + character

The final bucket index will be:

index = hash(key) % bucketCount

This approach distributes keys more uniformly than simply summing character values and reduces collisions.


### Alternative: Open Addressing

I considered using **open addressing**, where collisions are handled by finding another empty position in the table. However, I rejected it because it becomes more complex when the table gets crowded and requires extra searching due to probing. Separate chaining is easier to implement and works better for this project.


---

## Redis Lite

I chose a HashMap as the main storage structure because Redis works mainly with key-value pairs. HashMap provides fast insertion, searching, and deletion.

---

## Memory Management Decisions

All three data structures allocate memory dynamically, so I will implement the Rule of Three: destructor, copy constructor, and copy assignment operator.

I chose deep copying instead of shallow copying. Deep copying creates independent copies of the data, preventing shared ownership problems, accidental modifications, and double deletion errors. Although deep copying requires additional memory and copying time, it is safer and more appropriate for these data structures.
