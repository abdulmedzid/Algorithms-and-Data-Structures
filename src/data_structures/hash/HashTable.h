#pragma once

template <class T>
class HashTable {
    virtual void add(const T& obj) = 0;
    virtual bool remove(const T& obj) = 0;
    virtual bool get(const T& obj) = 0;
    virtual bool isFull() = 0;
    virtual bool isEmpty() = 0;
};
