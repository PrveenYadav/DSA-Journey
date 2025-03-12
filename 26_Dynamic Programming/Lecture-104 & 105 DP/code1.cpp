#include <iostream>
#include <vector>
#include <climits>
using namespace std;

//maximum sum of non adjacent elements

//Recursion
int solve(vector<int> &num, int n) {
    //base case
    if(n < 0) return 0;
    if(n == 0) return num[0];

    int include = solve(num, n-2) + num[n]; //when include then i/n goes 2 steps
    int exclude = solve(num, n-1) + 0;

    return max(include, exclude);
}

int maxSumOfNonAdj(vector<int> &num) {
    int n = num.size();
    int ans = solve(num, n-1);
    return ans;
}

//Memoization
int solveMem(vector<int> &num, int n, vector<int> &dp) {
    //base case
    if(n < 0) return 0;
    if(n == 0) return num[0];

    if(dp[n] != -1) return dp[n];

    int include = solveMem(num, n-2, dp) + num[n];
    int exclude = solveMem(num, n-1, dp) + 0;

    dp[n] = max(include, exclude);
    return dp[n];
}

int maxWithMem(vector<int> &num) {
    int n = num.size();
    vector<int> dp(n, -1);
    return solveMem(num, n-1, dp);
}

//Tabulation
int solveTab(vector<int> &num) {
    int n = num.size();
    vector<int> dp(n, 0);

    dp[0] = num[0];
    dp[1] = max(num[0], num[1]);

    for(int i=2; i<n; i++) {
        int inc = dp[i-2] + num[i];
        int exc = dp[i-1] + 0;
        dp[i] = max(inc, exc);
    }
    //Or: for(int i = 2; i < n; i++) dp[i] = max(dp[i - 2] + num[i], dp[i - 1]); 
    
    return dp[n-1];
}

//Space Optimized
int solve2(vector<int> &num) {
    int n = num.size();
    int prev2 = 0; 
    int prev1 = num[0];

    for(int i=1; i<n; i++) {
        int inc = prev2 + num[i];
        int exc = prev1 + 0;

        int ans = max(inc, exc);
        prev2 = prev1; 
        prev1 = ans;
    }
    return prev1;
}

int main() {
    cout<<endl;

    vector<int> num = {9, 9, 2, 4};

    cout<<"Maximum sum of non-adjacent element: "<< maxSumOfNonAdj(num) <<endl;
    cout<<"Memoization: "<< maxWithMem(num) <<endl;
    cout<<"Tabulation: "<< solveTab(num) <<endl;
    cout<<"Space Optimized: "<< solve2(num) <<endl;
    return 0;
}