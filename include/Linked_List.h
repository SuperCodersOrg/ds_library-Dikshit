#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <cstdlib>
#include <stdexcept>
#include <new>

template <typename T>
class LinkedList {
private:
    struct Node {
        T data;
        Node* prev;
        Node* next;

        Node(T value)
            : data(value), prev(nullptr), next(nullptr) {}
    };

    Node* head_;
    Node* tail_;
    int size_;

public:
    // constructor
    LinkedList();

    // rule of three
    ~LinkedList();
    LinkedList(const LinkedList& other);
    LinkedList& operator=(const LinkedList& other);

    // insertion
    void insertFront(T value);
    void insertBack(T value);
    void insert(int index, T value);

     // deletion
    void deleteFront();
    void deleteBack();
    void remove(int index);
    
    //get
    T get(int index) const;

    // capacity
    int size() const;
     bool empty() const;
     
    // utility
    void clear();
};

#include "../src/LinkedList.cpp" 

#endif