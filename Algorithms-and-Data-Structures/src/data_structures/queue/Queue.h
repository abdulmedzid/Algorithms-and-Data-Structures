#pragma once
#include "../array/Array.h"

template <class T>
class Queue : protected Array<T> {
public:
    void enqueue(const T& obj) {
        this->addStart(obj);
    }

    T dequeue() {
        if (getSize() == 0) throw std::exception("empty queue");
        this->mSize--;
        return this->getAt(this->mSize);
    }

    T& peek() {
        if (getSize() == 0) throw std::exception("empty queue");
        return this->getAt(this->mSize - 1);
    }

    int getSize() {
        return this->mSize;
    }

    bool isEmpty() {
        return getSize() == 0;
    }
};