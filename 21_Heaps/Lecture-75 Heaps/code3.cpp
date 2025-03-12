#include <iostream>
#include <queue>
using namespace std;

//Problem: Min cost of Ropes : time complexity O(nlogn) and space O(n)
long long minCost(long long arr[], long long n) {
    //we will create min heap and take two min elements and add both elements and then pop while(size > 1) and finaly add all sum of min elements
    
    //create min heap
    priority_queue<long long, vector<long long>, greater<long long>> pq;

    //all element pushing into heap
    for(int i=0; i<n; i++) {
        pq.push(arr[i]);
    }

    long long cost = 0;
    while(pq.size() > 1) {
        long long a = pq.top();
        pq.pop();
        long long b = pq.top();
        pq.pop();

        long long sum = a+b;
        cost = cost + sum;

        pq.push(sum);
    }
    return cost;
}

int main() {
    cout<<endl;

    long long arr[] = {4, 3, 2, 6};
    long long n = 4;

    //ans would be 29
    long long ans = minCost(arr, n);
    cout<<"Min cost of Ropes: "<< ans <<endl;
    return 0;
}