#include "Linked_List.h"

// constructor
template<typename T>
LinkedList<T>::LinkedList()
{
    head_ = nullptr;
    tail_ = nullptr;
    size_ = 0;
}

// destructor
template<typename T>
LinkedList<T>::~LinkedList()
{
    Node* current = head_;

    while (current != nullptr)
    {
        Node* next = current->next;
        delete current;
        current = next;
    }

    head_ = nullptr;
    tail_ = nullptr;
    size_ = 0;
}

// copy constructor
template<typename T>
LinkedList<T>::LinkedList(const LinkedList& other)
{
    head_ = nullptr;
    tail_ = nullptr;
    size_ = 0;

    Node* current = other.head_;

    while (current != nullptr)
    {
        insertBack(current->data);
        current = current->next;
    }
}

// assignment operator
template<typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList& other)
{
    if (this == &other)
        return *this;

    clear();

    Node* current = other.head_;

    while (current != nullptr)
    {
        insertBack(current->data);
        current = current->next;
    }

    return *this;
}


//insert front
template<typename T>
void LinkedList<T>::insertFront(T value)
{
    Node* newNode = new Node(value);

    if (head_ == nullptr)
    {
        head_ = newNode;
        tail_ = newNode;
    }
    else
    {
        newNode->next = head_;
        head_->prev = newNode;
        head_ = newNode;
    }

    size_++;
}

// insert back
template<typename T>
void LinkedList<T>::insertBack(T value)
{
    Node* newNode = new Node(value);

    if (tail_ == nullptr)
    {
        head_ = newNode;
        tail_ = newNode;
    }
    else
    {
        tail_->next = newNode;
        newNode->prev = tail_;
        tail_ = newNode;
    }

    size_++;
}

// insert at position
template<typename T>
void LinkedList<T>::insert(int index, T value)
{
    if (index < 0 || index > size_)
        throw std::out_of_range("Index out of range");

    if (index == 0)
    {
        insertFront(value);
        return;
    }

    if (index == size_)
    {
        insertBack(value);
        return;
    }

    Node* current;

    if (index < size_ / 2)
    {
        current = head_;

        for (int i = 0; i < index; i++)
            current = current->next;
    }
    else
    {
        current = tail_;

        for (int i = size_ - 1; i > index; i--)
            current = current->prev;
    }

    Node* newNode = new Node(value);

    newNode->prev = current->prev;
    newNode->next = current;

    current->prev->next = newNode;
    current->prev = newNode;

    size_++;
}

//get
template<typename T>
T LinkedList<T>::get(int index) const
{
    if (index < 0 || index >= size_)
        throw std::out_of_range("Index out of range");

    Node* current;

    // traverse from head
    if (index < size_ / 2)
    {
        current = head_;

        for (int i = 0; i < index; i++)
            current = current->next;
    }
    // traverse from tail
    else
    {
        current = tail_;

        for (int i = size_ - 1; i > index; i--)
            current = current->prev;
    }

    return current->data;
}

//clear
template<typename T>
void LinkedList<T>::clear()
{
    Node* current = head_;

    while (current != nullptr)
    {
        Node* next = current->next;
        delete current;
        current = next;
    }

    head_ = nullptr;
    tail_ = nullptr;
    size_ = 0;
}

//size
template<typename T>
int LinkedList<T>::size() const
{
    return size_;
}

//empty
template<typename T>
bool LinkedList<T>::empty() const
{
    return size_ == 0;
}