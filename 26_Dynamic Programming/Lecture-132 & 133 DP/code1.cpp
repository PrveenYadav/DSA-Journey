#include <iostream>
#include <vector>
using namespace std;

//Leetcode(188): Best Time to Buy and Sell Stock IV
//Return the max profit : you may buy at most k times and sell at most k times.

//Recursion
int solve(int index, int operationNo, int k, vector<int> &arr) {
    if(index == arr.size()) return 0;
    if(operationNo == 2*k) return 0;

    int profit = 0;
    if(operationNo % 2 == 0) { //then buy allowed
        int buyKaro = -arr[index] + solve(index+1, operationNo+1, k, arr);
        int skipKaro = 0 + solve(index+1, operationNo, k, arr);
        profit = max(buyKaro, skipKaro);
    }
    else {
        int buyKaro = arr[index] + solve(index+1, operationNo+1, k, arr);
        int sellKaro = 0 + solve(index+1, operationNo, k, arr);
        profit = max(buyKaro, sellKaro);
    }
    return profit;
}

int maxProfit(int k, vector<int> &prices) {
    return solve(0, 0, k, prices);
}

//Memoization
int solveMem(int index, int operationNo, int k, vector<int> &arr) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(2*k, -1));

    if(index == arr.size()) return 0;
    if(operationNo == 2*k) return 0;

    if(dp[index][operationNo] != -1) return dp[index][operationNo];

    int profit = 0;
    if(operationNo % 2 == 0) { //then buy allowed
        int buyKaro = -arr[index] + solveMem(index+1, operationNo+1, k, arr);
        int skipKaro = 0 + solveMem(index+1, operationNo, k, arr);
        profit = max(buyKaro, skipKaro);
    }
    else {
        int buyKaro = arr[index] + solveMem(index+1, operationNo+1, k, arr);
        int sellKaro = 0 + solveMem(index+1, operationNo, k, arr);
        profit = max(buyKaro, sellKaro);
    }
    return dp[index][operationNo] = profit;
}

int maxProfitMem(int k, vector<int> &prices) {
    return solveMem(0, 0, k, prices);
}

//Tabulation
int solveTab(int k, vector<int> &arr) {
    int n = arr.size();
    vector<vector<int>> dp(n+1, vector<int>(2*k+1, 0));

    for(int index=n-1; index>=0; index--) {
        for(int operationNo=0; operationNo<2*k; operationNo++) {
            
            int profit = 0;
            if(operationNo % 2 == 0) { //then buy allowed
                int buyKaro = -arr[index] + dp[index+1][operationNo+1];
                int skipKaro = 0 + dp[index+1][operationNo];
                profit = max(buyKaro, skipKaro);
            }
            else {
                int buyKaro = arr[index] + dp[index+1][operationNo+1];
                int sellKaro = 0 + dp[index+1][operationNo];
                profit = max(buyKaro, sellKaro);
            }
            dp[index][operationNo] = profit;
        }
    }
    return dp[0][0];
}

//Space Optimized
int solveOptimized(int k, vector<int> &arr) {
    int n = arr.size();
    vector<int> curr(2*k+1, 0);
    vector<int> next(2*k+1, 0);

    for(int index=n-1; index>=0; index--) {
        for(int operationNo=0; operationNo<2*k; operationNo++) {
            
            int profit = 0;
            if(operationNo % 2 == 0) { //then buy allowed
                int buyKaro = -arr[index] + next[operationNo+1];
                int skipKaro = 0 + next[operationNo];
                profit = max(buyKaro, skipKaro);
            }
            else {
                int buyKaro = arr[index] + next[operationNo+1];
                int sellKaro = 0 + next[operationNo];
                profit = max(buyKaro, sellKaro);
            }
            curr[operationNo] = profit;
        }
        next = curr;
    }
    return next[0];
}

int main() {
    cout<<endl;
    vector<int> prices = {3, 2, 6, 5, 0, 3};
    int k = 2; //output = 7

    cout<<"Max profit Rec: "<< maxProfit(k, prices) <<endl;
    cout<<"Max profit Mem: "<< maxProfitMem(k, prices) <<endl;
    cout<<"Max profit Tab: "<< solveTab(k, prices) <<endl;
    cout<<"Max profit S.O: "<< solveOptimized(k, prices) <<endl;
    return 0;
}