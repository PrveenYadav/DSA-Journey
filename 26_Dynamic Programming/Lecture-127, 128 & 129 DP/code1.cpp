#include <iostream>
#include <vector>
#include <climits>
using namespace std;

//Leetcode(375): Guess Number Higher or Lower II
//Relation: ans = min(ans, 1 + max(f(1, i-1), f(i+1, n)));

//Recursion
int solve(int start, int end) {
    //base case
    if(start >= end) return 0;

    int ans = INT_MAX;
    for(int i=start; i<=end; i++) {
        ans = min(ans, i + max(solve(start, i-1), solve(i+1, end)));
    }
    return ans;
}

int getMoneyAmount(int n) {
    return solve(1, n);
}

//Memoization
int solveMem(int start, int end, vector<vector<int>> &dp) {
    //base case
    if(start >= end) return 0;
    if(dp[start][end] != -1) return dp[start][end];
    
    int ans = INT_MAX;
    for(int i=start; i<=end; i++) {
        ans = min(ans, i + max(solveMem(start, i-1, dp), solveMem(i+1, end, dp)));
    }
    return dp[start][end] = ans;
}

int getMoneyAmountMem(int n) {
    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    return solveMem(1, n, dp);
}

//Tabulation
int solveTab(int n) {
    vector<vector<int>> dp(n+2, vector<int>(n+2, 0));
    
    for(int start=n; start>=1; start--) {
        for(int end=start; end<=n; end++) {

            if(start == end) {
                continue;
            }
            else {
                int ans = INT_MAX;
                for(int i=start; i<=end; i++) {
                    ans = min(ans, i + max(dp[start][i-1], dp[i+1][end]));
                }
                dp[start][end] = ans;
            }
        }
    }
    return dp[1][n];
}

int main() {
    cout<<endl;
    int n = 10; //output = 16

    cout<<"Min Amount Rec: "<< getMoneyAmount(n) <<endl;
    cout<<"Min Amount Mem: "<< getMoneyAmountMem(n) <<endl;
    cout<<"Min Amount Tab: "<< solveTab(n) <<endl;
    return 0;
}