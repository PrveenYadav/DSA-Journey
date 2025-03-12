#include <iostream>
#include <vector>
using namespace std;

//Leetcode(123): Best Time to Buy and Sell Stock III
// Return the max profit while you have to do at most 2 transaction

//Recursion
int solve(vector<int> &arr, int index, int buy, int limit) {
    //base case
    if(index == arr.size()) return 0;
    if(limit == 0) return 0;

    int profit = 0;
    if(buy) {
        int buyKaro = -arr[index] + solve(arr, index+1, 0, limit);
        int skipKaro = 0 + solve(arr, index+1, 1, limit);
        profit = max(buyKaro, skipKaro);
    }else {
        int sellKaro = +arr[index] + solve(arr, index+1, 1, limit-1);
        int skipKaro = 0 + solve(arr, index+1, 0, limit);
        profit = max(sellKaro, skipKaro);
    }
    return profit;
}

int maxProfit(vector<int> &prices) {
    return solve(prices, 0, 1, 2);
}

//Memoization + creating the 3D DP
int solveMem(vector<int> &arr, int index, int buy, int limit) {
    int n = arr.size();
    //Creating 3D DP
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1))); //n=index, 2=buy, limit=3
    //base case
    if(index == n) return 0;
    if(limit == 0) return 0;
    if(dp[index][buy][limit] != -1) return dp[index][buy][limit];

    int profit = 0;
    if(buy) {
        int buyKaro = -arr[index] + solveMem(arr, index+1, 0, limit);
        int skipKaro = 0 + solveMem(arr, index+1, 1, limit);
        profit = max(buyKaro, skipKaro);
    }else {
        int sellKaro = +arr[index] + solveMem(arr, index+1, 1, limit-1);
        int skipKaro = 0 + solveMem(arr, index+1, 0, limit);
        profit = max(sellKaro, skipKaro);
    }
    return dp[index][buy][limit] = profit;
}

int maxProfitMem(vector<int> &prices) {
    return solveMem(prices, 0, 1, 2);
}

//Tabulation
int solveTab(vector<int> &arr) {
    int n = arr.size();
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));

    for(int index=n-1; index>=0; index--) {
        for(int buy=0; buy<=1; buy++) {
            for(int limit=1; limit<=2; limit++) {
                
                int profit = 0;
                if(buy) {
                    int buyKaro = -arr[index] + dp[index+1][0][limit];
                    int skipKaro = 0 + dp[index+1][1][limit];
                    profit = max(buyKaro, skipKaro);
                }else {
                    int sellKaro = arr[index] + dp[index+1][1][limit-1];
                    int skipKaro = 0 + dp[index+1][0][limit];
                    profit = max(sellKaro, skipKaro);
                }
                dp[index][buy][limit] = profit;
            }
        }
    }
    return dp[0][1][2];
}

//Space Optimized
int solveOptimized(vector<int> &arr) {
    int n = arr.size();
    vector<vector<int>> next(2, vector<int>(3, 0));
    vector<vector<int>> curr(2, vector<int>(3, 0));

    for(int index=n-1; index>=0; index--) {
        for(int buy=0; buy<=1; buy++) {
            for(int limit=1; limit<=2; limit++) {
                
                int profit = 0;
                if(buy) {
                    int buyKaro = -arr[index] + next[0][limit];
                    int skipKaro = 0 + next[1][limit];
                    profit = max(buyKaro, skipKaro);
                }else {
                    int sellKaro = arr[index] + next[1][limit-1];
                    int skipKaro = 0 + next[0][limit];
                    profit = max(sellKaro, skipKaro);
                }
                curr[buy][limit] = profit;
            }
            next = curr;
        }
    }
    return next[1][2];
}

int main() {
    cout<<endl;
    vector<int> prices {3, 3, 5, 0, 0, 3, 1, 4}; //output = 6

    cout<<"Max Profit Rec: "<< maxProfit(prices) <<endl;
    cout<<"Max Profit Mem: "<< maxProfitMem(prices) <<endl;
    cout<<"Max Profit Tab: "<< solveTab(prices) <<endl;
    cout<<"Max Profit S.O: "<< solveOptimized(prices) <<endl;
    return 0;
}