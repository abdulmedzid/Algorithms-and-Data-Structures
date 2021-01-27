#pragma once

#include "HashTable.h"

template <class T>
class HashElement {
private:
    T* mData;
    bool mIsAssigned;
public:
    HashElement() : mData(nullptr), mIsAssigned(false) {}
    
    HashElement(const T& obj) : mIsAssigned(false) {
        mData = new T(obj);
    }
    
    HashElement(const HashElement& obj) {
        mData = new T(obj);
        mIsAssigned = obj.mIsAssigned;
    }

    ~HashElement() {
        delete mData;
    }

    HashElement& operator=(const HashElement& obj) {
        if (this != &obj) {
            if (mData == nullptr) {
                mData = new T(obj);
            }
            else {
                *mData = *obj.mData;
            }
        }
        return *this;
    }

    HashElement& operator=(const T& data) {
        if (mData == nullptr) {
            mData = new T(data);
        }
        else {
           *mData = data;
        }
        setAssigned();
        return *this;
    }

    bool setAssigned(bool isAssigned = true) {
        mIsAssigned = isAssigned;
    }

    bool isAssigned() {
        return mIsAssigned;
    }

    void setData(const T& obj) {
        if (mData == nullptr) {
            mData = new T(obj);
        }
        else {
            *mData = obj;
        }
    }

    T& getData() {
        return *mData;
    }
};


class HashTableOpenAdressing : public HashTable<int> {
private:
    int mSize;
    int mMaxSize;
    typedef HashElement<int> Element;
    Element* mArray;

    int getHashIndex(int x) {
        return x % mMaxSize;
    }

    bool isTaken(int index) {
        return mArray[index].isAssigned();
    }
public:
    HashTableOpenAdressing(int maxSize = 10) : mSize(0), mMaxSize(maxSize) {
        mArray = new Element[mSize];
    }

    ~HashTableOpenAdressing() {
        delete[] mArray;
    }

    void add(int obj) {
        if (isFull())
            return;

        int i = getHashIndex(obj);

        while (isTaken(i)) {
            i++;
            if (i == mMaxSize)
                i = 0;
        }
        mArray[i] = obj;
    }

    bool remove(int key) {
        int i = getHashIndex(key);
        int numVisited = 0;
        while (numVisited < mMaxSize) {
            if (mArray[i].isAssigned() && mArray[i].getData() == key) {
                mSize--;
                mArray[i].setAssigned(false);
                return true;
            }
            i++;
            if (i == mMaxSize)
                i = 0;
            numVisited++;
        }
        return false;
    }

    bool get(int key) {
        int i = getHashIndex(key);
        int numVisited = 0;
        while (numVisited < mMaxSize) {
            if (mArray[i].isAssigned() && mArray[i].getData() == key) {
                return true;
            }
            i++;
            if (i == mMaxSize)
                i = 0;
            numVisited++;
        }
        return false;
    }

    bool isFull() {
        return mSize == mMaxSize;
    }

    bool isEmpty() {
        return mSize == 0;
    }
};