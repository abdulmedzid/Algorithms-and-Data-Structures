#pragma once

#include <iostream>
#include "../../data_structures/array/Array.h"

void CountSort(Array<int>& arr, int exp) {
    int size = arr.getSize();
    int count[10] = { 0 };
    Array<int> temp(size);

    for (int i = 0; i < size; i++) {
        int digit = (arr[i] / exp) % 10;
        count[digit] += 1;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = size - 1; i >= 0; i--) {
        int num = arr[i];
        int digit = (num / exp) % 10;
        count[digit]--;
        temp.setAt(
            num,
            count[digit]
        );
    }

    for (int i = 0; i < size; i++) {
        arr[i] = temp[i];
    }
}

void RadixSort(Array<int>& arr) {
    int max = arr.getMax();
    int exp = 1;;
    while (max) {
        CountSort(arr, exp);
        exp *= 10;
        max /= 10;
    }
}

