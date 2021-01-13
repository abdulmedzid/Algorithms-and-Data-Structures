#pragma once
#include <iostream>
#include <sstream>
#include "../array/Array.h"

template <class T>
struct Edge {
    T a;
    T b;
    int weight;

    Edge() : weight(0) {}

    Edge(const T& a, const T& b, int weight = 0) {
        this->a = a;
        this->b = b;
        this->weight = weight;
    }

    bool operator==(const Edge& obj) {
        return a == obj.a && b == obj.b;
    }

    std::string toString() const {
        std::stringstream ss;
        ss << a << " to " << b << " (" << weight << ")";
        return ss.str();
    }

    friend std::ostream& operator<<(std::ostream& out, const Edge& obj) {
        out << obj.toString();
        return out;
    }
};

template <class T>
class AdjacencyList {
private:
    Array<Edge<T>> mEdges;
public:
    void addEdge(const Edge<T>& edge) {
        mEdges.add(edge);
    }

    void addEdge(const T& a, const T& b, int weight = 0) {
        addEdge(Edge<T>(a, b, weight));
    }

    void removeEdge(const Edge<T>& edge) {
        mEdges.remove(edge);
    }

    void removeEdge(const T& a, const T& b) {
        removeEdge(Edge<T>(a, b));
    }

    Array<Edge<T>>& getEdges() {
        return mEdges;
    }

    std::string toString() const {
        std::stringstream ss;
        for (int i = 0; i < mEdges.getSize(); i++) {
            ss << mEdges[i].toString() << std::endl;
        }
        return ss.str();
    }

    friend std::ostream& operator<<(std::ostream& out, const AdjacencyList& obj) {
        out << obj.toString();
        return out;
    }
};