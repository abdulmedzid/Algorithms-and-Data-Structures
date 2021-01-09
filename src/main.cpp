#include <iostream>
#include "./data_structures/node/Node.h"
#include "./data_structures/linked_list/LinkedList.h"
#include "./data_structures/linked_list_doubly/DoublyLinkedList.h"
#include "./data_structures/array/Array.h"
#include "./data_structures/stack/Stack.h"
#include "./data_structures/queue/Queue.h"
#include "./data_structures/tree_binary/BinaryTree.h"
#include "./data_structures/tree_binary_heap/BinaryHeap.h"
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
	node1->setRight(node2);
	node2->setRight(node3);
	cout << *(node1->getRight()) << endl;
	cout << *(node1->getRight()->getRight()) << endl;
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

void TestStack() {
    cout
        << line
        << "STACK TEST" << endl
        << line;

    Stack<int> stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);

    while (!stack.isEmpty()) {
        cout << stack.pop() << endl;
    }

    try {
        stack.pop();
    }
    catch (exception ex) {
        cout << ex.what() << endl;
    }
}

void TestQueue() {
    cout
        << line
        << "QUEUE TEST" << endl
        << line;

    Queue<int> queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);

    while (!queue.isEmpty()) {
        cout << queue.dequeue() << endl;
    }

    try {
        queue.dequeue();
    }
    catch (exception ex) {
        cout << ex.what() << endl;
    }
}

void TestBinaryTree() {
    
    cout
        << line
        << "BINARY TREE TEST" << endl
        << line;
    BinaryTree<int> binaryTree;
    binaryTree.insert(10);
    binaryTree.insert(20);
    binaryTree.insert(30);
    binaryTree.insert(5);
    binaryTree.insert(16);
    binaryTree.insert(50);
    /*
           10
          5  20
           16  30
                 50
    */

    cout << binaryTree << endl;

    BinaryTree<int> copy = binaryTree;
    cout << "copy\n" << copy << endl;
}

void TestBinaryHeap() {
    cout
        << line
        << "BINARY HEAP TEST" << endl
        << line;
    BinaryHeap<int> binaryHeap(MIN);
    for (int i = 1; i <= 10; i++) {
        binaryHeap.insert(i);
    }
    cout << binaryHeap << endl;
    for (int i = 0; i < 8; i++) {
        cout << "extract: " << binaryHeap.extractRoot() << endl;
        cout << binaryHeap << endl;
    }
}

int main() {
	//TestNodes();
	//TestLinkedList();
    //TestDoublyLinkedList();
    //TestArray();
    //TestStack();
    //TestQueue();
    //TestBinaryTree();
    TestBinaryHeap();
    return 0;
}