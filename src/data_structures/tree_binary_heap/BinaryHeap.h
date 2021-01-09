#pragma once
#include <iostream>
#include <sstream>
#include <cmath>
#include "../array/Array.h"

/*
A Binary Heap is a Binary Tree with following properties:

1) It’s a complete tree 
    All levels are completely filled except possibly the 
    last level and the last level has all keys as left as 
    possible. This property of Binary Heap makes them suitable 
    to be stored in an array.

2) A Binary Heap is either Min Heap or Max Heap. 
    In a Min Binary Heap, the key at root must be minimum 
    among all keys present in Binary Heap. The same property 
    must be recursively true for all nodes in Binary Tree. 
    Max Binary Heap is similar to MinHeap.
    
    taken from geeksforgeeks.org
*/

enum BinaryHeapType {
    MIN,
    MAX
};

bool isPowOfTwo(int n) {
    return (n & (n - 1)) == 0;
}

template <class T>
class BinaryHeap {
private:
    BinaryHeapType              mType;
    Array<T>                    mNodes;

public:
                                BinaryHeap(BinaryHeapType type = MAX) : mNodes(65), mType(type) {}

                                BinaryHeap(const BinaryHeap& obj) : mType(obj.mType) {
                                    mNodes = obj.mNodes;
                                }

    T&                          getParent(int index) { 
                                    return mNodes.getAt(
                                        getParentIndex(index)
                                    );
                                }

    int                         getParentIndex(int index) {
                                    return (index - 1) / 2;
                                }

    T&                          getLeftChild(int index) {
                                    return mNodes.getAt(
                                        getLeftChildIndex()
                                    );
                                }

    int                         getLeftChildIndex(int index) {
                                    return index * 2 + 1;
                                }

    T&                          getRightChild(int index) {
                                    return mNodes.getAt(
                                        getRightChildIndex(index)
                                    );
                                }

    int                         getRightChildIndex(int index) {
                                    return index * 2 + 2;
                                }

    T&                          getAt(int index) {
                                    return mNodes.getAt(index);
                                }

    int                         getSize() {
                                    return mNodes.getSize();
                                }

    void                        insert(const T& obj) {
                                    mNodes.add(obj);
                                    int newNodeIndex = getSize() - 1;
                                    int parentIndex = getParentIndex(newNodeIndex);
                                    while (
                                        newNodeIndex != 0 &&
                                        (
                                            getAt(parentIndex) < getAt(newNodeIndex) && mType == MAX ||
                                            getAt(parentIndex) > getAt(newNodeIndex) && mType == MIN
                                        )
                                    ) 
                                    {
                                        mNodes.swap(parentIndex, newNodeIndex);
                                        newNodeIndex = parentIndex;
                                        parentIndex = getParentIndex(newNodeIndex);
                                    }
                                }

    T                           extractRoot() {
                                    T root = getAt(0);
                                    mNodes.setSize(getSize() - 1);
                                    mNodes.swap(0, getSize());
                                    heapify(0);
                                    return root;
                                }

    void                        heapify(int nodeIndex) {
                                    int root = nodeIndex;
                                    int left = getLeftChildIndex(root);
                                    int right = getRightChildIndex(root);
                                    
                                    if (
                                        left < getSize() &&
                                        (
                                            getAt(left) > getAt(root) && mType == MAX ||
                                            getAt(left) < getAt(root) && mType == MIN
                                        )
                                    ) {
                                        root = left;
                                    }

                                    if (
                                        right < getSize() && 
                                        (
                                            getAt(right) > getAt(root) && mType == MAX ||
                                            getAt(right) < getAt(root) && mType == MIN
                                        )
                                    ) {
                                        root = right;
                                    }

                                    if (nodeIndex != root) {
                                        mNodes.swap(nodeIndex, root);
                                        heapify(root);
                                    }
                                }

    T&                          peekRoot() {
                                    return getAt(0);
                                }

    int                         getHeight() {
                                    int size = mNodes.getSize();
                                    if (size == 0) return 0;
                                    return log2(size) + 1;
                                }

    std::string                 toString() {
                                    std::stringstream ss;
                                    int height = getHeight();
                                    int size = mNodes.getSize();
                                    for (int i = 0; i < size; i++) {
                                        if (isPowOfTwo(i + 1)) {
                                            ss << std::endl;
                                        }
                                        ss << std::string(height - log2(i + 1), ' ');
                                        ss << mNodes.getAt(i) << " ";
                                    }
                                    return ss.str();
                                }

    friend std::ostream& operator<<(std::ostream& out, BinaryHeap& obj) {
        out << obj.toString();
        return out;
    }
};