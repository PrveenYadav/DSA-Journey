#include <iostream>
#include <vector>
using namespace std;

//Bridge in a Graph
//Problem: Critical connections in a network : Leetcode-1192 (Hard)

//declaring the timer Grobly
int timer = 1;

void dfs(int node, int parent, vector<int> &vis, vector<int> adj[], int tin[], int low[], vector<vector<int>> &bridge) {

    vis[node] = 1;
    tin[node] = low[node] = timer;
    timer++;

    for(auto it : adj[node]) {
        if(it == parent) continue;
        if(vis[it] == 0) { //if not visited
            dfs(it, node, vis, adj, tin, low, bridge    );
            low[node] = min(low[node], low[it]);
            //node ---- it
            if(low[it] > tin[node]) {
                bridge.push_back({it, node});
            }
        }else {
            low[node] = min(low[node], low[it]);
        }
    }
}

vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections) { //connections means edges
    
    vector<int> adj[n];
    for(auto it : connections) {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    vector<int> vis(n, 0);
    int tin[n]; //time of insertion
    int low[n];
    vector<vector<int>> bridges;

    dfs(0, -1, vis, adj, tin, low, bridges);
    return bridges;
}


int main() {
    cout<<endl;

    vector<vector<int>> edges = {
        {2, 0},
        {1, 0},
        {2, 1},
        {0, 4},
        {4, 5},
        {4, 3},
        {3, 5}
    };
    int n = edges.size();

    vector<vector<int>> ans = criticalConnections(n, edges);
    cout<<"Edge where the Bridge Exist: ";
    for(auto i : ans) {
        for(auto j : i) {
            cout<< j <<" ";
        }cout<<endl;
    }

    return 0;
}