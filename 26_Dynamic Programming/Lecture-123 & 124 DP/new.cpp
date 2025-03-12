#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int solveRecursive(int i, bool swapped, vector<int>& A, vector<int>& B) {
    if (i == A.size()) return 0;

    int prevA = swapped ? B[i - 1] : A[i - 1];
    int prevB = swapped ? A[i - 1] : B[i - 1];

    int ans = INT_MAX;

    // Case 1: No Swap
    if (A[i] > prevA && B[i] > prevB) {
        ans = solveRecursive(i + 1, false, A, B);
    }

    // Case 2: Swap
    if (B[i] > prevA && A[i] > prevB) {
        ans = min(ans, 1 + solveRecursive(i + 1, true, A, B));
    }

    return ans;
}

int minSwap(vector<int>& A, vector<int>& B) {
    return solveRecursive(1, false, A, B);
}


int solveMemo(int i, bool swapped, vector<int>& A, vector<int>& B, vector<vector<int>>& dp) {
    if (i == A.size()) return 0;

    if (dp[i][swapped] != -1) return dp[i][swapped];

    int prevA = swapped ? B[i - 1] : A[i - 1];
    int prevB = swapped ? A[i - 1] : B[i - 1];

    int ans = INT_MAX;

    // Case 1: No Swap
    if (A[i] > prevA && B[i] > prevB) {
        ans = solveMemo(i + 1, false, A, B, dp);
    }

    // Case 2: Swap
    if (B[i] > prevA && A[i] > prevB) {
        ans = min(ans, 1 + solveMemo(i + 1, true, A, B, dp));
    }

    return dp[i][swapped] = ans;
}

int minSwapMem(vector<int>& A, vector<int>& B) {
    int n = A.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));
    return solveMemo(1, false, A, B, dp);
}

//Tabulation
int minSwapTab(vector<int>& A, vector<int>& B) {
    int n = A.size();
    vector<vector<int>> dp(n, vector<int>(2, INT_MAX));

    dp[0][0] = 0; // No swap at index 0
    dp[0][1] = 1; // Swap at index 0

    for (int i = 1; i < n; i++) {
        for (int swapped = 0; swapped <= 1; swapped++) {
            int prevA = swapped ? B[i - 1] : A[i - 1];
            int prevB = swapped ? A[i - 1] : B[i - 1];

            // No Swap
            if (A[i] > prevA && B[i] > prevB) {
                dp[i][0] = min(dp[i][0], dp[i - 1][swapped]);
            }

            // Swap
            if (B[i] > prevA && A[i] > prevB) {
                dp[i][1] = min(dp[i][1], dp[i - 1][swapped] + 1);
            }
        }
    }
    return min(dp[n - 1][0], dp[n - 1][1]);
}

//Space Optimized
int minSwapOptimized(vector<int>& A, vector<int>& B) {
    int n = A.size();
    int prevNoSwap = 0, prevSwap = 1;

    for (int i = 1; i < n; i++) {
        int currNoSwap = INT_MAX, currSwap = INT_MAX;

        // No Swap
        if (A[i] > A[i - 1] && B[i] > B[i - 1]) {
            currNoSwap = min(currNoSwap, prevNoSwap);
            currSwap = min(currSwap, prevSwap + 1);
        }

        // Swap
        if (A[i] > B[i - 1] && B[i] > A[i - 1]) {
            currNoSwap = min(currNoSwap, prevSwap);
            currSwap = min(currSwap, prevNoSwap + 1);
        }

        prevNoSwap = currNoSwap;
        prevSwap = currSwap;
    }

    return min(prevNoSwap, prevSwap);
}


int main() {
    cout<<endl;
    vector<int> arr1 = {1, 3, 5, 4};
    vector<int> arr2 = {1, 2, 3, 7};

    cout<<"Min Swap Rec: "<< minSwap(arr1, arr2) <<endl;
    cout<<"Min Swap Mem: "<< minSwapMem(arr1, arr2) <<endl;
    cout<<"Min Swap Tab: "<< minSwapTab(arr1, arr2) <<endl;
    cout<<"Min Swap S.O: "<< minSwapOptimized(arr1, arr2) <<endl;
}