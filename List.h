#pragma once
#include <iostream>
#include <stdexcept> 

template <typename T>
class List {
public:
    // Parameterized constructor
    List(int max = 200);
    // Destructor
    ~List();
    // Copy constructor
    List(const List& other);
    // Methods
    List<T>& operator=(const List& other);
    bool operator==(const List& other) const;
    T& operator[](int index);
    void append(T item);
    void resize(int new_size);
    void remove(T item);
    void insert(T item, int index);
    int size() const;
    bool is_empty() const;
    bool is_full() const;
    void clear();
    List<T>& display() const;
    T* get_list() const;

private:
    T* list;
    int length;
    int max_size;
};

// Parameterized constructor
template <typename T>
List<T>::List(int max) : max_size(max) {
    list = new T[max_size];
    length = 0;
}
// Destructor
template <typename T>
List<T>::~List() { delete[] list; }
// Methods
template <typename T>
void List<T>::append(T item)
{
    if (length == max_size)
        resize(max_size * 2);

    list[length++] = item;
}

template <typename T>
void List<T>::resize(int new_size) {
    if (new_size < length)
        return; // Cannot resize to a smaller size than the current length

    // Create a new array of the new size and copy the elements
    T* temp = new T[new_size];
    for (int i = 0; i < length; i++)
    {
        temp[i] = list[i];
    }
    // Delete the old array and assign the new array to the list
    delete[] list;
    list = temp;
    max_size = new_size;
}

// Copy constructor
template <typename T>
List<T>::List(const List& other) : max_size(other.max_size) {
    list = new T[max_size];
    length = other.length;
    for (int i = 0; i < length; i++)
    {
        list[i] = other.list[i];
    }
}

template <typename T>
List<T>& List<T>::operator=(const List& other) {
    if (this == &other)
        return *this;
    delete[] list;
    max_size = other.max_size;
    length = other.length;
    list = new T[max_size];
    for (int i = 0; i < length; i++)
    {
        list[i] = other.list[i];
    }
    return *this;
}

template <typename T>
void List<T>::remove(T item) {
    int index = -1;
    for (int i = 0; i < length; i++)
    {
        if (list[i] == item)
        {
            index = i;
            break;
        }
    }
    if (index == -1)
        return;

    for (int i = index; i < length - 1; i++)
    {
        list[i] = list[i + 1];    // Shift elements to the left
    }
    length--;
}

template <typename T>
void List<T>::insert(T item, int index)
{
    if (index < 0 || index > length)
        return;
    if (length == max_size)
        resize(max_size * 2);
    for (int i = length; i > index; i--)
    {
        // Shift elements to the right
        list[i] = list[i - 1];
    }
    // Insert the item at the index
    list[index] = item;
    length++;
}

template <typename T>
int List<T>::size() const { return length; }

template <typename T>
bool List<T>::is_empty() const { return length == 0; }

template <typename T>
bool List<T>::is_full() const { return length == max_size; }

template <typename T>
T& List<T>::operator[](int index) {
    if (index < 0 || index >= length)
        throw std::out_of_range("Index out of range");
    return list[index];
}

template <typename T>
void List<T>::clear() { length = 0; }

template <typename T>
List<T>& List<T>::display() const {
    return *this;
}

template <typename T>
T* List<T>::get_list() const {
    return list;
}

// operator == overloading
template <typename T>
bool List<T>::operator==(const List& other) const {
    // Check if current list is equal to the other list
    if (this == &other)
        return true;
    if (length == other.length)
    {
        for (int i = 0; i < length; i++)
        {
            if (list[i] != other.list[i])
                return false;
        }
        return true;
    }
    return false;
}