#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <list>
using namespace std;

//DFS Traversal

void dfs(int node, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, vector<int> &component) {
    
    component.push_back(node);
    visited[node] = true;

    //recursive call for every connected node
    for(auto i : adj[node]) {
        if(!visited[i]) {
            dfs(i, adj, visited, component);
        }
    }
}

vector<vector<int>> DFS(int v, int e, vector<vector<int>> edges) {

    //creating adjacency list
    unordered_map<int, list<int>> adj;
    for(int i=0; i<edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>> ans;
    
    //calling all nodes if not visited
    unordered_map<int, bool> visited;
    for(int i=0; i<v; i++) {
        if(!visited[i]) {

            vector<int> component;
            dfs(i, adj, visited, component);
            ans.push_back(component);
        }
    }
    return ans;
}

int main() {
    cout<<endl;

    vector<vector<int>> edges = {{0, 2}, {2, 1}, {2, 4}, {1, 3}, {4, 3}};
    int v = 5; //verted means nodes
    int e = 5; //edges

    cout<<"DFS Traversal: ";
    vector<vector<int>> ans = DFS(v, e, edges);
    for(auto i : ans) {
        for(auto j : i) {
            cout<< j <<" ";
        }
    }cout<<endl;
    return 0;
}