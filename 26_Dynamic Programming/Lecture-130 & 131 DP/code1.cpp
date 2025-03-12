#include <iostream>
#include <vector>
using namespace std;

//Leetcode(122): Best time to buy and sell stocks 2
// Return the max profit while you can buy multiple times and then sell multiple times 

//Recursion
int solve(vector<int> &arr, int index, int buy) {
    //base case
    if(index == arr.size()) return 0;

    int profit = 0;
    if(buy) {
        int buyKaro = -arr[index] + solve(arr, index+1, 0);
        int skipKaro = 0 + solve(arr, index+1, 1);
        profit = max(buyKaro, skipKaro);
    }else {
        int sellKaro = +arr[index] + solve(arr, index+1, 1);
        int skipKaro = 0 + solve(arr, index+1, 0);
        profit = max(sellKaro, skipKaro);
    }
    return profit;
}

int maxProfit(vector<int> &prices) {
    return solve(prices, 0, 1);
}

//Memoization
int solve1(vector<int> &arr, int index, int buy) {
    int n = arr.size();
    vector<vector<int>> dp(n+1, vector<int>(2, -1));

    //base case
    if(index == n) return 0;
    if(dp[index][buy] != -1) return dp[index][buy];

    int profit = 0;
    if(buy) {
        int buyKaro = -arr[index] + solve1(arr, index+1, 0);
        int skipKaro = 0 + solve1(arr, index+1, 1);
        profit = max(buyKaro, skipKaro);
    }else {
        int sellKaro = +arr[index] + solve1(arr, index+1, 1);
        int skipKaro = 0 + solve1(arr, index+1, 0);
        profit = max(sellKaro, skipKaro);
    }
    return dp[index][buy] = profit;
}

int maxProfitMem(vector<int> &prices) {
    return solve1(prices, 0, 1);
}

//Tabulation
int solveTab(vector<int> &arr) {
    int n = arr.size();
    vector<vector<int>> dp(n+1, vector<int>(2, 0));

    for(int index=n-1; index>=0; index--) {
        for(int buy=0; buy<=1; buy++) {
            int profit = 0;
            if(buy) {
                int buyKaro = -arr[index] + dp[index+1][0];
                int skipKaro = 0 + dp[index+1][1];
                profit = max(buyKaro, skipKaro);
            }else {
                int sellKaro = arr[index] + dp[index+1][1];
                int skipKaro = 0 + dp[index+1][0];
                profit = max(sellKaro, skipKaro);
            }
            dp[index][buy] = profit;
        }
    }
    return dp[0][1];
}

//Space Optimized
int solveOptimized(vector<int> &arr) {
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
                int sellKaro = arr[index] + next[1];
                int skipKaro = 0 + next[0];
                profit = max(sellKaro, skipKaro);
            }
            curr[buy] = profit;
        }
        next = curr;
    }
    return next[1];
}

int main() {
    cout<<endl;
    vector<int> prices = {7, 1, 5, 3, 6, 4}; //output = 7

    cout<<"Maximum Profit Rec: "<< maxProfit(prices) <<endl;
    cout<<"Maximum Profit Mem: "<< maxProfitMem(prices) <<endl;
    cout<<"Maximum Profit Tab: "<< solveTab(prices) <<endl;
    cout<<"Maximum Profit S.O: "<< solveOptimized(prices) <<endl;
    return 0;
}