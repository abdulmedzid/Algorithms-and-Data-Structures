#pragma once
#include <exception>
#include <sstream>
#include <string>
#include "../node/Node.h"
#include "../list/List.h"

template <class T>
class LinkedList : public List<T> {
private:
    typedef Node<T> Node;
    Node*            mFirst;
    
    Node*            getNodeAt(int location) const {
                            if (!this->isIndexInBounds(location)) {
                                throw std::exception("index out of bounds");
                            }
                            Node* node = mFirst;
                            for (int i = 0; i < location; i++) {
                                node = node->getRight();
                            }
                            return node;
                        }
    
    Node*            getLastNode() const {
                            if (mFirst == nullptr) {
                                throw std::exception("empty linked list");
                            }
                            Node* curr = mFirst;
                            while (curr->getRight() != nullptr)
                                curr = curr->getRight();
                            return curr;
    		            }
    
    void                addNodeStart(Node* node) {
                            node->setRight(mFirst);
                            mFirst = node;
                            this->mSize++;
                        }

    void                addNodeEnd(Node* node) {
                            if (mFirst == nullptr) {
                                mFirst = node;
                            }
                            else {
                                Node* last = getLastNode();
                                last->setRight(node);
                            }
                            this->mSize++;
                        }

    void                copyNodes(const LinkedList& obj) {
                            Node* node = obj.mFirst;
                            while (node != nullptr) {
                                addNodeEnd(new Node(node->getData()));
                                node = node->getRight();
                            }
                        }

public:
                        LinkedList() : List<T>(), mFirst(nullptr) {}
                        
                        LinkedList(const LinkedList& obj) : List<T>() {
                            copyNodes(obj);
                        }
                        
                        ~LinkedList() {
                            clear();
                        }
    
    LinkedList&         operator=(const LinkedList& obj) {
                            clear(); 
                            copyNodes(obj);
                            return *this;
                        }
    
    void                add(const T& obj) { // adds to end
                            addNodeEnd(new Node(obj));
                        }

    void                addStart(const T& obj) {
                            addNodeStart(new Node(obj));
                        }
    
    void                insert(const T& obj, int location) {
                            Node* node = new Node(obj);
                            if (location == 0) {
                                if (mFirst == nullptr) {
                                    mFirst = node;
                                    this->mSize++;
                                }
                                else {
                                    addNodeStart(node);
                                }
                            }
                            else {
                                Node* prev = getNodeAt(location - 1);
                                node->setRight(prev->getRight());
                                prev->setRight(node);
                                this->mSize++;
                            }
                        }
    
    void                setAt(const T& obj, int location) {
                            Node* node = getNodeAt(location);
                            node->setData(obj);
                        }
    
    T&                  getAt(int location) const {
                            return getNodeAt(location)->getData();
                        }
    
    void                remove(const T& obj) {
                            removeAt(indexOf(obj));
                        }
    
    void                removeAt(int location) {
                            if (location == 0) {
                                if (mFirst == nullptr) {
                                    throw std::exception("empty linked list");
                                }
                                else {
                                    Node* rmNode = mFirst;
                                    mFirst = mFirst->getRight();
                                    delete rmNode;
                                }
                            }
                            else {
                                Node* prevRmNode = getNodeAt(location - 1);
                                Node* rmNode = prevRmNode->getRight();
                                prevRmNode->setRight(rmNode->getRight());
                                delete rmNode;
                            }
                            this->mSize--;
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
    
    friend std::ostream& operator<<(std::ostream& out, const LinkedList& obj) {
        out << obj.toString();
        return out;
    }
};