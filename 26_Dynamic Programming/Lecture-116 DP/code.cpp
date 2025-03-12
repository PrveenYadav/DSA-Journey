#include <iostream>
#include <vector>
#include <climits>
using namespace std;

//Leetcode(1039): Minimum Score Triangulation of Polygon(shape)
//you have to see how many triangle can make in a polygan with their vertex(values on corner), then you have to multiply val and give ans of min value's triangle
//Return the minimum possible score that you can achieve with some triangulation of the polygon.

//Recursoin
int solve(vector<int> &val, int i, int j) {
    //base case
    if(i+1 == j) return 0;

    int ans = INT_MAX;
    for(int k=i+1; k<j; k++) {
        int temp = val[i]*val[j]*val[k] + solve(val, i, k) + solve(val, k, j);
        ans = min(ans, temp);
    }
    return ans;
}

int minScore(vector<int> &values) {
    int n = values.size();
    return solve(values, 0, n-1);
}

//Memoization
int solve1(vector<int> &val, int i, int j, vector<vector<int>> &dp) {
    //base case
    if(i+1 == j) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    int ans = INT_MAX;
    for(int k=i+1; k<j; k++) {
        dp[i][j] = val[i]*val[j]*val[k] + solve1(val, i, k, dp) + solve1(val, k, j, dp);
        ans = min(ans, dp[i][j]);
    }
    dp[i][j] = ans;
    return dp[i][j];
}

int minScoreMem(vector<int> &values) {
    int n = values.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return solve1(values, 0, n-1, dp);
}

//Tabulation
int minScoreTab(vector<int> &val) {
    int n = val.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for(int i=n-1; i>=0; i--) {
        for(int j=i+2; j<n; j++) {
            
            int ans = INT_MAX;
            for(int k=i+1; k<j; k++) {
                ans = min(ans, val[i]*val[j]*val[k] + dp[i][k] + dp[k][j]);
            }
            dp[i][j] = ans;
        }
    }
    return dp[0][n-1];
}

//Time & Space Complexities = O(n^3) and O(n^2)

int main() {
    cout<<endl;

    vector<int> values = {1,2,3}; //ans=6

    cout<<"Min Score Rec: "<< minScore(values) <<endl;
    cout<<"Min Score Mem: "<< minScoreMem(values) <<endl;
    cout<<"Min Score Tab: "<< minScoreTab(values) <<endl;
    return 0;
}