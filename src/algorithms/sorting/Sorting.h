#pragma once
#include <functional>
#include "Compare.h"
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