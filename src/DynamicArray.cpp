#include "DynamicArray.h"

// default constructor
template<typename T>
DynamicArray<T>::DynamicArray()
{
    size_ = 0;
    capacity_ = 5;
    data_ = (T*)std::malloc(sizeof(T) * capacity_);
    if (!data_)
    throw std::bad_alloc();
}

// copy construcor
template<typename T>
DynamicArray<T>::DynamicArray(const DynamicArray& other)
{
    size_ = other.size_;
    capacity_ = other.capacity_;    

    data_ = (T*)std::malloc(sizeof(T) * capacity_);

    for (int i = 0; i < size_; i++)
        new (data_ + i) T(other.data_[i]);
}

// destructor
template<typename T>
DynamicArray<T>::~DynamicArray()
{
    if (data_)
    {
        for (int i = 0; i < size_; i++)
            data_[i].~T();

        std::free(data_);
    }

    data_ = nullptr;
}

// assignment operator
template<typename T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray& other)
{
    if (this == &other)
        return *this;

    // destroy current elements
    for (int i = 0; i < size_; i++)
        data_[i].~T();

    // free old memory
    std::free(data_);

    // copy metadata
    size_ = other.size_;
    capacity_ = other.capacity_;

    // allocate new memory
    data_ = (T*)std::malloc(sizeof(T) * capacity_);

    // copy-construct elements
    for (int i = 0; i < size_; i++)
        new (data_ + i) T(other.data_[i]);

    return *this;
}

// resize
template<typename T>
void DynamicArray<T>::resize()
{
    capacity_ *= 2;

    T* newData = (T*)std::malloc(sizeof(T) * capacity_);

    for (int i = 0; i < size_; i++)
    {
        // copy construct
        new (newData + i) T(data_[i]); 
        // destroy old
        data_[i].~T();
    }

    std::free(data_);
    data_ = newData;
}

// append
template<typename T>
void DynamicArray<T>::append(T value)
{
    if (size_ >= capacity_)
        resize();

    new (data_ + size_) T(value);
    size_++;
}

//insert
template<typename T>
void DynamicArray<T>::insert(int index, T value)
{
    if (index < 0 || index > size_)
        throw std::out_of_range("Index out of range");

    if (size_ >= capacity_)
        resize();

    for (int i = size_; i > index; i--)
    {
        new (data_ + i) T(data_[i - 1]);
        data_[i - 1].~T();
    }

    new (data_ + index) T(value);
    size_++;
}

// remove
template<typename T>
void DynamicArray<T>::remove(int index)
{
    if (index < 0 || index >= size_)
        throw std::out_of_range("Index out of range");

    data_[index].~T();

    for (int i = index; i < size_ - 1; i++)
    {
        new (data_ + i) T(data_[i + 1]);
        data_[i + 1].~T();
    }

    size_--;
}
