#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

//Minimum spanning tree : Prime's Algo | Kruskal's Algo

// Function to calculate the Minimum Spanning Tree (Prim's Algorithm)
void primsMST(vector<pair<int, int>> adj[], int V) {
    // Priority queue to select the edge with the smallest weight
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Array to keep track of visited nodes
    vector<bool> inMST(V, false);

    // Result to store the sum of weights in MST
    int mstWeight = 0;

    // Start from vertex 0
    pq.push({0, 0}); // {weight, vertex}

    while (!pq.empty()) {
        // Extract the minimum weight edge
        int weight = pq.top().first;
        int current = pq.top().second;
        pq.pop();

        // Skip if the vertex is already in the MST
        if (inMST[current]) continue;

        // Mark the vertex as part of the MST
        inMST[current] = true;

        // Add the weight to the total MST weight
        mstWeight += weight;

        // Add all adjacent vertices to the priority queue
        for (auto neighbor : adj[current]) {
            int next = neighbor.first;
            int edgeWeight = neighbor.second;

            if (!inMST[next]) {
                pq.push({edgeWeight, next});
            }
        }
    }

    // Print the total weight of the MST
    cout << "Total weight of the Minimum Spanning Tree: " << mstWeight << endl;
}

//Prime's Algo
//Task to find the sum of weights of the edges of the minimum spanning tree
int spanningTree(int v, vector<vector<int>> adj[]) {
    //Declare min heap or priority queue
    priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;

    vector<int> vis(v, 0);
    pq.push({0, 0}); //{weight, node}
    
    int sum = 0;
    while(!pq.empty()) {
        auto it = pq.top();
        int weight = pq.top().first;
        int node = pq.top().second;

        if(vis[node] == 1) continue;
        //add it to the mst
        vis[node] = 1;
        sum += weight;

        //itarate on all these adjlist
        for(auto i : adj[node]) {
            int adjNode = i[0];
            int edgeWt = i[1];

            if(!vis[adjNode]) {
                pq.push({edgeWt, adjNode});
            }
        }
    }
    return sum;
}

int main() {
    // Number of vertices
    int V = 5;

    // Create an adjacency list to represent the graph
    vector<pair<int, int>> adj[V];

    // Define edges (u, v, w) where u and v are vertices, w is the weight
    adj[0].push_back({1, 2});
    adj[0].push_back({3, 6});
    adj[1].push_back({0, 2});
    adj[1].push_back({2, 3});
    adj[1].push_back({3, 8});
    adj[1].push_back({4, 5});
    adj[2].push_back({1, 3});
    adj[2].push_back({4, 7});
    adj[3].push_back({0, 6});
    adj[3].push_back({1, 8});
    adj[4].push_back({1, 5});
    adj[4].push_back({2, 7});

    // Call Prim's Algorithm to find the MST
    primsMST(adj, V);
    //cout<<"sum is: "<< spanningTree(V, adj) <<endl;
    return 0;
}