#include <iostream>
#include <vector>
using namespace std;

// Function to create a graph
void createGraph(vector<vector<int>>& adjList, int edges) {
    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u); // Remove this line for a directed graph
    }
}

// Function to print the graph
void printGraph(const vector<vector<int>>& adjList) {
    cout << "Graph representation (Adjacency List):" << endl;
    for (int i = 1; i < adjList.size(); i++) {
        cout << i << " -> ";
        for (int neighbor : adjList[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }
}

int main() {
    int nodes, edges;
    cout << "Enter number of nodes and edges: ";
    cin >> nodes >> edges;

    // Create adjacency list
    vector<vector<int>> adjList(nodes + 1); // 1-based indexing

    // Create the graph
    createGraph(adjList, edges);

    // Print the graph
    printGraph(adjList);

    return 0;
}