#include <iostream>
#include <vector>
using namespace std;

// Spiral Matrix : Leetcode 54 (Medium)
vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    vector<int> result;
    if (matrix.empty()) return result;

    int top = 0;                      // starting row
    int bottom = matrix.size() - 1;   // ending row
    int left = 0;                     // starting col
    int right = matrix[0].size() - 1; // ending col

    while (top <= bottom && left <= right) {

        // Printing starting row
        for (int i = left; i <= right; i++) {
            result.push_back(matrix[top][i]);
        }
        top++;

        // Printing ending col
        for (int i = top; i <= bottom; i++) {
            result.push_back(matrix[i][right]);
        }
        right--;

        // Printing ending row
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                result.push_back(matrix[bottom][i]);
            }
            bottom--;
        }

        // Printing starting col
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                result.push_back(matrix[i][left]);
            }
            left++;
        }
    }
    return result;
}

int main()
{
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    vector<int> result = spiralOrder(matrix);

    // Print the result
    cout << "Spiral Order: ";

    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}