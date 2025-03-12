#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Kruskal's Algorithm : Disjoint set
//convert into vector from array
int spanningTree1(int V, vector<vector<int>> adj[]) {

    vector<pair<int, pair<int, int>>> edges;
    for(auto i=0; i<V; i++) {
        for(auto it : adj[i]) {
            int adjNode = it[0];
            int wt = it[1];
            int node = i;

            edges.push_back({wt, {node, adjNode}});
        }
    }

    sort(edges.begin(), edges.end());
    int mstWt = 0;

    for(auto it : edges) {
        int wt = it.first;
        int u = it.second.first;
        int v = it.second.second;

//there is the use of "Disjoint set data structure, so go and study this then solve the problem"
        // if(ds.findUPar(u) != ds.findUPar(v)) {
        //     mstWt == wt;
        //     ds.unionBySize(u, v);
        // }
    }
    return mstWt;
}

int main() {
    cout<<endl;

    int u = 6, v = 9; //nodes, edges
    vector<vector<int>> edges = { //wt, u, v
        {1, 1, 4}, 
        {2, 1, 2}, 
        {3, 2, 3}, 
        {3, 2, 4}, 
        {4, 1, 5}, 
        {5, 3, 4}, 
        {7, 2, 6}, 
        {8, 3, 6}, 
        {9, 4, 5} 
    };

    int n = edges.size(); //here is need edges size not the nodes size
    cout<<"Weight of Min Spanning Tre Kruskal's Algo: ";
    //cout<< spanningTree1(n, edges); //answer-17
    return 0;
}