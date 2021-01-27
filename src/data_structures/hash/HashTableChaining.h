#pragma once

#include "HashTable.h"
#include "../linked_list/LinkedList.h"

class HashTableChaining : public HashTable<int> {
private:
    LinkedList<int>* mTable;

    int getHashIndex(int x) {
        return x % 30;
    }

public:

    HashTableChaining() {
        mTable = new LinkedList<int>[30];
    }

    void add(int key) {
        mTable[getHashIndex(key)].add(key);
    }

    bool remove(int key) {
        return mTable[getHashIndex(key)].remove(key);
    }

    bool get(int key) {
        return mTable[getHashIndex(key)].indexOf(key) != -1;
    }

    bool isFull() {
        return true;
    }

    bool isEmpty() {
        return false;
    }
};