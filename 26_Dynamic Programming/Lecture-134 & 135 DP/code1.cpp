#include <iostream>
#include <vector>
using namespace std;

//Leetcode(1143): Longest common subsequence : DP on String(Lecture - 135, 136, 137)
//Return the length of longest common subseqeuence(common letters) between given two strings

//Recursion
int solve(string &a, string &b, int i, int j) { //we are taking i(to traverse on string a) and j(on string b)
    //base case
    if(i == a.length()) return 0;
    if(i == b.length()) return 0;

    int ans = 0;
    if(a[i] == b[j]) {
        ans = 1 + solve(a, b, i+1, j+1);
    }else {
        ans = max(solve(a, b, i+1, j), solve(a, b, i, j+1));
    }
    return ans;
}

int longestSubsequence(string &text1, string &text2) {
    return solve(text1, text2, 0, 0);
}

//Memoization
int solveMem(string &a, string &b, int i, int j, vector<vector<int>> &dp) { 
    //base case
    if(i == a.length()) return 0;
    if(i == b.length()) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    int ans = 0;
    if(a[i] == b[j]) {
        ans = 1 + solveMem(a, b, i+1, j+1, dp);
    }else {
        ans = max(solveMem(a, b, i+1, j, dp), solveMem(a, b, i, j+1, dp));
    }
    return dp[i][j] = ans;
}

int longestSubsequenceMem(string &text1, string &text2) {
    vector<vector<int>> dp(text1.length(), vector<int>(text2.length(), -1));
    return solveMem(text1, text2, 0, 0, dp);
}

//Tabulation
int solveTab(string &a, string &b) {
    vector<vector<int>> dp(a.length()+1, vector<int>(b.length()+1, 0));

    for(int i=a.length()-1; i>=0; i--) {
        for(int j=b.length()-1; j>=0; j--) {
            
            int ans = 0;
            if(a[i] == b[j]) {
                ans = 1 + dp[i+1][j+1];
            }else {
                ans = max(dp[i+1][j], dp[i][j+1]);
            }
            dp[i][j] = ans;
        }
    }
    return dp[0][0];
}

//Space Optimized
int solveOptimized(string &a, string &b) {

    vector<int> curr(b.length()+1, 0);
    vector<int> next(b.length()+1, 0);

    for(int i=a.length()-1; i>=0; i--) {
        for(int j=b.length()-1; j>=0; j--) {
            
            int ans = 0;
            if(a[i] == b[j]) {
                ans = 1 + next[j+1];
            }else {
                ans = max(next[j], curr[j+1]);
            }
            curr[j] = ans;
        }
        next = curr;
    }
    return next[0];
}

int main() {
    cout<<endl;
    string a = "abcde";
    string b = "ace";

    cout<<"Length of Longest Common Subsequence Rec: "<< longestSubsequence(a, b) <<endl;
    cout<<"Length of Longest Common Subsequence Mem: "<< longestSubsequenceMem(a, b) <<endl;
    cout<<"Length of Longest Common Subsequence Tab: "<< solveTab(a, b) <<endl;
    cout<<"Length of Longest Common Subsequence S.O: "<< solveOptimized(a, b) <<endl;
    return 0;
}