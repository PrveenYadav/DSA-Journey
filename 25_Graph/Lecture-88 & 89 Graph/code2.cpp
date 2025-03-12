#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <list>
using namespace std;

//Detect cycle in a ***Directed graph by **DFS**
//Time complexity: O(n + E) and space: O(n)
 
bool checkCycleDFS(int node, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsVisited, unordered_map<int, list<int>> &adj) {
    
    visited[node] = true;
    dfsVisited[node] = true;

    for(auto i : adj[node]) { //i is neighbour node
        if(!visited[i]) {
            bool cycleFound = checkCycleDFS(i, visited, dfsVisited, adj);
            if(cycleFound) return true;
        }
        else if(dfsVisited[i]) {
            return true;
        }
    }
    dfsVisited[node] = false;
    return false;
}

int detectCycleDirectedGraph(int n, vector<pair<int, int>> &edges) {
    //create adj list
    unordered_map<int, list<int>> adj;
    for(int i=0; i<edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v); //directed graph
    }

    //call dfs for all components
    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsVisited;
    for(int i=0; i<=n; i++) {
        if(!visited[i]) {
            bool cycleFound = checkCycleDFS(i, visited, dfsVisited, adj);
            if(cycleFound) return true;
        }
    }
}

int main() {
    cout<<endl;

    int n = 5;
    vector<pair<int, int>> edges = {{0, 2}, {2, 1}, {1, 3}, {3, 4}, {4, 1}};

    cout<<"Detect Cycle in Directed graph using DFS: ";
    cout<< detectCycleDirectedGraph(n, edges);
    return 0;
}