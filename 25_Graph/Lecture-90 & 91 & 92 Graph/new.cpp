#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

//Topological sort DFS
void dfs(int node, int vis[], vector<int> adj[], stack<int> &st) {
    vis[node] = 1;
    for(auto i : adj[node]) {
        if(!vis[i]) {
            dfs(i, vis, adj, st);
        }
    }
    st.push(node);
}

vector<int> topoSort(int v, vector<int> adj[]) {
    int vis[v] = {0};
    stack<int> st;
    for(int i=0; i<v; i++) {
        if(!vis[i]) {
            dfs(i, vis, adj, st);
        }
    }

    vector<int> ans;
    while(!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

//Topological sort BFS : Kahn's Algorithm 
vector<int> topoSortBFS(int v, vector<int> adj[]) {
    int indegree[v] = {0}; //indegree: number of incoming edges to the node
    for(int i=0; i<v; i++) {
        for(auto i : adj[i]) {
            indegree[i]++;
        }
    }

    queue<int> q;
    for(int i=0; i<v; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> ans;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        ans.push_back(node);

        for(auto i : adj[node]) {
            indegree[i]--;
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
    }
    return ans;
}

//Cycle detection in Directed graph : kahn's algo bfs
bool isCycle(int v, vector<int> adj[]) {
    int indegree[v] = {0}; 
    for(int i=0; i<v; i++) {
        for(auto i : adj[i]) {
            indegree[i]++;
        }
    }

    queue<int> q;
    for(int i=0; i<v; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }

    int count = 0;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        count++;

        for(auto i : adj[node]) {
            indegree[i]--;
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
    }
    
    if(count == v) return false;
    return true;
}

int main() {
    cout<<endl;

    int v = 6;
    vector<int> adj[v];
    adj[0] = {};
    adj[1] = {};
    adj[2] = {3};
    adj[3] = {1};
    adj[4] = {0, 1};
    adj[5] = {0, 2};

    vector<int> ans = topoSort(v, adj);
    cout<<"Topological Order DFS: ";
    for(int i=0; i<ans.size(); i++) {
        cout<< ans[i] <<" ";
    }cout<<endl;

    vector<int> bfs = topoSortBFS(v, adj);
    cout<<"Topological Order BFS: ";
    for(int i=0; i<bfs.size(); i++) {
        cout<< bfs[i] <<" ";
    }cout<<endl;

    if(isCycle(v, adj)) {
        cout<<"Cycle Detected"<<endl;
    }else {
        cout<<"Cycle Not Detected"<<endl;
    }
    return 0;
}