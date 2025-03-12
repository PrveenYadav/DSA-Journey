#include <iostream>
#include <climits>
#include <vector>
#include <queue>
using namespace std;

//Shortest path in Undirected Graph : we'll use queue and distance array
vector<int> shortestPath(int src, int N, int M, vector<vector<int>> &edges) {
    vector<vector<int>> adj(N);
    for(auto i : edges) {
        adj[i[0]].push_back(i[1]);
        adj[i[1]].push_back(i[0]);
    }

    int dist[N];
    for(int i=0; i<N; i++) {
        dist[i] = INT_MAX; //1e9 or INT_MAX
    }

    dist[src] = 0;
    queue<int> q;
    q.push(src);

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        for(auto i : adj[node]) {
            if(dist[node] + 1 < dist[i]) {
                dist[i] = dist[node] + 1;
                q.push(i);
            }
        }
    }

    vector<int> ans(N, -1);
    for(int i=0; i<N; i++) {
        if(dist[i] != INT_MAX) {
            ans[i] = dist[i];
        }
    }
    
    return ans;
}

int main() {
    cout<<endl;

    int V = 7, E = 8;
    vector<vector<int>> edges = {{0, 1},{0, 3}, {1, 2}, {1, 3}, {2, 6}, {3, 4}, {4, 5}, {5, 6}};

    vector<int> ans = shortestPath(0, V, E, edges);
    cout<<"Shortest Path: ";
    for(int i=0; i<ans.size(); i++) {
        cout<< ans[i] <<" ";
    }cout<<endl;

    return 0;
}