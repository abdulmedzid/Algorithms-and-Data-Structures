#pragma once
#include "../array/Array.h"

template <class T>
class Stack : protected Array<T> {
public:
    void                push(const T& obj) {
                            this->add(obj);
                        }
    
    T                   pop() {
                            if (this->mSize == 0) {
                                throw std::exception("empty stack");
                            }
                            this->mSize--;
                            return this->mElements[this->mSize];
                        }

    T&                  peek() {
                            if (this->mSize == 0) {
                                throw std::exception("empty stack");
                            }
                            return this->mElements[this->mSize - 1];
                        }

    int                 getSize() {
                            return this->mSize;
                        }

    bool                isEmpty() {
                            return getSize() == 0;
                        }
};