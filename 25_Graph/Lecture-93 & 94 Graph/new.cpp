#include <iostream>
#include <climits>
#include <vector>
#include <queue>
using namespace std;

// Shortest path in an Undirected Graph
vector<int> shortestPath(int src, int N, vector<vector<int>> &edges) {
    vector<vector<int>> adj(N);
    for (auto &edge : edges) {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }

    vector<int> dist(N, INT_MAX);
    dist[src] = 0;

    queue<int> q;
    q.push(src);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (auto neighbor : adj[node]) {
            if (dist[node] + 1 < dist[neighbor]) {
                dist[neighbor] = dist[node] + 1;
                q.push(neighbor);
            }
        }
    }

    vector<int> ans(N, -1);
    for (int i = 0; i < N; i++) {
        if (dist[i] != INT_MAX) {
            ans[i] = dist[i];
        }
    }
    return ans;
}

int main() {
    int V = 7; // Number of vertices
    vector<vector<int>> edges = {
        {0, 1}, {0, 3}, {1, 2}, {1, 3},
        {2, 6}, {3, 4}, {4, 5}, {5, 6}
    };

    vector<int> ans = shortestPath(0, V, edges);
    cout << "Shortest Path: ";
    for (int dist : ans) {
        cout << dist << " ";
    }
    cout << endl;

    return 0;
}
