#pragma once

#include "../../data_structures/linked_list/LinkedList.h"
#include "../../data_structures/stack/Stack.h"
#include "../../data_structures/queue/Queue.h"
#include "../../data_structures/graph/AdjacencyMatrix.h"

LinkedList<int> Bfs(const AdjacencyMatrix& adj, int start) {
    LinkedList<int> visited;
    Queue<int> queue;

    queue.enqueue(start);

    while (!queue.isEmpty()) {
        int vertex = queue.dequeue();

        if (!visited.contains(vertex)) {
            visited.add(vertex);

            for (int n = 0; n < adj.getSize(); n++) {
                
                if (adj.isNeigbour(vertex, n) && !visited.contains(n)) {
                    queue.enqueue(n);
                }
            }
        }
    }

    return visited;
}