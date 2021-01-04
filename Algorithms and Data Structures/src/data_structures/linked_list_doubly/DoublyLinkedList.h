#pragma once
#include "../node/Node.h"
#include "../list/List.h"

template <class T>
class DoublyLinkedList : public List<T> {
private:
    Node<T>*        mFirst;
    Node<T>*        mLast;
public:
                    DoublyLinkedList() : List<T> {}
                    
                    DoublyLinkedList(const DoublyLinkedList& obj) : List<T> {
                    
                    }

                    ~DoublyLinkedList() {

                    }
};