#include <iostream>
#include <vector>
using namespace std;

//Leetcode(714): Best Time to Buy and Sell Stock with Transaction Fee
//these all 5 quesitions are same but a little bit change is needed

//Space Optimized - Buy and sell stocks 2
int solveOptimized(vector<int> &arr, int fee) {
    int n = arr.size();
    vector<int> curr(2, 0);
    vector<int> next(2, 0);

    for(int index=n-1; index>=0; index--) {
        for(int buy=0; buy<=1; buy++) {
            int profit = 0;
            if(buy) {
                int buyKaro = -arr[index] + next[0];
                int skipKaro = 0 + next[1];
                profit = max(buyKaro, skipKaro);
            }else {
                int sellKaro = arr[index] + next[1] - fee;
                int skipKaro = 0 + next[0];
                profit = max(sellKaro, skipKaro);
            }
            curr[buy] = profit;
        }
        next = curr;
    }
    return next[1];
}

int maxProfit(vector<int>& prices, int fee) {
    return solveOptimized(prices, fee);
}

int main() {
    cout<<endl;
    vector<int> prices = {1, 3, 2, 8, 4, 9};
    int fee = 2; //output = 8

    cout<<"Max Profit after fee: "<< maxProfit(prices, fee) <<endl;
    return 0;
}