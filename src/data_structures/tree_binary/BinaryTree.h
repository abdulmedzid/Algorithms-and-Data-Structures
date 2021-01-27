#pragma once
#include <iostream>
#include <sstream>
#include <cmath>
#include <functional>
#include "../node/Node.h"
#include "../queue/Queue.h"
#include "../stack/Stack.h"

template <class T>
class BinaryTree {
private:
    typedef Node<T> Node;
    Node*               mRoot;

    void                insert(const T& obj, Node*& nodePtr) {
                            if (nodePtr == nullptr) {
                                nodePtr = new Node(obj);
                                return;
                            }
                            if (obj < nodePtr->getData()) {
                                insert(obj, nodePtr->getLeft());
                            }
                            else {
                                insert(obj, nodePtr->getRight());
                            }
                        }

    void                copy(Node*& root, Node* copyRoot) {
                            if (copyRoot == nullptr) {
                                return;
                            }
                            root = new Node(*copyRoot);
                            copy(root->getLeft(), copyRoot->getLeft());
                            copy(root->getRight(), copyRoot->getRight());
                        }

public:
                        BinaryTree() : mRoot(nullptr) {}

                        BinaryTree(const BinaryTree& obj) {
                            copy(mRoot, obj.mRoot);
                        }

                        ~BinaryTree() {
                            clear();
                        }

    BinaryTree&         operator=(const BinaryTree& obj) {
                            if (this != &obj) {
                                clear();
                                copy(obj);
                            }
                            return *this;
                        }

    void                clear() {
                            postOrder(
                                mRoot, 
                                [](Node* node) {
                                    delete node;
                                }
                            );
                        }

    void                insert(const T& obj) {
                            insert(obj, mRoot);
                        }

    int                    getHeight(Node* root = nullptr, int height = 0) const {
                            if (root == nullptr) {
                                return height;
                            }
                            height++;
                            return std::max(
                                getHeight(root->getLeft(), height), 
                                getHeight(root->getRight(), height)
                            );
                        }

    void                inOrder(Node* root, std::function<void(Node*)> callback) {
                            if (root == nullptr) {
                                return;
                            }
                            inOrder(root->getLeft(), callback);
                            callback(root);
                            inOrder(root->getRight(), callback);
                        }

    void                preOrder(Node* root, std::function<void(Node*)> callback) {
                            if (root == nullptr) {
                                return;
                            }
                            callback(root);
                            preOrder(root->getLeft(), callback);
                            preOrder(root->getRight(), callback);
                        }

    void                postOrder(Node* root, std::function<void(Node*)> callback) {
                            if (root == nullptr) {
                                return;
                            }
                            postOrder(root->getLeft(), callback);
                            postOrder(root->getRight(), callback);
                            callback(root);
                        }

    void                inOrderIterative(std::function<void(Node*)> callback) {
                            Stack<Node*> stack;
                            Node* curr = mRoot;
                            while (curr != nullptr || !stack.isEmpty()) {
             
                                while (curr != nullptr) {
                                    stack.push(curr);
                                    curr = curr->getLeft();
                                }

                                Node* node = stack.pop();
                                callback(node);

                                curr = node->getRight();
                            }
                        }

    void                preOrderIterative(std::function<void(Node*)> callback) {
                            Queue<Node*> queue;
                            queue.enqueue(mRoot);
                            while (!queue.isEmpty())
                            {
                                Node* root = queue.dequeue();
                                if (root != nullptr) {
                                    callback(root);
                                    queue.enqueue(root->getLeft());
                                    queue.enqueue(root->getRight());
                                }
                            }
                        }

    void                postOrderIterative(std::function<void(Node*)> callback) {
                            Stack<Node*> stack;
                            Stack<Node*> orderStack;
                            stack.push(mRoot);
                            while (!stack.isEmpty()) {
                                Node* curr = stack.pop();
                                if (curr != nullptr) {
                                    stack.push(curr->getLeft());
                                    stack.push(curr->getRight());
                                    orderStack.push(curr);
                                }
                            }
                            while (!orderStack.isEmpty()) {
                                callback(orderStack.pop());
                            }
                        }

    std::string         toString() const {
                            std::stringstream ss;
                            int height = getHeight(mRoot);
        
                            if (mRoot == nullptr) {
                                return "no tree";
                            }

                            Queue<Node*> queue;
                            queue.enqueue(mRoot);

                            while (!queue.isEmpty()) {
                                int nodeCount = queue.getSize();
                                while (nodeCount > 0) {
                                    Node* node = queue.dequeue();
                                    ss << *node << " ";
                                    if (node->getLeft() != nullptr) {
                                        queue.enqueue(node->getLeft());
                                    }
                                    if (node->getRight() != nullptr) {
                                        queue.enqueue(node->getRight());
                                    }
                                    nodeCount--;
                                }
                                ss << std::endl;
                            }
                            return ss.str();
                        }

    friend std::ostream& operator<<(std::ostream& out, BinaryTree<T>& obj) {
        out << obj.toString();
        return out;
    }
};