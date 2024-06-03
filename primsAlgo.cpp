#include <iostream>
#include <climits>
#include <queue>
using namespace std;

void primMST(int n, int graph[][5]) {
    int key[n];
    int parent[n];
    bool inMST[n];
    for (int i = 0; i < n; ++i) {
        key[i] = INT_MAX;
        parent[i] = -1;
        inMST[i] = false;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    key[0] = 0;
    pq.push({0, 0});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        inMST[u] = true;

        for (int v = 0; v < n; ++v) {
            if (graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                pq.push({key[v], v});
                parent[v] = u;
            }
        }
    }

    for (int i = 1; i < n; ++i) {
        cout << parent[i] << " -- " << i << " == " << graph[i][parent[i]] << endl;
    }
}

int main() {
    int n = 5;
    int graph[5][5] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    primMST(n, graph);
    return 0;
}
