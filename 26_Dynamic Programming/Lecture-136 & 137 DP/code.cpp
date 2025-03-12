#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//palindrome means = bab is palindrom because left->right or right->left the word is still same
//Leetcode(516): Longest palindrome subsequence
//APProach: if we extract the reverse string of given string then we have 2 string(str, rev str) then the LCS of both str will be the longest palindrome subsequence

//Space Optimized code of Longest common subsequence(LCS)
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

int longestPalindromeSubseq(string s) {
    string revStr = s;
    reverse(revStr.begin(), revStr.end());
    int ans = solveOptimized(s, revStr);   
    return ans;
}

int main() {
    cout<<endl;
    string s = "bbbab";

    cout<<"Length of Longest Palindrom Subsequence: "<< longestPalindromeSubseq(s) <<endl;
    return 0;
}