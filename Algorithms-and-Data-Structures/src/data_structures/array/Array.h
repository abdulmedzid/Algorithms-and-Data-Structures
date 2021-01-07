#pragma once
#include <iostream>
#include <sstream>
#include "../list/List.h"

template <class T>
class Array : public List<T> {
protected:
    T*                  mElements;
    int                 mMaxSize;

    void                expand() {
                            if (mMaxSize == 0) {
                                mMaxSize = 10;
                            }
                            else {
                                mMaxSize *= 2;
                            }
                            T* oldElements = mElements;
                            mElements = new T[mMaxSize];
                            for (int i = 0; i < this->mSize; i++) {
                                mElements[i] = oldElements[i];
                            }
                        }

    void                expansionCheck() {
                            if (this->mSize == mMaxSize) {
                                expand();
                            }
                        }

    void                copyArray(const Array& obj) {
                            this->mSize = obj.mSize;
                            mMaxSize = obj.mMaxSize;
                            mElements = new T[mMaxSize];
                            for (int i = 0; i < this->mSize; i++) {
                                mElements[i] = obj.mElements[i];
                            }
                        }

    void                shift(int shift = 1, int from = 0) {
                            if (shift > 0) {
                                for (int i = this->mSize - 1; i >= from; i--) {
                                    if (isIndexInBoundsOfMaxSize(i + shift)) {
                                        mElements[i + shift] = mElements[i];
                                    }
                                }
                            }
                            else if (shift < 0) {
                                for (int i = from; i < this->mSize; i++) {
                                    if (isIndexInBoundsOfMaxSize(i + shift)) {
                                        mElements[i + shift] = mElements[i];
                                    }
                                }
                            }
                            this->mSize += shift;
                        }

    bool                isIndexInBoundsOfMaxSize(int index) const {
                            return index >= 0 && index <= mMaxSize;
                        }

public:
                        Array() : List<T>(), mMaxSize(0), mElements(nullptr) {}
    
                        Array(const Array& obj) : List<T>() {
                            copyArray(obj);
                        }

                        ~Array() {
                            clear();
                        }

    Array&              operator=(const Array& obj) {
                            clear();
                            copyArray(obj);
                            return *this;
                        }

    void                clear() {
                            delete[] mElements;
                            mMaxSize = 0;
                            this->mSize = 0;
                        }

    void                add(const T& obj) {
                            expansionCheck();
                            mElements[this->mSize] = obj;
                            this->mSize++;
                        }

    void                addStart(const T& obj) {
                            expansionCheck();
                            shift();
                            mElements[0] = obj;
                        }

    void                insert(const T& obj, int location) {
                            expansionCheck();
                            shift(1, location);
                            mElements[location] = obj;
                        }

    void                setAt(const T& obj, int location) {
                            mElements[location] = obj;
                        }

    void                remove(const T& obj) {
                            removeAt(indexOf(obj));
                        }

    void                removeAt(int location) {
                            if (location == -1) return;
                            shift(-1, location + 1);
                        }

    int                 indexOf(const T& obj) const {
                            for (int i = 0; i < this->mSize; i++) {
                                if (mElements[i] == obj) {
                                    return i;
                                }
                            }
                            return -1;
                        }

    T&                  getAt(int location) const {
                            return mElements[location];
                        }

    std::string         toString() const {
                            std::stringstream ss;
                            for (int i = 0; i < this->mSize; i++) {
                                ss << mElements[i] << " ";
                            }
                            return ss.str();
                        }

    friend std::ostream& operator<<(std::ostream& out, const Array& obj) {
        out << obj.toString();
        return out;
    }
};