#pragma once
#include <exception>
#include <sstream>
#include <string>
#include "../node/Node.h"
#include "../list/List.h"

template <class T>
class LinkedList : public List<T> {
private:
    Node<T>*            mFirst;
    
    bool                isLocationInBounds(int location) const {
                            return location >= 0 && location < this->mSize;
                        }
    
    Node<T>*            getNodeAt(int location) const {
                            if (!isLocationInBounds(location)) {
                                throw std::exception("index out of bounds");
                            }
                            Node<T>* node = mFirst;
                            for (int i = 0; i < location; i++) {
                                node = node->getNext();
                            }
                            return node;
                        }
    
    Node<T>*            getLastNode() const {
                            if (mFirst == nullptr) {
                                throw std::exception("empty linked list");
                            }
                            Node<T>* curr = mFirst;
                            while (curr->getNext() != nullptr)
                                curr = curr->getNext();
                            return curr;
    		            }
    
    void                addNodeStart(Node<T>* node) {
                            node->setNext(mFirst);
                            mFirst = node;
                            this->mSize++;
                        }

    void                addNodeEnd(Node<T>* node) {
                            if (mFirst == nullptr) {
                                mFirst = node;
                            }
                            else {
                                Node<T>* last = getLastNode();
                                last->setNext(node);
                            }
                            this->mSize++;
                        }

    void                copyNodes(const LinkedList& obj) {
                            Node<T>* node = obj.mFirst;
                            while (node != nullptr) {
                                addNodeEnd(new Node<T>(*node));
                                node = node->getNext();
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
                            addNodeEnd(new Node<T>(obj));
                        }

    void                addStart(const T& obj) {
                            addNodeStart(new Node<T>(obj));
                        }
    
    void                insert(const T& obj, int location) {
                            Node<T>* node = new Node<T>(obj);
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
                                Node<T>* prev = getNodeAt(location - 1);
                                node->setNext(prev->getNext());
                                prev->setNext(node);
                                this->mSize++;
                            }
                        }
    
    void                setAt(const T& obj, int location) {
                            Node<T>* node = getNodeAt(location);
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
                                    Node<T>* rmNode = mFirst;
                                    mFirst = mFirst->getNext();
                                    delete rmNode;
                                }
                            }
                            else {
                                Node<T>* prevRmNode = getNodeAt(location - 1);
                                Node<T>* rmNode = prevRmNode->getNext();
                                prevRmNode->setNext(rmNode->getNext());
                                delete rmNode;
                            }
                            this->mSize--;
                        }
    
    int                 indexOf(const T& obj) const {
                            int i = 0;
                            Node<T>* node = mFirst;
                            while (node != nullptr) {
                                if (node->getData() == obj) {
                                    return i;
                                }
                                i++;
                                node = node->getNext();
                            }
                            return -1;
                        }

    void	            clear() {
                            Node<T>* node = mFirst;
                            while (node != nullptr) {
                                Node<T>* rmNode = node;
                                node = node->getNext();
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
                                next = next->getNext();
                            }
                            return ss.str();
                        }
    
    friend std::ostream& operator<<(std::ostream& out, const LinkedList& obj) {
        out << obj.toString();
        return out;
    }
};