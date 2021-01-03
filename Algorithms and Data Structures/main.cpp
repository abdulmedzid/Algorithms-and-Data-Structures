#include <iostream>
#include "./src/data_structures/node/Node.h";
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

int main() {
	TestNodes();
	return 0;
}