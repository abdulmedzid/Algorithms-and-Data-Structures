#pragma once
#include <exception>
#include <sstream>
#include <string>
#include "../node/Node.h"
#include "../list/List.h"

template <class T>
class DoublyLinkedList : public List<T> {
private:
    typedef Node<T> Node;
    Node*            mFirst;
    Node*            mLast;

    Node*            getNodeAt(int location) const {
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

    Node*            getNodeFromFirst(int location) const {
                            Node* node = mFirst;
                            for (int i = 0; i < location; i++) {
                                node = node->getRight();
                            }
                            return node;
                        }

    Node*            getNodeFromLast(int location) const {
                            Node* node = mLast;
                            for (int i = this->mSize-1; i > location; i--) {
                                node = node->getLeft();
                            }
                            return node;
                        }

    Node*            getNodeOf(const T& obj) const {
                            Node* node = mFirst;
                            while (node != nullptr) {
                                if (node->getData() == obj) {
                                    return node;
                                }
                                node = node->getRight();
                            }
                            return nullptr;
                        }

    void                addNodeStart(Node* node) {
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

    void                addNodeEnd(Node* node) {
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

    bool                removeNode(Node* node) {
                            Node* prev = node->getLeft();
                            Node* next = node->getRight();
                            prev->setRight(next);
                            next->setLeft(prev);
                            delete node;
                            this->mSize--;
                            return true;
                        }

    void                copyNodes(const DoublyLinkedList& obj) {
                            Node* node = obj.mFirst;
                            while (node != nullptr) {
                                addNodeEnd(new Node(node->getData()));
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
                            if (this != &obj) {
                                clear();
                                copyNodes(obj);
                            }
                            return *this;
                        }

    void                add(const T& obj) { // adds to end
                            addNodeEnd(new Node(obj));
                        }

    void                addStart(const T& obj) {
                            addNodeStart(new Node(obj));
                        }

    void                insert(const T& obj, int location) {
                            if (location == 0) {
                                addStart(obj);
                            }
                            else {
                                Node* oldNode = getNodeAt(location);
                                Node* newNode = new Node(obj, oldNode->getLeft(), oldNode);
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

    bool                remove(const T& obj) {
                            return removeNode(getNodeOf(obj));
                        }

    bool                removeAt(int location) {
                            return removeNode(getNodeAt(location));
                        }

    int                 indexOf(const T& obj) const {
                            int i = 0;
                            Node* node = mFirst;
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
                            Node* node = mFirst;
                            while (node != nullptr) {
                                Node* rmNode = node;
                                node = node->getRight();
                                delete rmNode;
                            }
                            mFirst = nullptr;
                            this->mSize = 0;
                        }

    std::string         toString() const {
                            std::stringstream ss;
                            Node* next = mFirst;
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