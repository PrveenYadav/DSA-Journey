#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Largest square formed(area) in a matrix

//Recursion
int solve(vector<vector<int>> &mat, int i, int j) {
    int maxi = 0;
    //base case
    if(i >= mat.size() || j >= mat[0].size()) return 0;

    int right = solve(mat, i+1, j);
    int diognal = solve(mat, i+1, j+1);
    int down = solve(mat, i+1, j);

    if(mat[i][j] == 1) {
        int ans = 1 + min(right, min(diognal, down));
        maxi = max(ans, maxi);
        return ans;
    }else {
        return 0;
    }
    return maxi;
}

int maxSquare(vector<vector<int>>& mat) {
    //base case
    return solve(mat, 0, 0);
}

//Memoization
int maxSquareMem(vector<vector<int>> &mat, int i, int j) {
    int maxi = 0;
    int n = mat.size(), m = 2;
    vector<vector<int>> dp(n, vector<int> (m, -1));

    //base case
    if(i >= mat.size() || j >= mat[0].size()) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    int right = maxSquareMem(mat, i+1, j);
    int diognal = maxSquareMem(mat, i+1, j+1);
    int down = maxSquareMem(mat, i+1, j);

    if(mat[i][j] == 1) {
        dp[i][j] = 1 + min(right, min(diognal, down));
        maxi = max(dp[i][j], maxi);
        return dp[i][j];
    }else {
        return dp[i][j] = 0;
    }
    return maxi;
}

//Tabulation
int maxSquareTab(vector<vector<int>> &mat) {
    int maxi = 0;
    int n = mat.size(); //row
    int m = mat[0].size(); //col
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int i=n-1; i>=0; i--) {
        for(int j=m-1; j>=0; j--) {

            int right = dp[i][j+1];
            int diognal = dp[i+1][j+1];
            int down = dp[i+1][j];

            if(mat[i][j] == 1) {
                dp[i][j] = 1 + min(right, min(diognal, down));
                maxi = max(dp[i][j], maxi);
                return dp[i][j];
            }
            else {
                dp[i][j] = 0;
            }
        }
    }
    return maxi;
}

int largestSquare(vector<vector<int>> &matrix) {
    int rows = matrix.size();
    if (rows == 0) return 0;
    int cols = matrix[0].size();

    // Create a dp matrix to store the size of the largest square ending at each cell
    vector<vector<int>> dp(rows, vector<int>(cols, 0));
    int maxSize = 0; // To store the size of the largest square

    // Fill the dp matrix
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] == 1) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 1; // First row or first column
                } else {
                    dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
                }
                maxSize = max(maxSize, dp[i][j]);
            }
        }
    }

    return maxSize;
}

//All above is taking O(n*m) time and space

//Space Optimized: space O(m)
int maxSquareOptimized(vector<vector<int>> &mat) {
    int maxi = 0;
    int n = mat.size(); //row
    int m = mat[0].size(); //col
    vector<int> curr(m+1, 0);
    vector<int> next(m+1, 0);

    for(int i=n-1; i>=0; i--) {
        for(int j=m-1; j>=0; j--) {

            int right = curr[j+1];
            int diognal = next[j+1];
            int down = next[j];

            if(mat[i][j] == 1) {
                curr[j] = 1 + min(right, min(diognal, down));
                maxi = max(curr[j], maxi);
                return curr[j];
            }else {
                curr[j] = 0;
            }
        }
        next = curr;
    }
    //return next[0];
    //return maxi;
}

//home work: solve in O(1) space 

int main() {
    cout<<endl;

    vector<vector<int>> mat = { //if 0 then square can't make, if 1 then square can make
        {1, 1},
        {1, 1}
    }; //output=2

    int row = mat.size();
    int col = mat[0].size(); //column find ways(**imp**)
    cout<<"Rows: "<< row <<" & Cols: "<< col <<endl;

    cout<<"Max Square-Rec: "<< maxSquare(mat) <<endl;
    cout<<"Max Square-Mem: "<< maxSquareMem(mat, 0, 0) <<endl;
    cout<<"Max Square-Tab: "<< maxSquareTab(mat) <<endl;
    cout<<"Max Square-S.O: "<< maxSquareOptimized(mat) <<endl;
    cout<<"Max Square: "<< largestSquare(mat) <<endl;

    return 0;
}