#include <iostream>
#include "./src/data_structures/node/Node.h"
#include "src/data_structures/linked_list/LinkedList.h"
#include "src/data_structures/linked_list_doubly/DoublyLinkedList.h"
#include "src/data_structures/array/Array.h"
using namespace std;

const char* line = "---------------------------------------------------\n";

void TestNodes() {
	cout
		<< line
		<< "NODE TEST" << endl
		<< line;
	Node<int>* node1 = new Node<int>(10);
	Node<int>* node2 = new Node<int>(20);
	Node<int>* node3 = new Node<int>(30);
	node1->setNext(node2);
	node2->setNext(node3);
	cout << *(node1->getNext()) << endl;
	cout << *(node1->getNext()->getNext()) << endl;
}

void TestLinkedList() {
	cout
		<< line
		<< "LINKED LIST TEST" << endl
		<< line;
	LinkedList<int> linkedList;
	int a = 1;
	linkedList.add(a);
	linkedList.add(1);
	for (int i = 2; i < 20; i++) {
		linkedList.add(linkedList.getAt(i - 1) + linkedList.getAt(i - 2));
	}
	cout << linkedList << endl;
	linkedList.setAt(30, 1);
	cout << linkedList << endl;
	linkedList.removeAt(1);
	cout << linkedList << endl;
	linkedList.insert(999, 5);
	cout << linkedList << endl;
	linkedList.remove(999);
	cout << linkedList << endl;

    LinkedList<int> linkedListCopy(linkedList);
    cout
        << "copy constructor:" << endl
        << linkedListCopy << endl;

    LinkedList<int> linkedListAsignment;
    linkedListAsignment = linkedListCopy;
    cout
        << "asignment:" << endl
        << linkedListAsignment << endl;
}

void TestDoublyLinkedList() {
    cout
        << line
        << "DOUBLY LINKED LIST TEST" << endl
        << line;
    DoublyLinkedList<int> linkedList;
    int a = 1;
    linkedList.add(a);
    linkedList.add(1);
    for (int i = 2; i < 20; i++) {
        linkedList.add(linkedList.getAt(i - 1) + linkedList.getAt(i - 2));
    }
    cout << linkedList << endl;
    linkedList.setAt(30, 1);
    cout << linkedList << endl;
    linkedList.removeAt(1);
    cout << linkedList << endl;
    linkedList.insert(999, 5);
    cout << linkedList << endl;
    linkedList.remove(999);
    cout << linkedList << endl;

    DoublyLinkedList<int> linkedListCopy(linkedList);
    cout 
        << "copy constructor:" << endl 
        << linkedListCopy << endl;

    DoublyLinkedList<int> linkedListAsignment;
    linkedListAsignment = linkedListCopy;
    cout
        << "asignment:" << endl
        << linkedListAsignment << endl;
}

void TestArray() {
    cout
        << line
        << "ARRAY TEST" << endl
        << line;
    Array<int> array;
    int a = 1;
    array.add(a);
    array.add(1);
    for (int i = 2; i < 20; i++) {
        array.add(array[i-1] + array[i-2]);
    }
    cout << array << endl;
    array.setAt(30, 1);
    cout << "setAt(30, 1)" << endl;
    cout << array << endl;
    array.removeAt(1);
    cout << "removeAt(1)" << endl;
    cout << array << endl;
    array.insert(999, 5);
    cout << "insert(999, 5)" << endl;
    cout << array << endl;
    array.remove(999);
    cout << "remove(999)" << endl;
    cout << array << endl;

    Array<int> arrayCopy(array);
    cout
        << "copy constructor:" << endl
        << arrayCopy << endl;

    Array<int> arrayAsigned;
    arrayAsigned = arrayCopy;
    cout
        << "asignment:" << endl
        << arrayAsigned << endl;
}

int main() {
	//TestNodes();
	//TestLinkedList();
    //TestDoublyLinkedList();
    TestArray();
    return 0;
}