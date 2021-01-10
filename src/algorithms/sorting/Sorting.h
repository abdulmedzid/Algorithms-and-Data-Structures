#pragma once
#include "../../data_structures/array/Array.h"

template <class T, class F>
void BubbleSort(Array<T>& arr, F comp) {
    int numPasses = 0;
    bool sorted = false;
    while (!sorted) {
        sorted = true;
        for (int i = 0; i < arr.getSize() - 1 - numPasses; i++) {
            if (comp(arr[i], arr[i + 1])) {
                arr.swap(i, i + 1);
                sorted = false;
                std::cout << arr << std::endl;
            }
        }
    }
}

template <class T, class F>
void InsertionSort(Array<T>& arr, F comp) {
    for (int i = 1; i < arr.getSize(); i++) {
        int j = i;
        while (j > 0 && comp(arr[j], arr[j - 1])) {
            arr.swap(j, j - 1);
            j--;
            std::cout << arr << std::endl;
        }
    }
}

template <class T, class F>
void MergeSort(Array<T>& arr, F comp) {
    int size = arr.getSize();
    if ( size > 1) {
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
    Array<T> temp2 = arr(middle+1, end);

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

template <class T, class F>
void QuickSort(Array<T>& arr, F comp) {
    QuickSort(arr, comp, 0, arr.getSize() - 1);
}

template <class T, class F>
void QuickSort(Array<T>& arr, F comp, int start, int end) {
    if (start < end) {
        int partitionIndex = partition(arr, comp, start, end);
        QuickSort(arr, comp, start, partitionIndex - 1);
        QuickSort(arr, comp, partitionIndex + 1, end);
    }
}

template <class T, class F>
int partition(Array<T>& arr, F comp, int start, int end) {
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