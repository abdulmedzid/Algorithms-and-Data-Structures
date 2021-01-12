#pragma once

#include "../../data_structures/array/Array.h"

template <class T, class F>
void MergeSort(Array<T>& arr, F comp) {
    int size = arr.getSize();
    if (size > 1) {
        MergeSort(arr, comp, 0, size - 1);
    }
}

template <class T, class F>
void MergeSort(Array<T>& arr, F comp, int start, int end) {
    if (end > start) {
        int middle = (start + end) / 2;
        MergeSort(arr, comp, start, middle);
        MergeSort(arr, comp, middle + 1, end);
        Merge(arr, comp, start, middle, end);
    }
}


template <class T, class F>
void Merge(Array<T>& arr, F comp, int start, int middle, int end) {
    Array<T> temp1 = arr(start, middle);
    Array<T> temp2 = arr(middle + 1, end);

    int size1 = temp1.getSize();
    int size2 = temp2.getSize();

    /*
            i -> temp1 index
            j -> temp2 index
            k -> sorted array index
    */
    int i, j, k;
    i = j = 0;
    k = start;

    while (i < size1 && j < size2) {
        if (comp(temp1[i], temp2[j])) {
            arr[k] = temp1[i];
            i++;
            k++;
        }
        else {
            arr[k] = temp2[j];
            j++;
            k++;
        }
    }

    while (i < size1) {
        arr[k] = temp1[i];
        i++;
        k++;
    }

    while (j < size2) {
        arr[k] = temp2[j];
        j++;
        k++;
    }
}

