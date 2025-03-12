#include <iostream>
#include <vector>
#include <climits>
using namespace std;

//Leetcode(801): Minimum Swaps to make Subsequences Increasing(Hard)
//Swap two array as they follow the increasing order

//Lecture-124: Time 17:25 => Watch carefully to understand  : prev1 and prev2 using for handle this edge case

//Recursion
int solve(vector<int> &num1, vector<int> &num2, int index, bool swapped) {
    //base case
    if(index == num1.size()) return 0;

    int ans = INT_MAX;
    int prev1 = num1[index-1];
    int prev2 = num2[index-1];

    //catch
    if(swapped) {
        swap(prev1, prev2);
    }

    //no swap : if it's already in increasing order then no swap
    if(num1[index] > prev1 && num2[index] > prev2) 
        ans = solve(num1, num2, index+1, 0);

    //swap
    if(num1[index] > prev2 && num2[index] > prev1)
        ans = min(ans, 1 + solve(num1, num2, index+1, 1));

    return ans; 
}

int minSwap(vector<int> &num1, vector<int> &num2) {
    //In the starting we are puting -1 in arrays, because it will work as prev
    num1.insert(num1.begin(), -1);
    num2.insert(num2.begin(), -1);
    //it means that the prev elements were swapped or not
    bool swapped = 0;
    return solve(num1, num2, 1, swapped);
} 

//Memoization
int solveMem(vector<int> &num1, vector<int> &num2, int index, bool swapped, vector<vector<int>> &dp) {
    //base case
    if(index == num1.size()) return 0;

    if(dp[index][swapped] != -1) return dp[index][swapped];

    int ans = INT_MAX;
    int prev1 = num1[index-1];
    int prev2 = num2[index-1];

    //catch
    if(swapped) {
        swap(prev1, prev2);
    }

    //no swap : if it's already in increasing order then no swap
    if(num1[index] > prev1 && num2[index] > prev2) 
        ans = solveMem(num1, num2, index+1, 0, dp);

    //swap
    if(num1[index] > prev2 && num2[index] > prev1)
        ans = min(ans, 1 + solveMem(num1, num2, index+1, 1, dp));

    return dp[index][swapped] = ans; 
}

int minSwapMem(vector<int> &num1, vector<int> &num2) {
    //In the starting we are puting -1 in arrays, because it will work as prev
    num1.insert(num1.begin(), -1);
    num2.insert(num2.begin(), -1);
    //it means that the prev elements were swapped or not
    bool swapped = 0;

    int n = num1.size();
    vector<vector<int>> dp(n, vector<int>(2, -1)); //index is going till n, and swapped has two values only 0 or 1 so: swapped = 2 and index = n
    return solveMem(num1, num2, 1, swapped, dp);
}

//Tabulation
int solveTab(vector<int> &num1, vector<int> &num2) {
    int n = num1.size();
    vector<vector<int>> dp(n+1, vector<int>(2, 0));

    for(int index=n-1; index>=1; index--) {
        for(int swapped=1; swapped>=0; swapped--) {
            
            int ans = INT_MAX;
            int prev1 = num1[index-1];
            int prev2 = num2[index-1];

            //catch
            if(swapped) {
                swap(prev1, prev2);
            }

            //no swap : if it's already in increasing order then no swap
            if(num1[index] > prev1 && num2[index] > prev2) 
                ans = dp[index+1][0];

            //swap
            if(num1[index] > prev2 && num2[index] > prev1)
                ans = min(ans, 1 + dp[index+1][1]);

            dp[index][swapped] = ans; 
        }
    }
    return dp[1][0];
}

//Space Optimized
int solveOptimized(vector<int> &num1, vector<int> &num2) {
    int n = num1.size();
    
    int yesSwap = 0;
    int noSwap = 0;
    int currSwap = 0;
    int currNoSwap = 0;

    for(int index=n-1; index>=1; index--) {
        for(int swapped=1; swapped>=0; swapped--) {
            
            int ans = INT_MAX;
            int prev1 = num1[index-1];
            int prev2 = num2[index-1];

            //catch
            if(swapped) {
                swap(prev1, prev2);
            }

            //no swap : if it's already in increasing order then no swap
            if(num1[index] > prev1 && num2[index] > prev2) 
                ans = noSwap;

            //swap
            if(num1[index] > prev2 && num2[index] > prev1)
                ans = min(ans, 1 + yesSwap);

            //dp[index][swapped] = ans; 
            if(swapped)
                currSwap = ans;
            else 
                currNoSwap = ans;
        }
        yesSwap = currSwap;
        noSwap = currNoSwap;
    }
    return min(yesSwap, noSwap);
}


int main() {
    cout<<endl;

    //in arr1 4(3rd index) is smaller than 5 and not following increasing order so we will swap with 3rd index(7) of arr2
    //then all is clear, now both array will follow incresing order and we swap only 1 number so output = 1
    vector<int> arr1 = {1, 3, 5, 4};
    vector<int> arr2 = {1, 2, 3, 7}; //output = 1

    cout<<"Minimum swap Rec: "<< minSwap(arr1, arr2) <<endl;
    //cout<<"Minimum swap Mem: "<< minSwapMem(arr1, arr2) <<endl;
    cout<<"Minimum swap Tab: "<< solveTab(arr1, arr2) <<endl;
    cout<<"Minimum swap S.O: "<< solveTab(arr1, arr2) <<endl;
    return 0;
}