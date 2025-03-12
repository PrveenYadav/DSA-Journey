#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function to perform BFS traversal
void BFS(int startNode, const vector<vector<int>>& adjList, vector<bool>& visited) { 
    queue<int> q;
    q.push(startNode);
    visited[startNode] = true;

    while (!q.empty()) {
        int currentNode = q.front();
        q.pop();
        cout << currentNode << " "; // Print the current node

        // Traverse all adjacent nodes
        for (int neighbor : adjList[currentNode]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

int main() {
    int nodes, edges;
    cout << "Enter number of nodes and edges: ";
    cin >> nodes >> edges;

    // Create adjacency list
    vector<vector<int>> adjList(nodes + 1); //1 based indexing
    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u); // Remove this line if the graph is directed
    }

    vector<bool> visited(nodes + 1, false);
    cout << "BFS Traversal: ";

    // Perform BFS from each unvisited node (for disconnected graphs)
    for (int i = 1; i <= nodes; i++) {
        if (!visited[i]) {
            BFS(i, adjList, visited);
        }
    }

    return 0;
}