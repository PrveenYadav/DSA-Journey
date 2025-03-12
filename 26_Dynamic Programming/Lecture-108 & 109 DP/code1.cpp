#include <iostream>
#include <vector>
using namespace std;

//Problem: Painting Fence Algorithm
//Condition: Not more two adjacent post has the same color
//Relation: Solve(n) = solve(n-1)*(k-1) + solve(n-2)*(k-1)

//Recursion
int countWays(int n, int k) { //given number of posts(n) and number of colors(k)
    //base case
    if(n == 1) return k;
    if(n == 2) return k * k;

    return countWays(n-1, k)*(k-1) + countWays(n-2, k)*(k-1); 
}

//Memoization
int countWaysMem(int n, int k) {
    vector<int> dp(n+1, -1);
    //base case
    if(n == 1) return k;
    if(n == 2) return k * k;

    if(dp[n] != -1) return dp[n];

    dp[n] = countWaysMem(n-1, k)*(k-1) + countWaysMem(n-2, k)*(k-1); 
    return dp[n];
}

//Tabulation
int countWaysTab(int n, int k) {
    vector<int> dp(n+1, -1);
    dp[1] = k;
    dp[2] = k*k;

    for(int i=3; i<=n; i++) {
        dp[i] = dp[i-1]*(k-1) + dp[i-2]*(k-1);
    }
    return dp[n];
}

//Space Optimized
int countWaysOptimized(int n, int k) {
    int prev2 = k;
    int prev1 = k*k;
    int ans;

    for(int i=3; i<=n; i++) {
        ans = prev1*(k-1) + prev2*(k-1);
        prev2 = prev1;
        prev1 = ans;
    }
    return ans;
}


//Handle all test-cases
int countWays1(int n, int k) {
    // Space Optimized Approach
    if (n <= 0) return 0;
    if (n == 1) return k;

    int same = k;
    int diff = k * (k - 1);
    int ans;

    for (int i = 3; i <= n; i++) {
        int total = same + diff;
        same = diff;
        diff = total * (k - 1);
    }
    return same + diff;
}

int main() {
    cout<<endl;
    int n = 5, k = 3;
    cout<<"Count Ways-Recursion: "<< countWays(n, k) <<endl;
    cout<<"Count Ways-Memoization: "<< countWaysMem(n, k) <<endl;
    cout<<"Count Ways-Tabulation: "<< countWaysTab(n, k) <<endl;
    cout<<"Count Ways-Optimized: "<< countWaysOptimized(n, k) <<endl;
    cout<<"Count Ways-Optimized-1: "<< countWays1(n, k) <<endl;
    return 0;
}