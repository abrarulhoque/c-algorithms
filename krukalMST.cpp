#include <iostream>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

int findParent(int node, int parent[]) {
    if (parent[node] != node) {
        parent[node] = findParent(parent[node], parent);
    }
    return parent[node];
}

void unionSets(int u, int v, int parent[], int rank[]) {
    int rootU = findParent(u, parent);
    int rootV = findParent(v, parent);
    if (rootU != rootV) {
        if (rank[rootU] > rank[rootV]) {
            parent[rootV] = rootU;
        } else if (rank[rootU] < rank[rootV]) {
            parent[rootU] = rootV;
        } else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }
}

void kruskalMST(int n, Edge edges[], int m) {
    sort(edges, edges + m);
    int parent[n], rank[n];
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
        rank[i] = 0;
    }

    Edge mst[n - 1];
    int count = 0;
    for (int i = 0; i < m && count < n - 1; ++i) {
        Edge edge = edges[i];
        if (findParent(edge.u, parent) != findParent(edge.v, parent)) {
            mst[count++] = edge;
            unionSets(edge.u, edge.v, parent, rank);
        }
    }

    for (int i = 0; i < count; ++i) {
        cout << mst[i].u << " -- " << mst[i].v << " == " << mst[i].weight << endl;
    }
}

int main() {
    int n = 4;
    Edge edges[] = {
        {0, 1, 10}, {0, 2, 6}, {0, 3, 5}, {1, 3, 15}, {2, 3, 4}
    };
    int m = sizeof(edges) / sizeof(edges[0]);
    kruskalMST(n, edges, m);
    return 0;
}
