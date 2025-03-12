#include <iostream>
#include <vector> 
#include <queue>
using namespace std;

//Min cost of ropes
int minCost(vector<int> &arr) {
    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i=0; i<arr.size(); i++) {
        pq.push(arr[i]);
    }

    int cost = 0;
    while(pq.size() > 1) {
        int first = pq.top();
        pq.pop();

        int second = pq.top();
        pq.pop();

        int merge = first + second;
        cost = cost + merge;

        pq.push(merge);
    }
    return cost;
}

int main() {
    cout<<endl;
    vector<int> arr = {4, 3, 2, 6};
    //output  = 29

    cout<<"Min Cost: "<< minCost(arr) <<endl;
    return 0;
}