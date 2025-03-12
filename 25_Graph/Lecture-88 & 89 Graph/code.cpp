#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//Detect cycle in a undirected graph by **BFS**
//Time complexity: O(n + 2E) + O(n) ans space: O(n)

bool detect(int src, vector<int> adj[], int vis[]) { //src means starting node

    vis[src] = 1;
    queue<pair<int, int>> q; //first is node and second is parent
    q.push({src, -1}); //in starting we pushing values

    while(!q.empty()) {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        
        for(auto i : adj[node]) {
            if(!vis[i]) {
                vis[i] = 1;
                q.push({i, node});
            }
            else if(parent != i) { //cycle detected: if this i(node) is visited and not a parent  
                return true;
            }
        }
    }
    return false;
}

bool isCycle(int v, vector<int> adj[]) {

    int vis[v] = {0};

    //if multiple components of graph(multiple graphs) then it will work
    for(int i=0; i<v; i++) {
        if(!vis[i]) {
            if(detect(i, adj, vis)) {
                return true;
            }
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