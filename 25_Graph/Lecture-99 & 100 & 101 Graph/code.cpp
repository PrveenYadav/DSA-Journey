#include <iostream> 
#include <vector>
#include <unordered_map>
#include <list>
using namespace std;

//Articulation points in a Graph: when nodes disconnects and make 2 or more components

void dfs(int node, int parent, unordered_map<int, bool> &vis, vector<int> &disc, vector<int> &low, vector<int> &ap, int &timer, unordered_map<int, list<int>> &adj) {
    
    vis[node] = true;
    disc[node] = low[node] = timer++;
    int child = 0;

    for(auto neighbour : adj[node]) {
        if(neighbour == parent) continue;
        if(!vis[neighbour]) {
            dfs(neighbour, node, vis, disc, low, ap, timer, adj);
            low[node] = min(low[node], low[neighbour]);

            //check Articulation point or not
            if(low[neighbour] >= disc[node] && parent != -1) {
                ap[node] = 1;
            }
            child++;
        }
        else {
            low[node] = min(low[node], disc[neighbour]);
        }
    }

    if(parent == -1 && child > 1) {
        ap[node] = 1;
    }
}

int main() {
    int n = 5, e = 5; //no. of nodes and edges
    vector<pair<int, int>> edges;
    edges.push_back(make_pair(0, 3));
    edges.push_back(make_pair(3, 4));
    edges.push_back(make_pair(0, 4));
    edges.push_back(make_pair(0, 1));
    edges.push_back(make_pair(1, 2));

    //adj list
    unordered_map<int, list<int>> adj;
    for(int i=0; i<edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timer = 0; 
    vector<int> disc(n);
    vector<int> low(n);
    unordered_map<int, bool> vis;
    vector<int> ap(n, 0); //Articulation point

    for(int i=0; i<n; i++) {
        disc[i] = -1; 
        low[i] = -1;
    }

    //dfs call
    for(int i=0; i<n; i++) {
        if(!vis[i]) {
            dfs(i, -1, vis, disc, low, ap, timer, adj);
        }
    }

    //Print articulation points
    cout<<"Printing all Articulation Points: ";
    for(int i=0; i<n; i++) {
        if(ap[i] != 0) {
            cout<< i <<" ";
        }
    }cout<<endl;
}
