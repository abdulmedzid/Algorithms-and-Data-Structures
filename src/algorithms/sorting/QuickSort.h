#pragma once

#include "../../data_structures/array/Array.h"

template <class T, class F>
void QuickSort(Array<T>& arr, F comp) {
    QuickSort(arr, comp, 0, arr.getSize() - 1);
}

template <class T, class F>
void QuickSort(Array<T>& arr, F comp, int start, int end) {
    if (start < end) {
        int partitionIndex = Partition(arr, comp, start, end);
        QuickSort(arr, comp, start, partitionIndex - 1);
        QuickSort(arr, comp, partitionIndex + 1, end);
    }
}

template <class T, class F>
int Partition(Array<T>& arr, F comp, int start, int end) {
    T& pivot = arr[end];
    int min = start - 1; // ovo ti zapravo treba bit zadnji element prije pivota
    for (int j = start; j < end; j++) {
        if (comp(arr[j], pivot)) {
            min++;
            arr.swap(j, min);
        }
    }
    min++;
    arr.swap(min, end);
    return min;
}