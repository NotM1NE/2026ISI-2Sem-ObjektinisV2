#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

template <typename T>

class Vector
{
private:
    T *_data;
    int _size;
    int _capacity;
    void resize()
    {
        _capacity *= 2;
        T *newData = new T[_capacity];
        for (int i = 0; i < _size; i++)
        {
            newData[i] = _data[i];
        }
        delete[] _data;
        _data = newData;
    }

public:
    Vector() : _size(0), _capacity(1), _data(new T[_capacity]) {}
    ~Vector()
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
        if (_size > 0)
            _size--;
    }
    void clear() { _size = 0; }
    void PushBack(T value)
    {
        if (_size == _capacity)
            resize();
        _data[_size] = value;
        _size++;
    }

    T &operator[](int index) { return _data[index]; }
    const T &operator[](int index) const { return _data[index]; }
};
#endif