#pragma once
#include <fstream>
#include <iostream>
#include <sstream>

class AdjacencyMatrix {
private:
    int** mMatrix;
    int mNodeCount;

    void alocateMatrix() {
        mMatrix = new int* [mNodeCount];
        for (int i = 0; i < mNodeCount; i++) {
            mMatrix[i] = new int[mNodeCount];
            for (int j = 0; j < mNodeCount; j++) {
                mMatrix[i][j] = 0;
            }
        }
    }

    void alocateMatrix(std::ifstream& file) {
        mMatrix = new int* [mNodeCount];
        for (int i = 0; i < mNodeCount; i++) {
            mMatrix[i] = new int[mNodeCount];
            for (int j = 0; j < mNodeCount; j++) {
                file >> mMatrix[i][j];
            }
        }
    }

    void copy(const AdjacencyMatrix& obj) {
        mNodeCount = obj.mNodeCount;
        alocateMatrix();
        for (int i = 0; i < mNodeCount; i++) {
            for (int j = 0; j < mNodeCount; j++) {
                mMatrix[i][j] = obj.mMatrix[i][j];
            }
        }
    }
public:
    AdjacencyMatrix(int nodeCount = 0) : mNodeCount(nodeCount) {
        if (nodeCount > 0) {
            alocateMatrix();
        }
        else {
            mMatrix = nullptr;
        }
    }

    AdjacencyMatrix(std::string path) {
        loadFromFile(path);
    }

    AdjacencyMatrix(const AdjacencyMatrix& obj) {
        copy(obj);
    }

    ~AdjacencyMatrix() {
        clear();
    }

    AdjacencyMatrix& operator=(const AdjacencyMatrix& obj) {
        if (this != &obj) {
            clear();
            copy(obj);
        }
        return *this;
    }

    void loadFromFile(std::string path) {
        if (mMatrix != nullptr) {
            clear();
        }
        std::ifstream inputFile;
        inputFile.open(path);
        inputFile >> mNodeCount;
        alocateMatrix(inputFile);
        inputFile.close();
    }

    void clear() {
        for (int i = 0; i < mNodeCount; i++) {
            delete[] mMatrix[i];
        }
        delete[] mMatrix;
    }

    void addNode() {
        int** temp = mMatrix;
        mNodeCount++;
        alocateMatrix();

        for (int i = 0; i < mNodeCount - 1; i++) {
            for (int j = 0; j < mNodeCount - 1; j++) {
                mMatrix[i][j] = temp[i][j];
            }
        }

        for (int i = 0; i < mNodeCount - 1; i++) {
            delete[] temp[i];
        }
        delete[] temp;
    }

    int& operator()(int a, int b) {
        return mMatrix[a][b];
    }

    void addEdge(int a, int b, int weight) {
        mMatrix[a][b] = weight;
    }

    int getEdgeWeight(int from, int to) const {
        return mMatrix[from][to];
    }

    int getSize() const {
        return mNodeCount;
    }

    bool isNeigbour(int from, int to) const {
        return mMatrix[from][to] > 0;
    }

    std::string toString() const {
        std::stringstream ss;
        ss << "  | ";
        for (int i = 0; i < mNodeCount; i++) {
            ss << i << " | ";
        }
        ss << std::endl << std::string(mNodeCount * 4 + 3, '-') << std::endl;
        for (int i = 0; i < mNodeCount; i++) {
            ss << i << " | ";
            for (int j = 0; j < mNodeCount; j++) {
                ss << mMatrix[i][j] << " | ";
            }
            ss << std::endl;
        }
        ss << std::endl;
        return ss.str();
    }

    friend std::ostream& operator<<(std::ostream& out, const AdjacencyMatrix& obj) {
        out << obj.toString();
        return out;
    }
};