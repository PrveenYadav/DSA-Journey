#include <iostream>
#include <vector>
#include <queue>
using namespace std;

///All Revision --- 

//bfs and dfs traversal of undirected graph
vector<int> bfsIs(int v, vector<int> adj[]) {
    vector<int> vis(v, 0);
    vis[0] = {1};
    queue<int> q;
    q.push(0);
    vector<int> ans;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for(auto i : adj[node]) {
            if(!vis[i]) {
                vis[i] = 1;
                q.push(i);
            }
        }
    }
    return ans;
}

void dfs(int node, vector<int> adj[], int vis[0], vector<int> &ans) {
    vis[node] = 1;
    ans.push_back(node);
    for(auto i : adj[node]) {
        if(!vis[i]) {
            dfs(i, adj, vis, ans);
            vis[i] = 1;
        }
    }
}

vector<int> dfsIs(int v, vector<int> adj[]) {
    int vis[v] = {0};
    int start = 0; 
    vector<int> ans;
    dfs(start, adj, vis, ans);
    return ans;
}


//Detect a cycle in undirected graph by bfs and dfs
bool detectBfs(int start, vector<int> adj[], int vis[]) {
    vis[start] = 1;
    queue<pair<int, int>> q;
    q.push({start, -1});

    while(!q.empty()) {
        int node = q.front().first;
        int parent = q.front().second;

        for(auto i : adj[node]) {
            if(!vis[i]) {
                q.push({i, node});
                vis[i] = 1;
            }
            else if(parent != i) {
                return true;
            }
        }
    }
    return false;
}

bool isCycle(int v, vector<int> adj[]) {
    int vis[1] = {0};
    for(int i=0; i<v; i++) {
        if(!vis[i]) {
            if(detectBfs(i, adj, vis)) {
                return true;
            }
        }
    }
    return false;
}


bool detectDfs(int node, int parent, vector<int> adj[], int vis[]) {
    vis[node] = 1;
    for(auto i : adj[node]) {
        if(!vis[i]) {
            if(detectDfs(i, -1, adj, vis) == true) {
                return true;
            }
        }
        else if(parent != i) return true;
    }
    return false;
}

bool isCycleDfs(int v, vector<int> adj[]) {
    int vis[1] = {0};
    for(int i=0; i<v; i++) {
        if(!vis[i]) {
            if(detectDfs(i, -1, adj, vis) == true) {
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
    //edges
    adj[0] = {2};
    adj[1] = {2, 3};
    adj[2] = {1, 4};
    adj[3] = {1, 4};
    adj[4] = {2, 3};
    // edges : cycle not present
    // adj[0] = {2};
    // adj[1] = {2, 3};
    // adj[2] = {1, 4};
    // adj[3] = {1};
    // adj[4] = {2};

    vector<int> ans = bfsIs(v, adj);
    cout<<"printing bfs of graph: ";
    for(int i=0; i<ans.size(); i++) {
        cout<< ans[i] <<" ";
    }cout<<endl;

    vector<int> ans1 = dfsIs(v, adj);
    cout<<"printing dfs of graph: ";
    for(int i=0; i<ans1.size(); i++) {
        cout<< ans1[i] <<" ";
    }cout<<endl;

    if(isCycle(v, adj)) {
        cout<<"Cycle Present"<<endl;
    }else {
        cout<<"Cycle not detect"<<endl;
    }
    if(isCycleDfs(v, adj)) {
        cout<<"Cycle Detected"<<endl;
    }else {
        cout<<"Not detected"<<endl;
    }
    return 0;
}