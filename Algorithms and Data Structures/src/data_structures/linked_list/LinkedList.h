#pragma once
#include <exception>
#include "../node/Node.h"
#include "../list/List.h"

template <class T>
class LinkedList : public List<T> {
private:
	Node<T>* mFirst;
	int mSize;

	bool locationInBounds(int location) const {
		return location >= 0 && location < mSize;
	}

	Node<T>* getNodeAt(int location) const {
		if (!locationInBounds(location)) {
			throw std::exception("index out of bounds");
		}
		Node<T>* curr = mFirst;
		for (int i = 0; i < location; i++) {
			curr = curr->getNext();
		}
		return curr;
	}

	Node<T>* getLastNode() const {

		if (mFirst == nullptr) {
			throw std::exception("empty linked list");
		}

		Node<T>* curr = mFirst;
		while (curr->getNext() != nullptr)
			curr = curr->getNext();
		return curr;
	}

	void addNode(Node<T>* newNode) {
		if (mFirst == nullptr) {
			mFirst = newNode;
		}
		else {
			Node<T>* last = getLastNode();
			last->setNext(newNode);
		}
		mSize++;
	}

	void clear() {
		Node<T>* curr = mFirst;
		while (curr != nullptr) {
			Node<T>* prev = curr;
			curr = curr->getNext();
			delete prev;
		}
		mFirst = nullptr;
		mSize = 0;
	}

public:
	LinkedList() : mFirst(nullptr), mSize(0) {}

	LinkedList(const LinkedList& obj) {
		Node<T>* next = obj.mFirst;
		while (next != nullptr) {
			addNode(new Node(*next));
			next = next->getNext();
		}
	}

	~LinkedList() {
		clear();
	}

	LinkedList& operator=(const LinkedList& obj) {
		clear(); 
		Node<T>* next = obj.mFirst;
		while (next != nullptr) {
			addNode(new Node(*next));
			next = next->getNext();
		}
	}

	void add(const T& obj) {
		addNode(new Node<T>(obj));
	}

	void insert(const T& obj, int location) {
		Node<T>* newNode = new Node<T>(obj);

		if (location == 0) {
			if (mFirst == nullptr) {
				mFirst = newNode;
			}
			else {
				newNode->setNext(mFirst);
				mFirst = newNode;
			}
		}
		else {
			Node<T>* prev = getNodeAt(location - 1);
			newNode->setNext(prev->getNext());
			prev->setNext(newNode);
		}

		mSize++;
	}

	void setAt(const T& obj, int location) {
		Node<T>* node = getNodeAt(location);
		node->setData(obj);
	}

	T& get(int location) const {
		return getNodeAt(location)->getData();
	}

	void remove(const T& obj) {
		removeAt(indexOf(obj));
	}

	void removeAt(int location) {
		if (location == 0) {
			if (mFirst == nullptr) {
				throw std::exception("empty linked list");
			}
			else {
				Node<T>* toBeRemoved = mFirst;
				mFirst = mFirst->getNext();
				delete toBeRemoved;
			}
			return;
		}
		Node<T>* beforeToBeRemoved = getNodeAt(location - 1);
		Node<T>* toBeRemoved = beforeToBeRemoved->getNext();
		beforeToBeRemoved->setNext(toBeRemoved->getNext());
		delete toBeRemoved;
		mSize--;
	}

	int indexOf(const T& obj) const {
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

	friend std::ostream& operator<<(std::ostream& out, const LinkedList& obj) {
		Node<T>* next = obj.mFirst;
		while (next != nullptr) {
			out << next->getData() << " ";
			next = next->getNext();
		}
		return out;
	}
};