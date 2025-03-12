#include <iostream> 
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

//Disjoint set : Kruskal's Algorithm : Minimum spanning tree

bool cmp(vector<int> &a, vector<int> &b) {
    return a[2] < b[2]; 
}

void makeSet(vector<int> &parent, vector<int> &rank, int n) {
    for(int i=0; i<n; i++) {
        //Initilly parent of node is itself and rank is 0
        parent[i] = i;
        rank[i] = 0;
    }
}

int findParent(vector<int> &parent, int node) {
    //when the node is pointing, parent node to itself then stop
    if(parent[node] == node) {
        return node;
    }

    return parent[node] = findParent(parent, parent[node]);
}

void unionSet(int u, int v, vector<int> &parent, vector<int> &rank) {
    u = findParent(parent, u);
    v = findParent(parent, v);

    if(rank[u] < rank[v]) {
        parent[u] = v; //parent change
    }
    else if(rank[v] < rank[u]) {
        parent[v] = u;
    }
    else {
        //change anyone and increse the rank
        parent[v] = u;
        rank[u]++;
    }
}

//Kruskal's Algo : MST
int minSpanningTree(int n, vector<vector<int>> &edges) {

    vector<int> parent(n);
    vector<int> rank(n);
    makeSet(parent, rank, n);
    sort(edges.begin(), edges.end(), cmp);

    int minWeight = 0;
    for(int i=0; i<edges.size(); i++) {
        int u = findParent(parent, edges[i][0]);
        int v = findParent(parent, edges[i][1]);
        int wt = edges[i][2];

        if(u != v) {
            minWeight += wt;
            unionSet(u, v, parent, rank);
        }
    }
    return minWeight;
}

int main() {
    cout<<endl;

    int u = 6, v = 9; //nodes, edges
    // vector<vector<int>> edges = { //wt, u, v
    //     {1, 1, 4}, 
    //     {2, 1, 2}, 
    //     {3, 2, 3}, 
    //     {3, 2, 4}, 
    //     {4, 1, 5}, 
    //     {5, 3, 4}, 
    //     {7, 2, 6}, 
    //     {8, 3, 6}, 
    //     {9, 4, 5} 
    // };

    vector<vector<int>> edges = { //u, v, wt
        {1, 4, 1}, 
        {1, 2, 2}, 
        {1, 5, 4}, 
        {2, 3, 3}, 
        {2, 4, 3}, 
        {2, 6, 7}, 
        {3, 4, 5}, 
        {3, 6, 8}, 
        {4, 5, 9} 
    };

    int n = edges.size(); //here is need edges size not the nodes size
    cout<<"Weight of Min Spanning Tre Kruskal's Algo: ";
    cout<< minSpanningTree(n, edges); //answer-17
    return 0;
}