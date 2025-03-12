#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

//Graph Implementation : Explore " template <typename> t "

class Graph {
public:
    unordered_map<int, list<int>> adj;

    void addEdges(int u, int v, bool direction) {
        //direction = 0 -> undirected graph
        //direction = 1 -> directed graph

        //create an edge from u to v
        adj[u].push_back(v);
        if(direction == 0) { //if undirected graph then u-v and v-u
            adj[v].push_back(u);
        }
    }

    void printAdjList() {
        for(auto i : adj) {
            cout<< i.first <<"-> ";
            for(auto j : i.second) {
                cout<< j <<", ";
            }
            cout<<endl;
        }
    }
};

int main() {
    cout<<endl;

    int n;
    cout<<"Enter the number of Nodes: ";
    cin>>n;

    int m;
    cout<<"Enter the number of Edges: ";
    cin>>m;

    Graph g;

    for(int i=0; i<m; i++) {
        int u, v;
        cin>>u>>v;
        //creating an undirected graph
        g.addEdges(u, v, 0);
    }

    //printing graph
    cout<<"Printing Graph: "<<endl;
    g.printAdjList();

/* Input
0 1
1 2
2 3
3 1
3 4
0 4
*/
    return 0;
}