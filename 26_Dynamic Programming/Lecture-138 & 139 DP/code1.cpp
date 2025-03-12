#include <iostream>
#include <vector>
#include <climits>
using namespace std;

//Leetcode(44): Wildcard Matching
/*
Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).
*/

//Recursion
bool solve(string &str, string &pattern, int i, int j) {
    //base case
    if(i<0 && j<0) return true;
    if(i>=0 && j<0) return false;
    if(i<0 && j>=0) { //handling that if i is full traversed and j has rest some patterns, so if pattern is star then true if not then false
        for(int k=0; k<=j; k++) {
            if(pattern[k] != '*') {
                return false;
            }
        }
        return true;
    }

    //match
    if(str[i] == pattern[j] || pattern[j] == '?') 
        return solve(str, pattern, i-1, j-1);
    else if(pattern[j] == '*')
        return (solve(str, pattern, i-1, j) || solve(str, pattern, i, j-1));
    else 
        return false;

}

bool isMatch(string s, string p) {
   return solve(s, p, s.length()-1, p.length()-1);    
}

//Memoization
bool solveMem(string &str, string &pattern, int i, int j) {
    vector<vector<int>> dp(str.length(), vector<int>(pattern.length(), -1));
    //base case
    if(i<0 && j<0) return true;
    if(i>=0 && j<0) return false;
    if(i<0 && j>=0) {
        for(int k=0; k<=j; k++) {
            if(pattern[k] != '*') {
                return false;
            }
        }
        return true;
    }

    if(dp[i][j] != -1) return dp[i][j];

    //match
    if(str[i] == pattern[j] || pattern[j] == '?') 
        return dp[i][j] = solveMem(str, pattern, i-1, j-1);
    else if(pattern[j] == '*')
        return dp[i][j] = (solveMem(str, pattern, i-1, j) || solveMem(str, pattern, i, j-1));
    else 
        return false;

}

bool isMatchMem(string s, string p) {
   return solveMem(s, p, s.length()-1, p.length()-1);    
}

//Memoization again on 1 based indexing
bool solveMem1(string &str, string &pattern, int i, int j) {
    vector<vector<int>> dp(str.length()+1, vector<int>(pattern.length()+1, -1));
    //base case
    if(i==0 && j==0) return true;
    if(i>0 && j==0) return false;
    if(i==0 && j>0) {
        for(int k=1; k<=j; k++) {
            if(pattern[k-1] != '*') {
                return false;
            }
        }
        return true;
    }

    if(dp[i][j] != -1) return dp[i][j];

    //match
    if(str[i-1] == pattern[j-1] || pattern[j-1] == '?') 
        return dp[i][j] = solveMem(str, pattern, i-1, j-1);
    else if(pattern[j-1] == '*')
        return dp[i][j] = (solveMem(str, pattern, i-1, j) || solveMem(str, pattern, i, j-1));
    else 
        return false;

}

bool isMatchMem1(string s, string p) {
   return solveMem1(s, p, s.length(), p.length());    
}

//Tabulation
bool isMatchTab(string &str, string &pattern) {
    vector<vector<int>> dp(str.length()+1, vector<int>(pattern.length()+1, 0));
    //base case
    dp[0][0] = true;
    for(int j=1; j<=pattern.length(); j++) {
        bool flag = true;
        for(int k=0; k<=j; k++) {
            if(pattern[k-1] != '*') {
                flag = false;
                break;
            }
        }
        dp[0][j] = flag;
    }

    for(int i=1; i<=str.length(); i++) {
        for(int j=1; j<=pattern.length(); j++) {
            //match
            if(str[i-1] == pattern[j-1] || pattern[j-1] == '?') 
                dp[i][j] = dp[i-1][j-1];
            else if(pattern[j-1] == '*')
                dp[i][j] = (dp[i-1][j] || dp[i][j-1]);
            else 
                dp[i][j] = false;
        }
    }
    return dp[str.length()][pattern.length()];
}

//Space Optimized
bool isMatchOptimized(string &str, string &pattern) {
    vector<int> prev(pattern.length()+1, 0); 
    vector<int> curr(pattern.length()+1, 0);

    //base case
    prev[0] = true;
    for(int j=1; j<=pattern.length(); j++) {
        bool flag = true;
        for(int k=0; k<=j; k++) {
            if(pattern[k-1] != '*') {
                flag = false;
                break;
            }
        }
        prev[j] = flag;
    }

    for(int i=1; i<=str.length(); i++) {
        for(int j=1; j<=pattern.length(); j++) {
            //match
            if(str[i-1] == pattern[j-1] || pattern[j-1] == '?') 
                curr[j] = prev[j-1];
            else if(pattern[j-1] == '*')
                curr[j] = (prev[j] || curr[j-1]);
            else 
                curr[j] = false;
        }
        prev = curr;
    }
    return prev[pattern.length()];
}

int main() {
    cout<<endl;
    string str = "abcde";
    string pattern = "a*c?e"; //output true\

    cout<<"Wildcard Matching Rec: "<< isMatch(str, pattern) <<endl;
    cout<<"Wildcard Matching Mem: "<< isMatchMem(str, pattern) <<endl;
    cout<<"Wildcard Matching Mem1: "<< isMatchMem1(str, pattern) <<endl;
    cout<<"Wildcard Matching Tab: "<< isMatchTab(str, pattern) <<endl;
    cout<<"Wildcard Matching S.O: "<< isMatchOptimized(str, pattern) <<endl;

    // if(isMatchMem1(str, pattern))
    //     cout<<"Matched"<<endl;
    // else
    //     cout<<"Not match"<<endl;
    return 0;
}