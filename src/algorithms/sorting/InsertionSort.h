#pragma once

#include "../../data_structures/array/Array.h"

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