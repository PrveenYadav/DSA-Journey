#include <iostream>
#include <vector>
#include <climits>
using namespace std;

//Problem: Cut Rod into segments of x y x : Rod cutting Problem

//Recursion
int solve(int n, int x, int y, int z) {
    //base case
    if(n == 0) return 0;
    if(n < 0) return INT_MIN;

    int a = solve(n-x, x, y, z) + 1;
    int b = solve(n-y, x, y, z) + 1;
    int c = solve(n-z, x, y, z) + 1;

    int ans = max(a, max(b, c));
    return ans;
}

//Memoization
int solveMem(int n, int x, int y, int z, vector<int> &dp) {
    //base case
    if(n == 0) return 0;
    if(n < 0) return INT_MIN;

    if(dp[n] != -1) return dp[n];

    int a = solveMem(n-x, x, y, z, dp) + 1;
    int b = solveMem(n-y, x, y, z, dp) + 1;
    int c = solveMem(n-z, x, y, z, dp) + 1;

    dp[n] = max(a, max(b, c));
    return dp[n];
}

//Tabulation
int solveTab(int n, int x, int y, int z) {
    
    //we can use -1 instead of INT_MIN but then we use a condition in loop that if ... && dp[i-x] != -1 
    vector<int> dp(n+1, INT_MIN); //settling the also INTMIN case by initiallizing INTMIN to array
    dp[0] = 0;

    for(int i=1; i<=n; i++) {
        if(i-x >= 0)
            dp[i] = max(dp[i], dp[i-x] + 1); 

        if(i-y >= 0) 
            dp[i] = max(dp[i], dp[i-y] + 1);
             
        if(i-z >= 0) 
            dp[i] = max(dp[i], dp[i-x] + 1); 
    }

    if(dp[n] < 0) 
        return 0;
    else
        return dp[n];
}

//if we will solve useing Variables(space optimized approach) even then it will take same complexities

int cutSegments(int n, int x, int y, int z) {
    //int ans = solve(n, x, y, z);  //Recursion
    //if(ans < 0) return 0;
    //else return ans;

    vector<int> dp(n+1, -1);
    int ans = solveMem(n, x, y, z, dp); //Memoization
    if(ans < 0) return 0;
    else return ans;
}


//using vector.....
int cutRod(vector<int> &price) {
    int n = price.size();
    vector<int> dp(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            dp[i] = max(dp[i], price[j - 1] + dp[i - j]);
        }
    }
    return dp[n];
}

int main() {
    cout<<endl;

    int rod[] = {5, 3, 2};
    cout<<"Cut rod into segments of: "<< cutSegments(3, 5, 3, 2) <<endl;
    cout<<"Cut rod into segments of: "<< solveTab(3, 5, 3, 2) <<endl;

    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};
    cout<<"Rod cutting: "<< cutRod(price) <<endl;
    return 0;
}