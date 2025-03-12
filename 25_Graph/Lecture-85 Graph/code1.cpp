#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
using namespace std;

//creating and printing graph : vector used
vector<vector<int>> printAdjacency(int n, int m, vector<vector<int>> &edges) {
    
    vector<int> ans[n];
    //ans array will store all adjacent nodes correspending on index
    for(int i=0; i<m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        ans[u].push_back(v);
        ans[v].push_back(u);
    }

    vector<vector<int>> adj(n);
    for(int i=0; i<n; i++) {
        adj[i].push_back(i);

        //entering neighbour
        for(int j=0; j<ans[i].size(); j++) {
            adj[i].push_back(ans[i][j]);
        }
    }

    return adj;
}

int main() {
    cout<<endl;
    
    vector<vector<int>> edges = {
        {0, 1},
        {1, 2},
        {2, 3},
        {3, 1},
        {3, 4},
        {0, 4}
    };

    int n = 5;
    int m = 6;
    
    
    cout<<"Printing Adjacency: "<<endl;
    vector<vector<int>> ans = printAdjacency(n, m, edges);
    for(auto i : ans) {
        for(auto j : i) {
            cout<< j <<" ";
        }
        cout<<endl;
    }

    return 0;
}