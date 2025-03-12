#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Problem: Largest increasing subsequence : largest subsequence in increasing order
//Problem: Russian Doll Envelopes

//Recursion
int solve(int n, int arr[], int curr, int prev) {
    //base case
    if(curr == n) return 0;

    //include condition
    int inc = 0; 
    if(prev == -1 || arr[curr] > arr[prev]) { //prev = -1 means, curr is on the first index and not any element included
        inc = 1 + solve(n, arr, curr+1, curr); //prev will update as curr
    }
    //Exclude
    int exc = 0 + solve(n, arr, curr+1, prev);
    
    return max(inc, exc);
}

int subSequence(int n, int a[]) {
    return solve(n, a, 0, -1); //curr index is 0 in starting, include array is -1 in starting
}

//Memoization
int solve1(int n, int arr[], int curr, int prev, vector<vector<int>> &dp) {
    //base case
    if(curr == n) return 0;
    if(dp[curr][prev+1] != -1) return dp[curr][prev];

    int include = 0; 
    if(prev == -1 || arr[curr] > arr[prev]) {
        include = 1 + solve1(n, arr, curr+1, curr, dp);
    }
    int exclude = 0 + solve1(n, arr, curr+1, prev, dp);
    return dp[curr][prev+1] = max(include, exclude); //prev+1 because we intialize with -1 so, to avoid invalid indexes we update it
}

int largestSubsequenceMem(int n, int a[]) {
    vector<vector<int>> dp(n, vector<int>(n+1, -1));
    return solve1(n, a, 0, -1, dp);
}

//Tabulation
int solveTab(int n, int arr[]) {
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    
    for(int curr=n-1; curr>=0; curr--) {
        for(int prev=curr-1; prev>=-1; prev--) {
            int include = 0; 
            if(prev == -1 || arr[curr] > arr[prev]) {
                include = 1 + dp[curr+1][curr+1]; //curr+1 because it can be -1 so to avoid invalide indexes
            }
            int exclude = 0 + dp[curr+1][prev+1]; //same here
            dp[curr][prev+1] = max(include, exclude);
        }
    }
    return dp[0][0];
}

//all prev has time and space complexities of O(n^2)

//Space Optimized: space O(n)
int solveOptimized(int n, int arr[]) {
    vector<int> currRow(n+1, 0);
    vector<int> nextRow(n+1, 0);
    
    for(int curr=n-1; curr>=0; curr--) {
        for(int prev=curr-1; prev>=-1; prev--) {
            int include = 0; 
            if(prev == -1 || arr[curr] > arr[prev]) {
                include = 1 + nextRow[curr+1]; //curr+1 because it can be -1 so to avoid invalide indexes
            }
            int exclude = 0 + nextRow[prev+1]; //same here
            currRow[prev+1] = max(include, exclude);
        }
        nextRow = currRow;
    }
    return nextRow[0];
}


//Binary Search with DP : Time and Space O(nlogn) & O(n)
int solveOptimal(int n, int arr[]) {
    if(n == 0) return 0;
    vector<int> ans;
    ans.push_back(arr[0]);

    for(int i=1; i<n; i++) {
        if(arr[i] > ans.back()) { //back means last element
            ans.push_back(arr[i]);
        }else {
            //find index of just bigger element in ans
            int index = lower_bound(ans.begin(), ans.end(), arr[i]) - ans.begin();
            ans[index] = arr[i];
        }
    }
    return ans.size(); //return length of largest subsequence
} 

int main() {
    cout<<endl;
    int arr[] = {5, 8, 3, 7, 9, 1};
    int n = 6;

    cout<<"Largest subsequence Rec: "<< subSequence(n, arr) <<endl; //we have to return the length of largest subsequence
    cout<<"Largest subsequence Mem: "<< largestSubsequenceMem(n, arr) <<endl;
    cout<<"Largest subsequence Tab: "<< solveTab(n, arr) <<endl;
    cout<<"Largest subsequence S.O: "<< solveOptimized(n, arr) <<endl;
    cout<<"Largest subsequence T.O: "<< solveOptimal(n, arr) <<endl;
    return 0;
}