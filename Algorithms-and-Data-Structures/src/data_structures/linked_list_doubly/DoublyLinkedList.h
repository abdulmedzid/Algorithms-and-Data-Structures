#pragma once
#include <exception>
#include "../node/Node.h"
#include "../list/List.h"

template <class T>
class DoublyLinkedList : public List<T> {
private:
    Node<T>*            mFirst;
    Node<T>*            mLast;

    bool                isLocationInBounds(int location) const {
                            return location >= 0 && location < this->mSize;
                        }

    Node<T>*            getNodeAt(int location) const {
                            if (!isLocationInBounds(location)) {
                                throw std::exception("index out of bounds");
                            }
                            if (location <= this->mSize / 2) {
                                return getNodeFromFirst(location);
                            }
                            else {
                                return getNodeFromLast(location);
                            }
                        }

    Node<T>*            getNodeFromFirst(int location) const {
                            Node<T>* node = mFirst;
                            for (int i = 0; i < location; i++) {
                                node = node->getNext();
                            }
                            return node;
                        }

    Node<T>*            getNodeFromLast(int location) const {
                            Node<T>* node = mLast;
                            for (int i = this->mSize-1; i > location; i--) {
                                node = node->getPrev();
                            }
                            return node;
                        }

    Node<T>*            getNodeOf(const T& obj) const {
                            Node<T>* node = mFirst;
                            while (node != nullptr) {
                                if (node->getData() == obj) {
                                    return node;
                                }
                                node = node->getNext();
                            }
                            return nullptr;
                        }

    void                removeNode(Node<T>* node) {
                            Node<T>* prev = node->getPrev();
                            Node<T>* next = node->getNext();
                            prev->setNext(next);
                            next->setPrev(prev);
                            delete node;
                        }
public:
                        DoublyLinkedList() : List<T>() {}
                        
                        DoublyLinkedList(const DoublyLinkedList& obj) : List<T>() {
                            Node<T>* next = obj.mFirst;
                            while (next != nullptr) {
                                addNode(new Node(*next));
                                next = next->getNext();
                            }
                        }

                        ~DoublyLinkedList() {
                            clear();
                        }

    DoublyLinkedList&   operator=(const DoublyLinkedList& obj) {
                            return *this;
                        }
    
    T&                  getAt(int location) {
                            getNodeAt(location)->getData();
                        }
    
    void                setAt(const T& obj, int location) {
                            getNodeAt(location)->setData(obj);
                        }

    void                add(const T& obj) { // adds to end
                            Node<T>* newLast = new Node<T>(obj);
                            if (mLast == nullptr) {
                                mFirst = mLast = newLast;
                            }
                            else {
                                newLast->setPrev(mLast);
                                mLast->setNext(newLast);
                                mLast = newLast;
                            }
                        }

    void                addFirst(const T& obj) {
                            Node<T>* newFirst = new Node<T>(obj);        
                            if (mFirst == nullptr) {
                                mFirst = mLast = newFirst;
                            }
                            else {
                                newFirst->setNext(mFirst);
                                mFirst->setPrev(newFirst);
                                mFirst = newFirst;
                            }
                        }

    void                addLast(const T& obj) {
                            add(obj);
                        }

    void                insert(const T& obj, int location) {
                            Node<T>* oldNode = getNodeAt(location);
                            Node<T>* newNode = new Node<T>(obj, oldNode->getPrev(), oldNode);
                            oldNode->setPrev(newNode);
                        }

    void                remove(const T& obj) {
                            removeNode(getNodeOf(obj));
                        }

    void                removeAt(int location) {
                            removeNode(getNodeAt(location));
                        }

     int                indexOf(const T& obj) const {
                            int i = 0;
                            Node<T>* next = mFirst;
                            while (next != nullptr) {
                                if (next->getData() == obj) {
                                    return i;
                                }
                                i++;
                                next = next->getNext();
                            }
                            return -1;
                        }

    void	            clear() {
                            Node<T>* curr = mFirst;
                            while (curr != nullptr) {
                                Node<T>* prev = curr;
                                curr = curr->getNext();
                                delete prev;
                            }
                            mFirst = nullptr;
                            this->mSize = 0;
                        }
};