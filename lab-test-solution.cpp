#include <iostream>
using namespace std;

void initializeMatrix(int adjMatrix[8][8], int vertices) {
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            adjMatrix[i][j] = 0;
        }
    }
}

void addEdge(int adjMatrix[8][8], int vertices, int i, int j, int weight) {
    if (i >= 0 && i < vertices && j >= 0 && j < vertices) {
        adjMatrix[i][j] = weight;
    }
}

void displayMatrix(int adjMatrix[8][8], int vertices) {
    cout << "Adjacency Matrix:" << endl;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

void dfs(int adjMatrix[8][8], int vertices, int node, int visitCount[8], int visited[8][3], int& visitIndex) {
    if (visitCount[node] == 3) {
        return;
    }

    visitCount[node]++;
    visited[node][visitCount[node] - 1] = visitIndex++;
    cout << "Node " << node << " visited " << visitCount[node] << " times." << endl;

    for (int i = 0; i < vertices; i++) {
        if (adjMatrix[node][i] != 0 && visitCount[i] < 3) {
            dfs(adjMatrix, vertices, i, visitCount, visited, visitIndex);
        }
    }
}

int main() {
    int vertices = 8;
    int adjMatrix[8][8];
    int visitCount[8] = {0};
    int visited[8][3] = {{0}};
    int visitIndex = 1;

    initializeMatrix(adjMatrix, vertices);

    // The graph that was given on the question had nodes from 1-7
    // But we initialized the Nodes from 0-6 to instead of 1-7 for simplicity
    addEdge(adjMatrix, vertices, 0, 1, 1);  // 1 -> 2
    addEdge(adjMatrix, vertices, 0, 3, 1);  // 1 -> 4
    addEdge(adjMatrix, vertices, 1, 3, 1);  // 2 -> 4
    addEdge(adjMatrix, vertices, 1, 4, 1);  // 2 -> 5
    addEdge(adjMatrix, vertices, 3, 2, 1);  // 4 -> 3
    addEdge(adjMatrix, vertices, 3, 4, 1);  // 4 -> 5
    addEdge(adjMatrix, vertices, 3, 5, 1);  // 4 -> 6
    addEdge(adjMatrix, vertices, 3, 6, 1);  // 4 -> 7
    addEdge(adjMatrix, vertices, 4, 6, 1);  // 5 -> 7
    addEdge(adjMatrix, vertices, 6, 5, 1);  // 7 -> 6

    displayMatrix(adjMatrix, vertices);

    dfs(adjMatrix, vertices, 0, visitCount, visited, visitIndex);  // Start DFS from node 1 (index 0)

    return 0;
}
