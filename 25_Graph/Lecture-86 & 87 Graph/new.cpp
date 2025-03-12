#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//BFS uses queue and visited : while DFS uses Recursion and visited
//BFS Traversal
vector<int> bfsOfGraph(int v, vector<int> adj[]) {

    vector<int> vis(v, 0); //visited array : prev was => vis[v] = {0} 
    vis[0] = 1;
    queue<int> q;
    q.push(0);
    vector<int> ans;

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        ans.push_back(node);

        for(auto i : adj[node]) {
            if(!vis[i] ) {
                vis[i] = 1;
                q.push(i);
            }
        }
    }
    return ans;
}

//Geeks for geeks way
vector<int> bfsOfGraph1(vector<vector<int>> &adj) {
    int n = adj.size();
    int vis[n] = {0};
    vis[0] = 1;
    queue<int> q;
    q.push(0);
    vector<int> ans;

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        ans.push_back(node);

        for(auto i : adj[node]) {
            if(!vis[i] ) {
                vis[i] = 1;
                q.push(i);
            }
        }
    }
    return ans;
}


//Recursive Function for DFS
void dfs(int node, vector<int> adj[], int vis[0], vector<int> &adjList) {
    vis[node] = 1;
    adjList.push_back(node);

    //traverse the all neighbour nodes
    for(auto i : adj[node]) {
        if(!vis[i]) {
            dfs(i, adj, vis, adjList);
        }
    }
}

//DFS of Graph : Recursion algorith use
vector<int> dfsOfGraph(int v, vector<int> adj[]) {

    int vis[v] = {0};
    int start = 0; //0 based indexing
    vector<int> adjList;
    dfs(start, adj, vis, adjList);
    return adjList;
}

int main() {
    cout<<endl;

    int v = 5;
    vector<int> adj[v]; //adjacency list

    //Edges : are connected with
    adj[0] = {2};
    adj[1] = {2, 3};
    adj[2] = {1, 4};
    adj[3] = {1, 4};
    adj[4] = {2, 3};
    
    vector<int> bfs = bfsOfGraph(v, adj);
    cout<<"BFS Traversal: ";
    for(int i=0; i<bfs.size(); i++) {
        cout<< bfs[i] <<" "; 
    }cout<<endl;

    vector<int> dfs = dfsOfGraph(v, adj);
    cout<<"DFS Traversal: ";
    for(int i=0; i<dfs.size(); i++) {
        cout<< dfs[i] <<" "; 
    }cout<<endl;


    //For bfs 1 function
    // int v = 5;
    // //vector<vector<int>> adj = {{0, 2},{1, 3}, {2, 1}, {2, 4},{3, 4}};
    // vector<vector<int>> adj(v);
    // //Edges
    // adj[0] = {2};
    // adj[1] = {2, 3};
    // adj[2] = {1, 4};
    // adj[3] = {1, 4};
    // adj[4] = {2, 3};

    // vector<int> ans = bfsOfGraph1(adj);
    // cout<<"BFS of Graph: ";
    // for(int i=0; i<ans.size(); i++) {
    //     cout<< i <<" ";
    // }cout<<endl;

    return 0;
}