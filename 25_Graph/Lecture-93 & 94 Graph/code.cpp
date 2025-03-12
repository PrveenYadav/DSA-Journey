#include <iostream>
#include <vector>
#include <stack>
#include <climits>
using namespace std;

// Perform Topological Sort
void topologicalSort(int node, vector<pair<int, int>> adj[], vector<bool> &visited, stack<int> &s) {
    visited[node] = true;
    for (auto &neighbor : adj[node]) {
        if (!visited[neighbor.first]) {
            topologicalSort(neighbor.first, adj, visited, s);
        }
    }
    s.push(node);
}

// Shortest Path in DAG
vector<int> shortestPathDAG(int src, int N, vector<vector<int>> &edges) {
    // Create adjacency list with weights
    vector<pair<int, int>> adj[N];
    for (auto &edge : edges) {
        int u = edge[0], v = edge[1], weight = edge[2];
        adj[u].push_back({v, weight});
    }

    // Perform Topological Sort
    vector<bool> visited(N, false);
    stack<int> topoStack;
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            topologicalSort(i, adj, visited, topoStack);
        }
    }

    // Initialize distances to all nodes as infinity
    vector<int> dist(N, INT_MAX);
    dist[src] = 0;

    // Process nodes in topological order
    while (!topoStack.empty()) {
        int node = topoStack.top();
        topoStack.pop();

        // If the current node has been reached before
        if (dist[node] != INT_MAX) {
            for (auto &neighbor : adj[node]) {
                int v = neighbor.first;
                int weight = neighbor.second;
                if (dist[node] + weight < dist[v]) {
                    dist[v] = dist[node] + weight;
                }
            }
        }
    }

    return dist;
}

int main() {
    int N = 6; // Number of vertices
    vector<vector<int>> edges = {
        {0, 1, 2}, {0, 4, 1}, {1, 2, 3}, {4, 2, 2},
        {4, 5, 4}, {2, 3, 6}, {5, 3, 1}
    };

    int src = 0;
    vector<int> shortestPaths = shortestPathDAG(src, N, edges);

    cout << "Shortest paths from source " << src << ": ";
    for (int i = 0; i < N; i++) {
        if (shortestPaths[i] == INT_MAX) {
            cout << "INF ";
        } else {
            cout << shortestPaths[i] << " ";
        }
    }
    cout << endl;

    return 0;
}