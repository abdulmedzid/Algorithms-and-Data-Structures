#pragma once
#include <iostream>

template<class T>
class Node {
private:
    T*              mData;
    Node*           mRight;
    Node*           mLeft;
public:
                    Node() : mData(nullptr), mRight(nullptr), mLeft(nullptr) {}
					
                    Node(const T& data) : mRight(nullptr), mLeft(nullptr) {
                        mData = new T(data);
                    }

                    Node(const T& data, Node<T>* left, Node<T>* right) : mRight(right), mLeft(left) {
                        mData = new T(data);
                    }
					
                    Node(const Node& nodeObj) {
                        mData = new T(*nodeObj.mData);
                        mRight = nodeObj.mRight;
                        mLeft = nodeObj.mLeft;
                    }

					~Node() {
					    delete mData;
					}

    Node&           operator=(const Node& nodeObj) {
                        setData(*nodeObj.mData);
                        this.mRight = nodeObj.mRight;
                        this.mLeft = nodeObj.mLeft;
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
    
    Node*&          getRight() { return mRight; }
    Node*&          getLeft() { return mLeft; }
    void            setRight(Node* next) { mRight = next; }
    void            setLeft(Node* prev) { mLeft = prev; }

    bool            operator>(const Node& obj) {
                        return *mData > *obj.mData;
                    }

    bool            operator<(const Node& obj) {
                        return *mData < *obj.mData;
                    }

    bool            operator>=(const Node& obj) {
                        return *mData >= *obj.mData;
                    }

    bool            operator<=(const Node& obj) {
                        return *mData <= *obj.mData;
                    }

    bool            operator==(const Node& obj) {
                        return *mData == *obj.mData;
                    }
    
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