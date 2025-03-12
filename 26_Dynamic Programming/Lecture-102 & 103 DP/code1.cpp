#include <iostream>
#include <vector>
using namespace std;

//Minimum cost to climbing stairs : Dynamic Programming

//Basic Recursion : Leetcode 70
int countDistance(int nStairs) {
    if(nStairs < 0) return 0;
    if(nStairs == 0) return 1;

    return countDistance(nStairs-1) + countDistance(nStairs-2);
}

//Basic Recursion : Leetcode 70
int solve(int n, vector<int> &dp) {
        //base case
    if(n < 0) return 0;
    if(n == 0) return 1;

    if(dp[n] != -1) return dp[n];

    dp[n] = solve(n-1, dp) + solve(n-2, dp);
    return dp[n];
}

int climbStairs(int n) {
    vector<int> dp(n+1, -1);
    return solve(n, dp);
}


//Recursion : As the input provided : Time O(n) & Space O(n + n)
int solve(vector<int> &cost, int n) {
    //base case
    if(n == 0) return cost[0];
    if(n == 1) return cost[1];

    int ans = cost[n] + min(solve(cost, n-1), solve(cost, n-2));
    return ans;
}

int minCost(vector<int> &cost) {
    int n = cost.size();
    int ans = min(solve(cost, n-1), solve(cost, n-2));
    return ans;
}

//Memoization : Leetcode 746 : Time O(n) & Space O(n + n)
int solve1(vector<int> &cost, int n, vector<int> &dp) {
    //base case
    if(n == 0) return cost[0];
    if(n == 1) return cost[1];

    //step-3
    if(dp[n] != -1) return dp[n];

    //step-2
    dp[n] = cost[n] + min(solve(cost, n-1), solve(cost, n-2));
    return dp[n];
}

int minCost1(vector<int> &cost) {
    int n = cost.size();
    //step-1
    vector<int> dp(n+1, -1);
    int ans = min(solve1(cost, n-1, dp), solve1(cost, n-2, dp));
    return ans;
}

//Tabulation : Time O(n) & Space O(n)
int minCost2(vector<int> &cost) {
    int n = cost.size();
    //step-1: create dp array
    vector<int> dp(n+1);
    //step-2: Base case initialize
    dp[0] = cost[0];
    dp[1] = cost[1];

    //step-3: cases of 0 & 1 is handled, now loop for the rest cases(2 to n)
    for(int i=2; i<n; i++) {
        dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
    }

    return min(dp[n-1], dp[n-2]);
}

//Space Optimized : Time O(n) & Space O(1)
int minCost3(vector<int> &cost) {
    int n = cost.size();
    
    int prev1 = cost[1]; 
    int prev2 = cost[0];

    for(int i=2; i<n; i++) {
        int curr = cost[i] + min(prev1, prev2);
        prev2 = prev1;
        prev1 = curr;
    }
    return min(prev1, prev2);
}

int main() {

    cout<<"dist for nStairs: "<< countDistance(5) <<endl;
    cout<<"climb stairs: "<< climbStairs(5) <<endl;

    vector<int> cost = {10, 15, 20};
    cout<<"Min cost Recursion: "<< minCost(cost) <<endl;
    cout<<"Min cost Memoization: "<< minCost1(cost) <<endl;
    cout<<"Min cost Tabulation: "<< minCost2(cost) <<endl;
    cout<<"Min cost Space Optimized: "<< minCost3(cost) <<endl;
    return 0;
}