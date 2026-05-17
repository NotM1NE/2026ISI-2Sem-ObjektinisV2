#ifndef VECTOR_H
#define VECTOR_H

#include <utility>
#include <stdexcept>
#include <initializer_list>

template <typename T>

class MyVector
{
private:
    T *_data;
    int _size;
    int _capacity;
    void Grow()
    {
        int newCapacity;
        if (_capacity == 0)
            newCapacity = 1;
        else
            newCapacity = _capacity * 2;

        Reserve(newCapacity);
    }

public:
    MyVector() : _size(0), _capacity(1), _data(new T[_capacity]) {}

    MyVector(std::initializer_list<T> values);

    MyVector(const MyVector &other);
    MyVector &operator=(const MyVector &other);

    MyVector(MyVector &&other) noexcept;
    MyVector &operator=(MyVector &&other) noexcept;

    ~MyVector()
    {
        delete[] _data;
    }

    inline int size() const { return _size; }
    inline int capacity() const { return _capacity; }
    inline bool empty() const
    {
        if (_size == 0)
            return true;
        else
            return false;
    }

    void PopBack()
    {
        if (_size == 0)
            throw std::out_of_range("PopBack on empty vector");

        _size--;
    }
    void Clear() { _size = 0; }
    void PushBack(T value)
    {
        if (_size == _capacity)
            Grow();
        _data[_size] = std::move(value);
        _size++;
    }
    void Reserve(int newAlloc)
    {
        if (newAlloc <= _capacity)
            return;

        T *newData = new T[newAlloc];
        for (int i = 0; i < _size; i++)
        {
            newData[i] = std::move(_data[i]);
        }
        delete[] _data;
        _data = newData;
        _capacity = newAlloc;
    }
    void Resize(int newSize)
    {
        if (newSize < 0)
            throw std::out_of_range("Size cannot be negative");

        if (newSize > _capacity)
            Reserve(newSize);

        _size = newSize;
    }
    void Resize(int newSize, const T &value)
    {
        if (newSize < 0)
            throw std::out_of_range("Size cannot be negative");

        if (newSize > _capacity)
            Reserve(newSize);

        for (int i = _size; i < newSize; i++)
        {
            _data[i] = value;
        }

        _size = newSize;
    }
    void ShrinkToFit()
    {
        if (_capacity == _size)
            return;

        T *newData = new T[_size];
        for (int i = 0; i < _size; i++)
        {
            newData[i] = std::move(_data[i]);
        }

        delete[] _data;
        _data = newData;
        _capacity = _size;
    }
    void Erase(int index)
    {
        if (index >= _size || index < 0)
            throw std::out_of_range("Index is out of range");

        for (int i = index; i < _size - 1; i++)
        {
            _data[i] = std::move(_data[i + 1]);
        }

        _size--;
    }
    void Insert(int index, T value)
    {
        if (index > _size || index < 0)
            throw std::out_of_range("Index is out of range");

        if (_size == _capacity)
            Grow();

        for (int i = _size; i > index; i--)
        {
            _data[i] = std::move(_data[i - 1]);
        }

        _data[index] = std::move(value);
        _size++;
    }
    template <typename... Args>
    void EmplaceBack(Args &&...args)
    {
        if (_size == _capacity)
            Grow();

        _data[_size] = T(std::forward<Args>(args)...);
        _size++;
    }

    T &operator[](int index)
    {
        if (index < 0 || index >= _size)
            throw std::out_of_range("Index out of range");
        return _data[index];
    }
    const T &operator[](int index) const
    {
        if (index < 0 || index >= _size)
            throw std::out_of_range("Index out of range");
        return _data[index];
    }
    T &Front()
    {
        if (_size == 0)
            throw std::out_of_range("Vector is empty");

        return _data[0];
    }
    const T &Front() const
    {
        if (_size == 0)
            throw std::out_of_range("Vector is empty");

        return _data[0];
    }
    T &Back()
    {
        if (_size == 0)
            throw std::out_of_range("Vector is empty");

        return _data[_size - 1];
    }
    const T &Back() const
    {
        if (_size == 0)
            throw std::out_of_range("Vector is empty");

        return _data[_size - 1];
    }
    T *Data() { return _data; }
    const T *Data() const { return _data; }
    T *begin() { return _data; }
    const T *begin() const { return _data; }
    T *end() { return _data + _size; }
    const T *end() const { return _data + _size; }
};

// copy constructor
template <typename T>
MyVector<T>::MyVector(const MyVector<T> &other)
{
    _size = other._size;
    _capacity = other._capacity;
    _data = new T[_capacity];

    for (int i = 0; i < _size; i++)
    {
        _data[i] = other._data[i];
    }
}

// move constructor
template <typename T>
MyVector<T>::MyVector(MyVector<T> &&other) noexcept
{
    _data = other._data;
    _capacity = other._capacity;
    _size = other._size;

    other._data = nullptr;
    other._capacity = 0;
    other._size = 0;
}

// copy assignment
template <typename T>
MyVector<T> &MyVector<T>::operator=(const MyVector<T> &other)
{
    if (this == &other)
        return *this;

    T *newData = new T[other._capacity];

    for (int i = 0; i < other._size; i++)
    {
        newData[i] = other._data[i];
    }

    delete[] _data;

    _data = newData;
    _size = other._size;
    _capacity = other._capacity;

    return *this;
}

// move assignment
template <typename T>
MyVector<T> &MyVector<T>::operator=(MyVector<T> &&other) noexcept
{
    if (this == &other)
        return *this;

    delete[] _data;

    _data = other._data;
    _size = other._size;
    _capacity = other._capacity;

    other._data = nullptr;
    other._size = 0;
    other._capacity = 0;

    return *this;
}

template <typename T>
MyVector<T>::MyVector(std::initializer_list<T> values)
{
    _size = static_cast<int>(values.size());
    _capacity = static_cast<int>(values.size());
    _data = new T[_capacity];

    int i = 0;
    for (const T &value : values)
    {
        _data[i] = value;
        i++;
    }
}

template <typename T>
bool operator==(const MyVector<T> &a, const MyVector<T> &b)
{
    if (a.size() != b.size())
        return false;

    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] != b[i])
            return false;
    }

    return true;
}

template <typename T>
bool operator!=(const MyVector<T> &a, const MyVector<T> &b)
{
    return !(a == b);
}

template <typename T>
bool operator<(const MyVector<T> &a, const MyVector<T> &b)
{
    int minSize;

    if(a.size() < b.size())
        minSize = a.size();
    else
        minSize = b.size();

    for(int i = 0; i < minSize; i++)
    {
        if(a[i] < b[i])
            return true;

        if(a[i] > b[i])
            return false;
    }

    return a.size() < b.size();
}

template <typename T>
bool operator>(const MyVector<T> &a, const MyVector<T> &b)
{
    return b < a;
}

template <typename T>
bool operator<=(const MyVector<T> &a, const MyVector<T> &b)
{
    return !(b < a);
}

template <typename T>
bool operator>=(const MyVector<T> &a, const MyVector<T> &b)
{
    return !(b > a);
}


#endif