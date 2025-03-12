#include <iostream>
#include <vector>
using namespace std;

//Leetcode(121): Best time to buy and sell stocks
// Returning the max profit while you have to only one time buy and then sell 

int maxProfit(vector<int> &arr) {
    int maxProfit = 0;
    int mini = arr[0];

    for(int i=1; i<arr.size(); i++) {
        if(arr[i] > mini) {
            maxProfit = max(maxProfit, arr[i] - mini);
        }
        mini = min(mini, arr[i]);
    }
    return maxProfit;
}

int main() {
    cout<<endl;
    vector<int> prices = {7, 1, 5, 3, 6, 4}; //output = 5

    cout<<"Maximum Profit is: "<< maxProfit(prices) <<endl;
    return 0;
}