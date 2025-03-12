#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <set>
using namespace std;

//Dijkstra's Algo shortest path using priority queue
vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
    int V = adj.size(); // Number of vertices in the graph

    // Distance vector to store the shortest distance from src
    vector<int> dist(V, INT_MAX);

    // Priority queue to store {distance, vertex}
    // Min-Heap ensures the vertex with the smallest distance is processed first
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Initialize source vertex
    dist[src] = 0;
    pq.push({0, src}); // {distance, vertex}

    while (!pq.empty()) {
        // Extract the vertex with the smallest distance
        int currentDistance = pq.top().first;
        int currentVertex = pq.top().second;
        pq.pop();

        // Traverse the neighbors of the current vertex
        for (auto neighbor : adj[currentVertex]) {
            int nextVertex = neighbor.first;
            int edgeWeight = neighbor.second;

            // Relaxation step
            if (currentDistance + edgeWeight < dist[nextVertex]) {
                dist[nextVertex] = currentDistance + edgeWeight;
                pq.push({dist[nextVertex], nextVertex});
            }
        }
    }
    return dist;
}

//Dijkstra's Algo using set
vector<int> dijkstra1(vector<vector<pair<int, int>>> &adj, int src) {
    int V = adj.size(); // Number of vertices in the graph

    // Distance vector to store the shortest distance from src
    vector<int> dist(V, INT_MAX);

    // Set to store pairs {distance, vertex}
    set<pair<int, int>> s;

    // Initialize source vertex
    dist[src] = 0;
    s.insert({0, src}); // {distance, vertex}

    while (!s.empty()) {
        // Extract the vertex with the smallest distance
        auto it = s.begin();
        int currentDistance = it->first;
        int currentVertex = it->second;
        s.erase(it);

        // Traverse the neighbors of the current vertex
        for (auto neighbor : adj[currentVertex]) {
            int nextVertex = neighbor.first;
            int edgeWeight = neighbor.second;

            // Relaxation step
            if (currentDistance + edgeWeight < dist[nextVertex]) {
                // If the vertex is already in the set, remove it
                auto found = s.find({dist[nextVertex], nextVertex});
                if (found != s.end()) {
                    s.erase(found);
                }

                // Update distance and insert the updated pair into the set
                dist[nextVertex] = currentDistance + edgeWeight;
                s.insert({dist[nextVertex], nextVertex});
            }
        }
    }

    // Return the distance array
    return dist;
}

int main() {

    vector<vector<pair<int, int>>> adj = {
        {{1, 9}}, // Node 0 -> Node 1 with weight 9
        {{0, 9}}  // Node 1 -> Node 0 with weight 9
    };

    int src = 0;
    vector<int> result = dijkstra(adj, src);
    vector<int> result1 = dijkstra1(adj, src);
    for (int i = 0; i < result.size(); ++i) {
        cout << "(Using PQ)Distance from " << src << " to " << i << ": " << result[i] << endl;
        cout<< "(Using set)Distance from " << src << " to " << i << ": " << result1[i] << endl;
    }

    return 0;
}
