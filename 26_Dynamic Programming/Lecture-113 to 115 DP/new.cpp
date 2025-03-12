#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Recursive approach to find the largest square
int solveRec(vector<vector<int>> &matrix, int i, int j, int &maxSize) {
    if (i < 0 || j < 0) return 0;

    int up = solveRec(matrix, i - 1, j, maxSize);
    int left = solveRec(matrix, i, j - 1, maxSize);
    int diag = solveRec(matrix, i - 1, j - 1, maxSize);

    if (matrix[i][j] == 1) {
        int size = min({up, left, diag}) + 1;
        maxSize = max(maxSize, size);
        return size; //focus here
    }
    return 0;
}

int largestSquareRec(vector<vector<int>> &matrix) {
    int maxSize = 0;
    solveRec(matrix, matrix.size() - 1, matrix[0].size() - 1, maxSize);
    return maxSize; //focus here
}

// Memoization approach
int solveMemo(vector<vector<int>> &matrix, int i, int j, vector<vector<int>> &dp, int &maxSize) {
    if (i < 0 || j < 0) return 0;

    if (dp[i][j] != -1) return dp[i][j];

    int up = solveMemo(matrix, i - 1, j, dp, maxSize);
    int left = solveMemo(matrix, i, j - 1, dp, maxSize);
    int diag = solveMemo(matrix, i - 1, j - 1, dp, maxSize);

    if (matrix[i][j] == 1) {
        dp[i][j] = min({up, left, diag}) + 1;
        maxSize = max(maxSize, dp[i][j]);
        return dp[i][j];
    }
    return dp[i][j] = 0;
}

int largestSquareMemo(vector<vector<int>> &matrix) {
    int rows = matrix.size(), cols = matrix[0].size();
    vector<vector<int>> dp(rows, vector<int>(cols, -1));
    int maxSize = 0;
    solveMemo(matrix, rows - 1, cols - 1, dp, maxSize);
    return maxSize;
}

// Tabulation approach
int largestSquareTab(vector<vector<int>> &matrix) {
    int rows = matrix.size();
    if (rows == 0) return 0;
    int cols = matrix[0].size();

    vector<vector<int>> dp(rows, vector<int>(cols, 0));
    int maxSize = 0;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] == 1) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
                }
                maxSize = max(maxSize, dp[i][j]);
            }
        }
    }

    return maxSize;
}

// Space-optimized approach
int largestSquareSpaceOpt(vector<vector<int>> &matrix) {
    int rows = matrix.size();
    if (rows == 0) return 0;
    int cols = matrix[0].size();

    vector<int> prev(cols, 0), curr(cols, 0);
    int maxSize = 0;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] == 1) {
                if (i == 0 || j == 0) {
                    curr[j] = 1;
                } else {
                    curr[j] = min({prev[j], curr[j - 1], prev[j - 1]}) + 1;
                }
                maxSize = max(maxSize, curr[j]);
            } else {
                curr[j] = 0;
            }
        }
        prev = curr;
    }
    return maxSize;
}

// Example usage
int main() {
    vector<vector<int>> matrix = {
        {1, 0, 1, 0, 0},
        {1, 0, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 0, 0, 1, 0}
    };

    cout << "Largest square using Recursion: " << largestSquareRec(matrix) << endl;
    cout << "Largest square using Memoization: " << largestSquareMemo(matrix) << endl;
    cout << "Largest square using Tabulation: " << largestSquareTab(matrix) << endl;
    cout << "Largest square using Space Optimization: " << largestSquareSpaceOpt(matrix) << endl;

    return 0;
}