#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//Min Spanning Tree using Prime's Algoritm
int spanningTree(int V, vector<vector<int>> adj[]) {

    vector<bool> visited(V, false); //To keep track of visited nodes
    // Min-heap to store {weight, node}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Start from node 0 (arbitrary choice)
    pq.push({0, 0});   //{weight, node}
    int mstWeight = 0; //Initially Total weight of the MST

    while (!pq.empty()) {
        // Extract the node with the smallest edge weight
        pair<int, int> current = pq.top();
        pq.pop();

        int weight = current.first;
        int node = current.second;

        // If the node is already visited, skip it
        if (visited[node]) continue;

        // Mark the node as visited
        visited[node] = true;

        // Add the weight of this edge to the MST weight
        mstWeight += weight;

        // Traverse the neighbors of the current node
        for (auto neighbor : adj[node]) {
            int nextNode = neighbor[0];
            int edgeWeight = neighbor[1];

            // If the neighbor hasn't been visited, add it to the heap
            if (!visited[nextNode]) {
                pq.push({edgeWeight, nextNode});
            }
        }
    }
    return mstWeight;
}

int main() {

    int V = 4;
    vector<vector<int>> adj[V];

    // Example graph:
    // Node 0: {1, 1}, {2, 2}
    // Node 1: {0, 1}, {2, 2}, {3, 1}
    // Node 2: {0, 2}, {1, 2}, {3, 1}
    // Node 3: {1, 1}, {2, 1}
    adj[0].push_back({1, 1});
    adj[0].push_back({2, 2});
    adj[1].push_back({0, 1});
    adj[1].push_back({2, 2});
    adj[1].push_back({3, 1});
    adj[2].push_back({0, 2});
    adj[2].push_back({1, 2});
    adj[2].push_back({3, 1});
    adj[3].push_back({1, 1});
    adj[3].push_back({2, 1});

    cout << "Weight of MST: " << spanningTree(V, adj) << endl;
    return 0;
}