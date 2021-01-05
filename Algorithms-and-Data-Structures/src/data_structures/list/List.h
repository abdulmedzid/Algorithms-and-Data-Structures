#pragma once
#include <iostream>

template <class T>
class List {
protected:
    int                     mSize;

                            List() : mSize(0) {};
    virtual void            add(const T& obj) = 0;
    virtual void            addStart(const T& obj) = 0;
    virtual void            insert(const T& obj, int location) = 0; // insert at location, everything else shifsts to right
    virtual void            setAt(const T& obj, int location) = 0; // sets data of node at location
    virtual void            remove(const T& obj) = 0; // seek and destroy
    virtual void            removeAt(int location) = 0; 
    virtual int             indexOf(const T& obj) const = 0; // just seek
    virtual T&              getAt(int location) const = 0;
    virtual std::string     toString() const = 0;

public:
    T& operator[](int location) const {
        return getAt(location);
    }
    
    int getSize() const {
        return mSize;
    }
    
    bool isEmpty() const {
        return mSize == 0;
    }

    bool isIndexInBounds(int index) const {
        return index >= 0 && index <= this->mSize;
    }
};