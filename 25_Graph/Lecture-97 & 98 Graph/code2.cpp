#include <iostream>
#include <vector>
using namespace std;

//Bridge in Graph: when a edge removes from a graph then graph disconnects(or Increase the number of connected components in the Graph)
//To solve we need 4 Array: discoveryTime[-1], low[-1], parent[-1], visited[F]