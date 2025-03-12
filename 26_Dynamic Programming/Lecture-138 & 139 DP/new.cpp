#include <iostream>
#include <vector>
using namespace std;

// Leetcode(44): Wildcard Matching

bool isMatchTab(string &str, string &pattern) {
    vector<vector<bool>> dp(str.length()+1, vector<bool>(pattern.length()+1, false));
    
    // Base case: empty string and empty pattern match
    dp[0][0] = true;
    
    // Initialize the first row (empty string)
    for(int j=1; j<=pattern.length(); j++) {
        if(pattern[j-1] == '*') {
            dp[0][j] = dp[0][j-1];
        } else {
            dp[0][j] = false;
        }
    }
    
    // Fill the DP table
    for(int i=1; i<=str.length(); i++) {
        for(int j=1; j<=pattern.length(); j++) {
            // Match single character or '?'
            if(str[i-1] == pattern[j-1] || pattern[j-1] == '?') {
                dp[i][j] = dp[i-1][j-1];
            }
            // Match '*'
            else if(pattern[j-1] == '*') {
                dp[i][j] = dp[i-1][j] || dp[i][j-1];
            }
            // No match
            else {
                dp[i][j] = false;
            }
        }
    }
    
    return dp[str.length()][pattern.length()];
}

bool isMatchOptimized(string &str, string &pattern) {
    vector<int> prev(pattern.length()+1, 0); 
    vector<int> curr(pattern.length()+1, 0);

    // Base case: empty string and empty pattern match
    prev[0] = true;

    // Initialize the first row (empty string)
    for(int j=1; j<=pattern.length(); j++) {
        if(pattern[j-1] == '*') {
            prev[j] = prev[j-1];
        } else {
            prev[j] = false;
        }
    }

    // Fill the DP table
    for(int i=1; i<=str.length(); i++) {
        // Empty pattern cannot match a non-empty string
        curr[0] = false;

        for(int j=1; j<=pattern.length(); j++) {
            // Match single character or '?'
            if(str[i-1] == pattern[j-1] || pattern[j-1] == '?') {
                curr[j] = prev[j-1];
            }
            // Match '*'
            else if(pattern[j-1] == '*') {
                curr[j] = prev[j] || curr[j-1];
            }
            // No match
            else {
                curr[j] = false;
            }
        }

        // Update prev for the next iteration
        prev = curr;
    }

    return prev[pattern.length()];
}

int main() {
    cout<<endl;
    string str = "abcde";
    string pattern = "a*c?e"; //output true

    cout<<"Wildcard Matching Tab: "<< isMatchTab(str, pattern) <<endl;
    cout<<"Wildcard Matching S.O: "<< isMatchOptimized(str, pattern) <<endl;
    return 0;
}