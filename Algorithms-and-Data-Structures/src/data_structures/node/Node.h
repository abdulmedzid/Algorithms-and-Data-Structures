#pragma once
#include <iostream>

template<class T>
class Node {
private:
    T*              mData;
    Node*           mNext;
    Node*           mPrev;
public:
                    Node() : mData(nullptr), mNext(nullptr), mPrev(nullptr) {}
					
                    Node(const T& data) : mNext(nullptr), mPrev(nullptr) {
                        mData = new T(data);
                    }

                    Node(const T& data, Node<T>* prev, Node<T>* next) : mPrev(prev), mNext(next) {
                        mData = new T(data);
                    }
					
                    Node(const Node& nodeObj) {
                        mData = new T(*nodeObj.mData);
                        mNext = nodeObj.mNext;
                        mPrev = nodeObj.mPrev;
                    }

					~Node() {
					    delete mData;
					}

    Node&           operator=(const Node& nodeObj) {
                        setData(*nodeObj.mData);
                        this.mNext = nodeObj.mNext;
                        this.mPrev = nodeObj.mPrev;
                        return *this;
                    }
    
    Node&           operator=(const T& dataObj) {
                        setData(dataObj);
                        return *this;
                    }
    				
    T&              getData() const { return *mData; }
    				
    void            setData(const T& dataObj) {
                        if (mData != nullptr) {
                            *mData = dataObj;
                        }
                        else {
                            mData = new T(dataObj);
                        }
                    }
    
    Node*           getNext() const { return mNext; }
    Node*           getPrev() const { return mPrev; }
    void            setNext(Node* next) { mNext = next; }
    void            setPrev(Node* prev) { mPrev = prev; }
    
    friend std::ostream& operator<<(std::ostream& out, const Node<T>& nodeObj) {
        if (nodeObj.mData != nullptr) {
            out << *nodeObj.mData;
    	}
        else {
            out << "NO DATA";
        }
        return out;
    }
};