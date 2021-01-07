#pragma once
#include <exception>
#include <sstream>
#include <string>
#include "../node/Node.h"
#include "../list/List.h"

template <class T>
class DoublyLinkedList : public List<T> {
private:
    Node<T>*            mFirst;
    Node<T>*            mLast;

    Node<T>*            getNodeAt(int location) const {
                            if (!this->isIndexInBounds(location)) {
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
                                node = node->getRight();
                            }
                            return node;
                        }

    Node<T>*            getNodeFromLast(int location) const {
                            Node<T>* node = mLast;
                            for (int i = this->mSize-1; i > location; i--) {
                                node = node->getLeft();
                            }
                            return node;
                        }

    Node<T>*            getNodeOf(const T& obj) const {
                            Node<T>* node = mFirst;
                            while (node != nullptr) {
                                if (node->getData() == obj) {
                                    return node;
                                }
                                node = node->getRight();
                            }
                            return nullptr;
                        }

    void                addNodeStart(Node<T>* node) {
                            if (mFirst == nullptr) {
                                mFirst = mLast = node;
                            }
                            else {
                               node->setRight(mFirst);
                               mFirst->setLeft(node);
                               mFirst = node;
                            }
                            this->mSize++;
                        }

    void                addNodeEnd(Node<T>* node) {
                            if (mFirst == nullptr) {
                                mFirst = mLast = node;
                            }
                            else {
                                node->setLeft(mLast);
                                mLast->setRight(node);
                                mLast = node;
                            }
                            this->mSize++;
                        }

    void                removeNode(Node<T>* node) {
                            Node<T>* prev = node->getLeft();
                            Node<T>* next = node->getRight();
                            prev->setRight(next);
                            next->setLeft(prev);
                            delete node;
                            this->mSize--;
                        }

    void                copyNodes(const DoublyLinkedList& obj) {
                            Node<T>* node = obj.mFirst;
                            while (node != nullptr) {
                                addNodeEnd(new Node<T>(node->getData()));
                                node = node->getRight();
                            }
                        }

public:
                        DoublyLinkedList() : List<T>(), mFirst(nullptr), mLast(nullptr) {}
                        
                        DoublyLinkedList(const DoublyLinkedList& obj) : List<T>() {
                            copyNodes(obj);
                        }

                        ~DoublyLinkedList() {
                            clear();
                        }

    DoublyLinkedList&   operator=(const DoublyLinkedList& obj) {
                            clear();
                            copyNodes(obj);
                            return *this;
                        }

    void                add(const T& obj) { // adds to end
                            addNodeEnd(new Node<T>(obj));
                        }

    void                addStart(const T& obj) {
                            addNodeStart(new Node<T>(obj));
                        }

    void                insert(const T& obj, int location) {
                            if (location == 0) {
                                addStart(obj);
                            }
                            else {
                                Node<T>* oldNode = getNodeAt(location);
                                Node<T>* newNode = new Node<T>(obj, oldNode->getLeft(), oldNode);
                                oldNode->getLeft()->setRight(newNode);
                                oldNode->setLeft(newNode);
                                this->mSize++;
                            }
                        }

    T&                  getAt(int location) const {
                            return getNodeAt(location)->getData();
                        }

    void                setAt(const T& obj, int location) {
                            getNodeAt(location)->setData(obj);
                        }

    void                remove(const T& obj) {
                            removeNode(getNodeOf(obj));
                        }

    void                removeAt(int location) {
                            removeNode(getNodeAt(location));
                        }

    int                 indexOf(const T& obj) const {
                            int i = 0;
                            Node<T>* node = mFirst;
                            while (node != nullptr) {
                                if (node->getData() == obj) {
                                    return i;
                                }
                                i++;
                                node = node->getRight();
                            }
                            return -1;
                        }

    void                clear() {
                            Node<T>* node = mFirst;
                            while (node != nullptr) {
                                Node<T>* rmNode = node;
                                node = node->getRight();
                                delete rmNode;
                            }
                            mFirst = nullptr;
                            this->mSize = 0;
                        }

    std::string         toString() const {
                            std::stringstream ss;
                            Node<T>* next = mFirst;
                            while (next != nullptr) {
                                ss << next->getData() << " ";
                                next = next->getRight();
                            }
                            return ss.str();
                        }

    friend std::ostream& operator<<(std::ostream& out, const DoublyLinkedList& obj) {
        out << obj.toString();
        return out;
    }
};