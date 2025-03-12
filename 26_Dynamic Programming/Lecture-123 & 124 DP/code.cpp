#include <iostream>
#include <vector>
using namespace std;

//(Pattern)Distinct ways problems: Lecture: 122,123,124
//Leetcode(416): Partition Equal Subset Sum : Divide into two subset with equal sum, for arr[1, 5, 11, 5] = {1, 5, 5}, {11}

//Recursion
bool solve(int index, int N, int arr[], int target) {
    //base case
    if(index >= N) return 0;
    if(target < 0) return 0;
    if(target == 0) return 1;

    bool include = solve(index+1, N, arr, target-arr[index]); //if an elemnent is adding then move forward(index+1) and now new target will be(target-arr[index])
    bool exclude = solve(index +1, N, arr, target-0);

    return include or exclude;
}

int equalPartition(int N, int arr[]) {
    int total = 0;
    for(int i=0; i<N; i++) {
        total += arr[i];
    }
    if(total & 1) return 0; //if sum of array is an odd number then return 0

    int target = total/2; 
    return solve(0, N, arr, target);
}

//Memoization
bool solve1(int index, int N, int arr[], int target, vector<vector<int>> &dp) {
    //base case
    if(index >= N) return 0;
    if(target < 0) return 0;
    if(target == 0) return 1;

    if(dp[index][target] != -1) return dp[index][target];

    bool include = solve1(index+1, N, arr, target-arr[index], dp);
    bool exclude = solve1(index +1, N, arr, target-0, dp);

    return dp[index][target] = include or exclude;
}

int equalPartitionMem(int N, int arr[]) {
    int total = 0;
    for(int i=0; i<N; i++) {
        total += arr[i];
    }
    if(total & 1) return 0;
    int target = total/2; 

    vector<vector<int>> dp(N, vector<int>(target+1, -1));
    return solve1(0, N, arr, target, dp);
}

//Tabulation
bool solveTab(int N, int arr[], int total) {
    vector<vector<int>> dp(N+1, vector<int>(total+1, 0));
    //base case
    for(int i=0; i<=N; i++) {
        dp[i][0] = 1;
    }

    for(int index=N-1; index>=0; index--) {
        for(int target=0; target<=total/2; target++) {
            
            bool include = 0;
            if(target-arr[index] >= 0)
                include = dp[index+1][target-arr[index]];
            bool exclude = dp[index +1][target-0];
            dp[index][target] = include or exclude;
        }
    }
    return dp[0][total/2]; //total/2 means target
}

int equalPartitionTab(int N, int arr[]) {
    int total = 0;
    for(int i=0; i<N; i++) {
        total += arr[i];
    }
    if(total & 1) return 0;
    int target = total/2; 

    return solveTab(N, arr, total);
}

//Space Optimized
bool solveOptimized(int N, int arr[], int total) {
    vector<int> curr(total+1, 0); //it will work even if we'll do it (total/2) instead of total
    vector<int> next(total+1, 0);
    //base case
    curr[0] = 1;
    next[0] = 1;

    for(int index=N-1; index>=0; index--) {
        for(int target=0; target<=total/2; target++) {
            
            bool include = 0;
            if(target-arr[index] >= 0)
                include = next[target-arr[index]];
            bool exclude = next[target-0];
            curr[target] = include or exclude;
        }
        next = curr;
    }
    return next[total/2]; //total/2 = target
}

int equalPartitionOptimized(int N, int arr[]) {
    int total = 0;
    for(int i=0; i<N; i++) {
        total += arr[i];
    }
    if(total & 1) return 0;
    int target = total/2; 

    return solveOptimized(N, arr, total);
}

int main() {
    cout<<endl;
    int arr[] = {1, 5, 11, 5};
    int n = 4;

    cout<<"Equal Partition Rec: "<< equalPartition(n, arr) <<endl;
    cout<<"Equal Partition Mem: "<< equalPartitionMem(n, arr) <<endl;
    cout<<"Equal Partition Tab: "<< equalPartitionTab(n, arr) <<endl;
    cout<<"Equal Partition S.O: "<< equalPartitionOptimized(n, arr) <<endl;
    return 0;
}