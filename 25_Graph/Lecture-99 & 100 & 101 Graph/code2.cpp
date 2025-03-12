#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <stack>
#include <climits>
using namespace std;

// Bellmon Ford Algorithm : To find shortest path : it can work on negative weight

int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {

    vector<int> distance(n + 1, INT_MAX);
    distance[src] = 0;

    // n-1 times
    for (int i = 1; i <= n; i++) {
        // traverse on all edges
        for (int j = 0; j < m; j++) {
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];

            if (distance[u] != INT_MAX && ((distance[u] + wt) < distance[v])) {
                distance[v] = distance[u] + wt;
            }
        }
    }

    // to check negative cycles
    int flag = 0;
    for (int i = 0; i < m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];

        if (distance[u] != INT_MAX && ((distance[u] + wt) < distance[v])) {
            flag = 1;
        }
    }

    if(flag == 0) return distance[dest];
    return -1;
}

int main() {
    cout<<endl;

    int n = 3, m = 3;
    vector<vector<int>> edges = { //u, v, wt
        {0, 1, 6},
        {0, 2, 5},
        {1, 2, -3}
    };

    int src = 0, dest = 2;
    cout<<"Shortest Path, Bellmon Ford Algo: "<< bellmonFord(n, m, src, dest, edges) <<endl;
    return 0;
}