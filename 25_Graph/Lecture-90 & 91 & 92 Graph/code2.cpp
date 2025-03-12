#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;

//Topological sort : Kahn's Algorithm : DAG : using BFS

vector<int> topologySort(vector<vector<int>> &edges, int v, int e) {
    //creating adj list;
    unordered_map<int, list<int>> adj;
    for(int i=0; i<e; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    //find all in degrees
    vector<int> indegree(v);
    for(auto i : adj) {
        for(auto j : i.second) {
            indegree[j]++;  
        }
    }
    
    //0 indegree walo ko push kr do
    queue<int> q;
    for(int i=0; i<v; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }

    //do bfs
    vector<int> ans;
    while(!q.empty()) {
        int front = q.front();
        q.pop();

        ans.push_back(front);

        for(auto i : adj[front]) {
            indegree[i]--;
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
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
    //adj[6] = {};

    vector<int> ans = topologySort(adj, v, e);
    cout<<"Topological sort: ";
    for(int i=0; i<ans.size(); i++) {
        cout<< ans[i] <<" ";
    }cout<<endl;
    return 0;
}