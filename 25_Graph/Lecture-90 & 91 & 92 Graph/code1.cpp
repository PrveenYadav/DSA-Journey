#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <stack>
using namespace std;

//A topological sort is a linear ordering of vertices(nodes) in a DAG(dircted acyclic graph)
//Topological sort : we can use this at only DAG(directed acyclic graph)
//we will solve it by DFS

void topoSort(int node, vector<bool> &vis, unordered_map<int, list<int>> &adj, stack<int> &s) {
    vis[node] = 1;

    for(auto i : adj[node]) {
        if(!vis[i]) {
            topoSort(i, vis, adj, s);
        }
    }
    s.push(node);
}

vector<int> topologySort(vector<vector<int>> &edges, int v, int e) {
    //creating adj list;
    unordered_map<int, list<int>> adj;
    for(int i=0; i<e; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    //call dfs topological sort function for all components
    vector<bool> visited;
    stack<int> s;
    for(int i=0; i<v; i++) {
        if(!visited[i]) {
            topoSort(i, visited, adj, s);
        }
    }
    
    vector<int> ans;
    while(!s.empty()) {
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}

int main() {
    cout<<endl;

    int v = 6;
    int e = 7;
    vector<vector<int>> adj(v);
    adj[1] = {2, 3};
    adj[2] = {4};
    adj[3] = {4};
    adj[4] = {5, 6};
    adj[5] = {6};
    adj[6] = {};

    vector<int> ans = topologySort(adj, v, e);
    cout<<"Topological sort: ";
    for(int i=0; i<ans.size(); i++) {
        cout<< ans[i] <<" ";
    }cout<<endl;
    return 0;
}