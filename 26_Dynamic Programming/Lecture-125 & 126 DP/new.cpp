
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm> // For max function
using namespace std;

//Home work do solve: Most imp***Longest increasing subsequence
//Home Work: a + c = 2b  : prev problem, Solve in O(n) space, Above all is in O(n^2) Time & Space

//Longest increasing subsequence
int lengthOfLIS(vector<int>& nums) {
    if (nums.empty()) {
        return 0;
    }

    int n = nums.size();
    vector<int> dp(n, 1); // Initialize DP array with 1s

    // Fill the DP array
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    // Find the maximum value in the DP array
    return *max_element(dp.begin(), dp.end());
}

//longest AP O(n) space : Optimal
int longestArithSeqLength(vector<int>& nums) {
    int n = nums.size();
    if (n <= 2) {
        return n;
    }

    // DP array: dp[i][diff] represents the length of the longest arithmetic subsequence ending at index i with difference 'diff'
    vector<unordered_map<int, int>> dp(n);

    int maxLength = 2; // Minimum length of an arithmetic subsequence is 2

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            int diff = nums[i] - nums[j];

            // Check if the difference exists for the previous index j
            if (dp[j].find(diff) != dp[j].end()) {
                dp[i][diff] = dp[j][diff] + 1;
            } else {
                dp[i][diff] = 2; // Default length for a new arithmetic subsequence
            }

            // Update the maximum length
            maxLength = max(maxLength, dp[i][diff]);
        }
    }

    return maxLength;
}

int main() {
    cout<<endl;
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << "Length of LIS: " << lengthOfLIS(nums) << endl; // Output: 4

    vector<int> nums1 = {3, 6, 9, 12};
    cout << "Length of Longest Arithmetic Subsequence: " << longestArithSeqLength(nums1) << endl; // Output: 4
    return 0;
}