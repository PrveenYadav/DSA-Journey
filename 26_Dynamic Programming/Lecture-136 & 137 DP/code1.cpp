#include <iostream>
#include <vector>
using namespace std;

//Leetcode(72) : Edit Distance (Hard)
/*
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.
You have the following three operations permitted on a word:
Insert a character
Delete a character
Replace a character 
*/

//Simple Approach: check if ch of both string are match then further function call(for remaining str), else perform all 3 operation and return the min(delete, insert, replace)

//Recursion
int solve(string &a, string &b, int i, int j) {
    //base case
    if(i == a.length()) 
        return b.length() - j;
    if(j == b.length())
        return a.length() - i;
    
    int ans = 0;
    if(a[i] == b[j]) {
        return solve(a, b, i+1, j+1);
    }else {
        //insert
        int insertAns = 1 + solve(a, b, i, j+1);
        //delete
        int deleteAns = 1 + solve(a, b, i+1, j);
        //replace
        int replaceAns = 1 + solve(a, b, i+1, j+1);

        ans = min(insertAns, min(deleteAns, replaceAns));
    }
    return ans;
}

int minDistance(string &word1, string &word2) {
    return solve(word1, word2, 0, 0);
}

//Memoization
int solveMem(string &a, string &b, int i, int j, vector<vector<int>> &dp) {
    //base case
    if(i == a.length()) return b.length() - j;
    if(j == b.length()) return a.length() - i;
    
    if(dp[i][j] != -1) return dp[i][j];

    int ans = 0;
    if(a[i] == b[j]) {
        return solveMem(a, b, i+1, j+1, dp);
    }else {
        //insert
        int insertAns = 1 + solveMem(a, b, i, j+1, dp);
        //delete
        int deleteAns = 1 + solveMem(a, b, i+1, j, dp);
        //replace
        int replaceAns = 1 + solveMem(a, b, i+1, j+1, dp);

        ans = min(insertAns, min(deleteAns, replaceAns));
    }
    return dp[i][j] = ans;
}

int minDistanceMem(string &word1, string &word2) {
    vector<vector<int>> dp(word1.length(), vector<int>(word2.length(), -1));
    return solveMem(word1, word2, 0, 0, dp);
}

//Tabulation
int solveTab(string &a, string &b) {
    vector<vector<int>> dp(a.length()+1, vector<int>(b.length()+1, 0));
    //base case
    for(int j=0; j<b.length(); j++) {
        dp[a.length()][j] = b.length() - j;
    }

    for(int i=0; i<a.length(); i++) {
        dp[i][b.length()] = a.length() - i;
    }

    for(int i=a.length()-1; i>=0; i--) {
        for(int j=b.length()-1; j>=0; j--) {
            
            int ans = 0;
            if(a[i] == b[j]) {
                ans = dp[i+1][j+1];
            }else {
                //insert
                int insertAns = 1 + dp[i][j+1];
                //delete
                int deleteAns = 1 + dp[i+1][j];
                //replace
                int replaceAns = 1 + dp[i+1][j+1];

                ans = min(insertAns, min(deleteAns, replaceAns));
            }
            dp[i][j] = ans;
        }
    }
    return dp[0][0];
}

//Space Optimized
int solveOptimized(string &a, string &b) {
    vector<int> curr(b.length() + 1, 0);
    vector<int> next(b.length() + 1, 0);

    // Initialize the base case for `next` (last row)
    for (int j = 0; j <= b.length(); j++) {
        next[j] = b.length() - j;
    }

    for (int i = a.length() - 1; i >= 0; i--) {
        curr[b.length()] = a.length() - i; // Base case for the last column

        for (int j = b.length() - 1; j >= 0; j--) {
            int ans = 0;
            if (a[i] == b[j]) {
                ans = next[j + 1]; // Characters match, no operation needed
            } else {
                // Calculate costs for insert, delete, and replace operations
                int insertAns = 1 + curr[j + 1];
                int deleteAns = 1 + next[j];
                int replaceAns = 1 + next[j + 1];

                ans = min(insertAns, min(deleteAns, replaceAns));
            }
            curr[j] = ans;
        }

        // Move the current row to the next row
        next = curr;
    }

    return next[0];
}

int main() {
    cout<<endl;
    string word1 = "horse";
    string word2 = "ros"; //output = 3 

    cout<<"Min Operations Rec: "<< minDistance(word1, word2) <<endl;
    cout<<"Min Operations Mem: "<< minDistanceMem(word1, word2) <<endl;
    cout<<"Min Operations Tab: "<< solveTab(word1, word2) <<endl;
    cout<<"Min Operations S.O: "<< solveOptimized(word1, word2) <<endl;
    return 0;
}