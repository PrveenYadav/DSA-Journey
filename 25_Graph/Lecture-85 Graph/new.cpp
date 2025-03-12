#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
using namespace std;

//Graph implementation : Revision ---
class Graph{
public:
    //step-1: creating a map for indexes and list
    //step-2: create functions to add edges
    //step-3: function to print adj list/Graph
    //IN main function---
    //Step-1: input number of nodes and Edges
    //step-2: create a graph 
    //step-3: Input every nodes and connecting with Edges by for loop
    //step-4: function call to print graph

    unordered_map<int, list<int>> adj;
     
    void addEdges(int u, int v, bool direction) { //direction for directed(1)/undirected(0) graph

        //creating an edge from u to v
        adj[u].push_back(v);
        if(direction == 0) { //dirction==0 means Undirected graph
            adj[v].push_back(u);
        }
    }

    void printAdjacency() {
        for(auto i : adj) {
            cout<< i.first <<"-> "; //first is key/index
            for(auto j : i.second) { //second is lis/values which is connected from the key/indexes
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
    
    //Input every nodes and connecting with Edges
    for(int i=0; i<m; i++) {
        int u, v;
        cin>>u>>v;
        g.addEdges(u, v, 0); //0 means undirected graph
    }

    cout<<"Printing the Graph/Adjacency: "<<endl;
    g.printAdjacency();

    return 0;
}