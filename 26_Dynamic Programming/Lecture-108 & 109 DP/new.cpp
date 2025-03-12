// Painting Fence Problem: All Approaches (Recursion, Memoization, Tabulation, and Space Optimization)
#include <iostream>
#include <vector>
using namespace std;

// Recursion Approach
int paintFenceRec(int n, int k) {
    if (n == 1) return k; // Base case: One fence, k ways to paint
    if (n == 2) return k * k; // Base case: Two fences, k * k ways

    return paintFenceRec(n - 1, k) * (k - 1) + paintFenceRec(n - 2, k) * (k - 1);
}

// Memoization Approach
int paintFenceMemo(int n, int k, vector<int> &dp) {
    if (n == 1) return k;
    if (n == 2) return k * k;
    if (dp[n] != -1) return dp[n];

    dp[n] = paintFenceMemo(n - 1, k, dp) * (k - 1) + paintFenceMemo(n - 2, k, dp) * (k - 1);
    return dp[n];
}

// Tabulation Approach
int paintFenceTab(int n, int k) {
    if (n == 1) return k;
    if (n == 2) return k * k;

    vector<int> dp(n + 1);
    dp[1] = k;
    dp[2] = k * k;

    for (int i = 3; i <= n; ++i) {
        dp[i] = dp[i - 1] * (k - 1) + dp[i - 2] * (k - 1);
    }

    return dp[n];
}

// Space Optimized Approach
int paintFenceSpaceOpt(int n, int k) {
    if (n == 1) return k;
    if (n == 2) return k * k;

    int prev2 = k;         // dp[i-2]
    int prev1 = k * k;     // dp[i-1]

    for (int i = 3; i <= n; ++i) {
        int curr = prev1 * (k - 1) + prev2 * (k - 1);
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

// Example usage
int main() {
    int n = 5; // Number of fences
    int k = 3; // Number of colors

    // Recursion
    cout << "Recursion: " << paintFenceRec(n, k) << endl;

    // Memoization
    vector<int> dp(n + 1, -1);
    cout << "Memoization: " << paintFenceMemo(n, k, dp) << endl;

    // Tabulation
    cout << "Tabulation: " << paintFenceTab(n, k) << endl;

    // Space Optimized
    cout << "Space Optimized: " << paintFenceSpaceOpt(n, k) << endl;

    return 0;
}
