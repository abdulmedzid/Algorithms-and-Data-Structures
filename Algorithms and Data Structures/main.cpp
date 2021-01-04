#include <iostream>
#include "./src/data_structures/node/Node.h"
#include "src/data_structures/liked_list/LinkedList.h"
using namespace std;

const char* line = "###############################\n";

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
		linkedList.add(linkedList.get(i - 1) + linkedList.get(i - 2));
	}

	cout << linkedList << endl;
}

int main() {
	TestNodes();
	TestLinkedList();
	return 0;
}