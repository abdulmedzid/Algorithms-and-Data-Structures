#pragma once
#include <iostream>
#include "../../data_structures/array/Array.h"

enum SortType {
    ASCENDING, // will use min tree
    DESCENDING // will use max tree
};

template <class T>
bool isNodeMissplaced(T& node, T& parent, SortType type) {
    return
        (type == DESCENDING && node < parent) ||
        (type == ASCENDING && node > parent);
}

template <class T>
void Heapify(Array<T>& arr, int root, int size = -1, SortType type = ASCENDING) {
    T& node = arr[root];

    int target = root;
    int left = root * 2 + 1;
    int right = root * 2 + 2;
    size = size == -1 ? arr.getSize() : size;

    if (left < size && isNodeMissplaced(arr[left], node, type)) {
        target = left;
    }

    if (right < size && isNodeMissplaced(arr[right], arr[target], type)) {
        target = right;
    }

    if (target != root) {
        arr.swap(target, root);
        Heapify(arr, target, type);
    }
}

template <class T>
void HeapSort(Array<T>& arr, SortType type = ASCENDING) {
    int size = arr.getSize();
    for (int i = size / 2 - 1; i >= 0; i--) {
        Heapify(arr, i);
    }
    for (int i = size - 1; i >= 0; i--) {
        arr.swap(i, 0);
        size--;
        Heapify(arr, 0, size, type); 
    }
}