#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Dynamic Programming(DP) on strings (lecture-135,136,137)

//Problem-1: Longest common subsequence(Leetcode: 1143)
//Memoization / Recursion
int solve(string &a, string &b, int i, int j) {
    vector<vector<int>> dp(a.length(), vector<int>(b.length(), -1));
    //base case
    if(i == a.length()) return 0;
    if(j == b.length()) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    int ans = 0;
    if(a[i] == b[j]) {
        //match
        ans = 1 + solve(a, b, i+1, j+1);
    }else {
        //no match
        ans = max(solve(a, b, i+1, j), solve(a, b, i, j+1));
    }
    return dp[i][j] = ans;
}

int LCS(string &text1, string &text2) {
    return solve(text1, text2, 0, 0);
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

//Optimized LCS
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


//Problem-2: Longest palindrome subsequence(Leetcode: 516)
int solvePalindrome(string &word) {
    string revStr = word;
    reverse(revStr.begin(), revStr.end());
    int ans = solveOptimized(word, revStr);
    return ans;
}


//Problem-3: Edit Distance(Leetcode: 72)
//Memoization/Recursion
int solveRec(string &a, string &b, int i, int j) {
    vector<vector<int>> dp(a.length(), vector<int>(b.length(), -1));
    //base case
    if(i == a.length()) return b.length() - j;
    if(j == b.length()) return a.length() - i;

    if(dp[i][j] != -1) return dp[i][j];

    int ans = 0;
    if(a[i] == b[j]) {
        return solveRec(a, b, i+1, j+1);
    }else {
        //insert
        int insertAns = 1 + solve(a, b, i, j+1);
        //delete
        int deleteAns = 1 + solve(a, b, i+1, j);
        //replace ans
        int replaceAns = 1 + solve(a, b, i+1, j+1);

        ans = min(insertAns, min(deleteAns, replaceAns));
    }
    return dp[i][j] = ans;
}

int minDistance(string &a, string &b) {
    return solveRec(a, b, 0, 0);
}

//Tabulation
int minDistanceTab(string &a, string &b) {
    vector<vector<int>> dp(a.length()+1, vector<int>(b.length()+1, 0));
    //base case
    for(int j=0; j<b.length(); j++) {
        dp[a.length()][j] = b.length()-j;
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
                //replace ans
                int replaceAns = 1 + dp[i+1][j+1];

                ans = min(insertAns, min(deleteAns, replaceAns));
            }
            dp[i][j] = ans;
        }
    }
    return dp[0][0];
}

//Space Optimized
int minDistanceOptimized(string &a, string &b) {
    vector<int> curr(b.length()+1, 0);
    vector<int> next(b.length()+1, 0);

    //base case
    for(int j=0; j<b.length(); j++) {
        next[j] = b.length()-j;
    }

    for(int i=a.length()-1; i>=0; i--) {
        //base case
        curr[b.length()] = a.length() - i;

        for(int j=b.length()-1; j>=0; j--) {
            
            int ans = 0;
            if(a[i] == b[j]) {
                return next[j+1];
            }else {
                //insert
                int insertAns = 1 + curr[j+1];
                //delete
                int deleteAns = 1 + next[j];
                //replace ans
                int replaceAns = 1 + next[j+1];

                ans = min(insertAns, min(deleteAns, replaceAns));
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
    string palindrome = "bbbab";

    string str1 = "horse";
    string str2 = "ros";

    cout<<"LCS Mem/Rec: "<< LCS(a, b) <<endl;
    cout<<"LCS Tab: "<< solveTab(a, b) <<endl;
    cout<<"LCS Optimized: "<< solveOptimized(a, b) <<endl;

    cout<<endl<<"Longest palindrome subsequence: "<< solvePalindrome(palindrome) <<endl;

    cout<<endl<<"Min operations Rec/Mem: "<< minDistance(str1, str2) <<endl;
    cout<<"Min operations Tab: "<< minDistanceTab(str1, str2) <<endl;
    cout<<"Min operations Optimized: "<< minDistanceTab(str1, str2) <<endl;
    return 0;
}