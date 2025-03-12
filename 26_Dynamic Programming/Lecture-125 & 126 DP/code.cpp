#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>
using namespace std;

//Leetcode(1027): Longest Arithmetic Subsequence
//Problem: Longest Arithmetic Progression(gfg) : Hashmap + DP
//Arithmetic Progrssion = a, a+d, a+2d, a+3d, ..... an :- where a = first term, d = common difference

//Recursion
int solve(int arr[], int index, int diff) {
    //base case
    if(index < 0) return 0;

    int ans = 0;
    //backward check
    for(int j=index-1; j>=0; j--) {
        if(arr[index]-arr[j] == diff) {
            ans = max(ans, 1 + solve(arr, j, diff));
        }
    }
    return ans;
}

int lengthOfLongestAp(int arr[], int n) {
    //base case
    if(n <= 2) return n;

    int ans = 0;
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            ans = max(ans, 2 + solve(arr, i, arr[j]-arr[i]));
        }
    }
    return ans;
}

//Memoization : Hashmap + DP
int solveMem(int arr[], int index, int diff, unordered_map<int, int> dp[]) {
    //base case
    if(index < 0) return 0;

    if(dp[index].count(diff)) return dp[index][diff];

    int ans = 0;
    //backward check
    for(int j=index-1; j>=0; j--) {
        if(arr[index]-arr[j] == diff) {
            ans = max(ans, 1 + solveMem(arr, j, diff, dp));
        }
    }
    return dp[index][diff] = ans;
}

int lengthOfLongestApMem(int arr[], int n) {
    //base case
    if(n <= 2) return n;

    unordered_map<int, int> dp[n+1]; //(diff, length)
    int ans = 0;

    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            ans = max(ans, 2 + solveMem(arr, i, arr[j]-arr[i], dp));
        }
    }
    return ans;
}

//Tabulation
int solveTab(int arr[], int n) {
    //base case
    if(n <= 2) return n;

    int ans = 0;
    unordered_map<int, int> dp[n+1];

    for(int i=1; i<n; i++) {
        for(int j=0; j<i; j++) {
            int diff = arr[i]-arr[j];
            int cnt = 1;

            //check if answer already present
            if(dp[j].count(diff))
                cnt =  dp[j][diff];
            
            dp[i][diff] = 1 + cnt;
            ans = max(ans, dp[i][diff]);
        }
    }
    return ans;
}



//Home Work: a + c = 2b  : Solve in O(n) space, Above is in O(n^2) Time & Space



int main() {
    cout<<endl;
    //In this array longest AP is: {1, 7, 13, 19} because in {1, 7} or {7, 13} or {13, 19} difference is same(6)
    //return the length of longest AP = 4
    int set[] = {1, 7, 10, 13, 14, 19};
    int n = 6;

    cout<<"Length of Longest AP Rec: "<< lengthOfLongestAp(set, n) <<endl;
    cout<<"Length of Longest AP Mem: "<< lengthOfLongestApMem(set, n) <<endl;
    cout<<"Length of Longest AP Tab: "<< solveTab(set, n) <<endl;
    return 0;
}