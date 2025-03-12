#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <set>
using namespace std;

//Dijkstra's Algorithm : Using Priority Queue | Using Set
//Dijkstra's shortest path : Dijkshtra's Algorithm used for calculate shortest path in graph

//Using Priority Queue
void dijkstra(int src, vector<pair<int, int>> adj[], int V) {
    // Create a priority queue to store the vertices(nodes) and their distances
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Distance vector to store the shortest distances from the source
    vector<int> dist(V, INT_MAX);

    // Initialize the source vertex
    dist[src] = 0;
    pq.push({0, src}); // {distance, vertex}

    while (!pq.empty()) {
        // Extract the vertex with the smallest distance
        int distance = pq.top().first; 
        int current = pq.top().second; //pririty queue(min heap) has two things {dist, node}
        pq.pop();

        // Iterate over the adjacent vertices
        for (auto neighbor : adj[current]) {
            int next = neighbor.first;
            int weight = neighbor.second;

            // Relaxation step
            if (dist[current] + weight < dist[next]) {
                dist[next] = dist[current] + weight;
                pq.push({dist[next], next});
            }
        }
    }

    // Print the shortest distances from the source
    cout << "Vertex\tDistance from Source" << endl;
    for (int i = 0; i < V; ++i) {
        cout << i << "\t" << dist[i] << endl;
    }
}

//Using Set
void dijkstra1(int src, vector<pair<int, int>> adj[], int V) {

    set<pair<int, int>> s; //{distance, vertex}

    //Distance vector to store the shortest distances from the source
    vector<int> dist(V, INT_MAX);

    // Initialize the source vertex
    dist[src] = 0;
    s.insert({0, src}); //{distance, vertex}

    while (!s.empty()) {
        // Extract the vertex with the smallest distance
        auto it = s.begin();
        int current = it->second;
        int distance = it->first;
        s.erase(it);

        // Iterate over the adjacent vertices
        for (auto neighbor : adj[current]) {
            int next = neighbor.first;
            int weight = neighbor.second;

            // Relaxation step
            if (dist[current] + weight < dist[next]) {
                // If the vertex is already in the set, remove it
                if (dist[next] != INT_MAX) {
                    s.erase({dist[next], next});
                }

                // Update the distance and insert it into the set
                dist[next] = dist[current] + weight;
                s.insert({dist[next], next});
            }
        }
    }

    // Print the shortest distances from the source
    cout << "Vertex\tDistance from Source" << endl;
    for (int i = 0; i < V; ++i) {
        cout << i << "\t" << dist[i] << endl;
    }
}

int main() {
    // Number of vertices and edges
    int V = 5;

    // Create an adjacency list to represent the graph
    vector<pair<int, int>> adj[V];

    // Define edges (u, v, w) where u and v are vertices, w is the weight
    adj[0].push_back({1, 2});
    adj[0].push_back({2, 4});
    adj[1].push_back({2, 1});
    adj[1].push_back({3, 7});
    adj[2].push_back({4, 3});
    adj[3].push_back({4, 2});

    // Note: If the graph is undirected, add reverse edges too
    adj[1].push_back({0, 2});
    adj[2].push_back({0, 4});
    adj[2].push_back({1, 1});
    adj[3].push_back({1, 7});
    adj[4].push_back({2, 3});
    adj[4].push_back({3, 2});

    // Define source vertex
    int src = 0;

    // Call Dijkstra's algorithm
    dijkstra(src, adj, V);
    dijkstra1(src, adj, V);

    return 0;
}