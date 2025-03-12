#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//Detect cycle in a undirected graph by **DFS**
//Time complexity: O(n + 2E) + O(n) and space: O(n)
 
bool dfs(int node, int parent, vector<int> adj[], int vis[]) {

    vis[node] = 1;
    for(auto i : adj[node]) {
        if(!vis[i]) {
            if(dfs(i, node, adj, vis) == true) 
                return true;
        }
        else if(i != parent) return true;
    }
    return false;
}

bool isCycle(int v, vector<int> adj[]) {

    //if only one graph then we only do function call of dfs but if there is multiple components(graphs) then we have to check particularly
    int vis[v] = {0}; //0 base indexing

    for(int i=0; i<v; i++) {
        if(!vis[i]) {
            if(dfs(i, -1, adj, vis) == true) return true;
        }
    }
    return false;
}

int main() {
    cout<<endl;

    int v = 5;
    vector<int> adj[v];

    adj[0] = {2};
    adj[1] = {2, 3};
    adj[2] = {1, 4};
    adj[3] = {1, 4};
    adj[4] = {2, 3};
    //Not detected cycle---
    // adj[0] = {1, 2, 4};
    // adj[1] = {0};
    // adj[2] = {0};
    // adj[3] = {4};
    // adj[4] = {0, 3};

    if(isCycle(v, adj)) {
        cout<<"Cycle Detected"<<endl;
    }else {
        cout<<"Not Detected"<<endl;
    }

    return 0;
}