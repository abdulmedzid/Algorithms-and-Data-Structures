#pragma once
#include "../tree_binary_heap/BinaryHeap.h"

template <class T>
class PriorityQueue : protected BinaryHeap<T> {
public:
                            PriorityQueue() : BinaryHeap(MAX) {}

    void                    enqueue(const T& obj) {
                                insert(obj);
                            }

    T                       dequeue() {
                                return extractRoot();
                            }

    T&                      peek() {
                                return peekRoot();
                            }
};