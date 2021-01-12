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
