#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <queue>
using namespace std;

//BFS Traversal: is like level order traversal

void prepareAdjList(unordered_map<int, list<int>>& adjList, vector<pair<int, int>>& edges) {
    for (auto edge : edges) {
        int u = edge.first;
        int v = edge.second;
        adjList[u].push_back(v);
        adjList[v].push_back(u); // Remove for directed graph
    }
}

// Function to perform BFS traversal from a starting node
void bfs(unordered_map<int, list<int>>& adjList, unordered_map<int, bool>& visited, vector<int>& ans, int startNode) {
    queue<int> q;
    q.push(startNode);
    visited[startNode] = true;

    while (!q.empty()) {
        int currentNode = q.front();
        q.pop();
        ans.push_back(currentNode);

        for (auto neighbor : adjList[currentNode]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

vector<int> BFS(int vertax, vector<pair<int, int>> edges) {
    unordered_map<int, list<int>> adjList;
    vector<int> ans;
    unordered_map<int, bool> visited;

    prepareAdjList(adjList, edges);

    // Traverse all components of the graph
    for (int i = 0; i < vertax; i++) {
        if (!visited[i]) {
            bfs(adjList, visited, ans, i);
        }
    }

    return ans;
}

int main() {
    cout<<endl;

    int vertax = 7; // Example graph with 7 vertices
    vector<pair<int, int>> edges = {
        {0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}
    };

    vector<int> result = BFS(vertax, edges);

    cout << "BFS Traversal: ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}