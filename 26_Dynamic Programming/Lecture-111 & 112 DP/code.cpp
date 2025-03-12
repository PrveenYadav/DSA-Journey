#include <iostream>
#include <vector>
#include <climits>
using namespace std;

//Problem: Combination sum(1D DP question) : Combination Sum IV(Leetcode-377)

//Recursion
int findWays(vector<int> arr, int target) {
    //base case
    if(target < 0) return 0;
    if(target == 0) return 1;

    int ans = 0;
    for(int i=0; i<arr.size(); i++) {
        ans += findWays(arr, target - arr[i]);
    }
    return ans;
}

//Memoization
int findWaysMem(vector<int> &arr, int tar) {
    vector<int> dp(tar+1, -1);
    //base case
    if(tar < 0) return 0;
    if(tar == 0) return 1;

    if(dp[tar] != -1) return dp[tar];

    int ans = 0;
    for(int i=0; i<arr.size(); i++) {
        if(tar >= arr[i]) {
            ans += findWaysMem(arr, tar - arr[i]);
        }
    }
    dp[tar] = ans;
    return dp[tar];
}

//Combination Sum IV: Memoization Approach
int combinationSum4(vector<int>& nums, int target) {
    vector<int> dp(target + 1, -1);
    if (target == 0) return 1; // Base case: One valid combination found
    if (dp[target] != -1) return dp[target];

    int count = 0;
    for (int num : nums) {
        if (target >= num) {
            count += combinationSum4(nums, target - num);
        }
    }
    dp[target] = count;
    return dp[target];
}

//Tabulation
int findWaysTab(vector<int> &arr, int tar) {
    vector<int> dp(tar+1, 0); //vector<long long> dp(tar+1, 0) to prevent overflow
    dp[0] = 1;

    for(int i=1; i<=tar; i++) { //traversing 1 to tar
        //traversing num vector
        for(int j=0; j<arr.size(); j++) {
            if(i-arr[j] >= 0) {
                dp[i] += dp[i - arr[j]];
            }
        }
    }
    return dp[tar];
}

//All leetcode testcases passes: Tabulation Approach
int combinationSum4Tab(vector<int>& nums, int tar) {
    vector<long long> dp(tar + 1, 0); // Use long long to handle larger values
    dp[0] = 1;

    // Fill the dp array iteratively
    for (int i = 1; i <= tar; ++i) {
        for (int num : nums) {
            if (i - num >= 0) { // Ensure we don't access negative indices
                dp[i] += dp[i - num];

                // Optional: Add overflow handling for further safety
                if (dp[i] > INT_MAX) {
                    dp[i] = INT_MAX; // Clamp to avoid undefined behavior
                }
            }
        }
    }
    return dp[tar];
}

//More space optimization is not possible, dp[i] dependent on i-arr[j] so, we don't know where is the exact location of i-arr[j]

int main() {
    cout<<endl;

    vector<int> arr = {1, 2, 4};
    int tar = 5;
    cout<<"Find ways Rec: "<< findWays(arr, tar) <<endl;
    cout<<"Find ways Mem1: "<< findWaysMem(arr, tar) <<endl;
    cout<<"Find ways Mem2: "<< combinationSum4(arr, tar) <<endl;
    cout<<"Find ways Tab: "<< findWaysTab(arr, tar) <<endl;
    cout<<"Find ways Leetcode: "<< combinationSum4Tab(arr, tar) <<endl;
    return 0;
}