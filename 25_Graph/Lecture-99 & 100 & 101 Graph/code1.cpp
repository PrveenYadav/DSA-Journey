#include <iostream> 
#include <vector>
#include <unordered_map>
#include <list>
#include <stack>
using namespace std;

//Kosaraju's Algorithm : Find Strongly connected components(SCCs)

void dfs(int node, unordered_map<int, bool> &vis, stack<int> &st, unordered_map<int, list<int>> &adj) {

    vis[node] = 1;

    for(auto neighbour : adj[node]) {
        if(!vis[neighbour]) {
            dfs(neighbour, vis, st, adj);
        }
    }
    //topo logic
    st.push(node);
}

void revDfs(int node, unordered_map<int, bool> &vis, unordered_map<int, list<int>> &transpose) {
    vis[node] = true;
    for(auto i : transpose[node]) {
        if(!vis[i]) {
            revDfs(i, vis, transpose);
        }
    }
}

int sccByKosaraju(int v, vector<vector<int>> &edges) {

    unordered_map<int, list<int>> adj;
    for(int i=0; i<edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v); //directed graph
    }

    //topo sort
    stack<int> st;
    unordered_map<int, bool> vis;
    for(int i=0; i<v; i++) {
        if(!vis[i]) {
            dfs(i, vis, st, adj);
        }
    }

    //create a transpose graph
    unordered_map<int, list<int>> transpose;
    for(int i=0; i<v; i++) {
        vis[i] = 0;
        for(auto ngbr : adj[i]) {
            transpose[ngbr].push_back(1);
        }
    }

    //dfs call using above ordering
    int count = 0;
    while(!st.empty()) {
        int top = st.top();
        st.pop();
        if(!vis[top]) {
            count++;
            revDfs(top, vis, transpose);
        }
    }

    return count;
}


int main() {
    cout<<endl;

    int v = 5;
    vector<vector<int>> edges = {
        {0, 1},
        {1, 4},
        {4, 0},
        {1, 2},
        {2, 3},
        {3, 2}
    };

    cout<<"Kosaraju's Algo, SCCs : "<< sccByKosaraju(v, edges) <<endl;

    return 0;
}