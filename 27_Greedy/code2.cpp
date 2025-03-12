#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Problem: Shop in candy store
//Time and space : O(nlogn) and O(1)

vector<int> candyStore(int candies[], int N, int K) {
    
    sort(candies, candies+N);

    int minAns = 0;
    int buy = 0;
    int free = N-1;

    while(buy <= free) {
        minAns = minAns + candies[buy];
        buy++;
        free = free - K;
    }

    int maxAns = 0;
    buy = N-1;
    free = 0;

    while(free <= buy) {
        maxAns = maxAns + candies[buy];
        buy--;
        free = free + K;
    }

    vector<int> ans;
    ans.push_back(minAns);
    ans.push_back(maxAns);
    return ans;
}

int main() {
    cout<<endl;
    int candies[] = {3, 2, 1, 4};
    int n = 4, k = 2;

    vector<int> ans = candyStore(candies, n, k);
    for(int i=0; i<k; i++) {
        cout<< ans[i] <<" ";
    }cout<<endl;
    return 0;
}