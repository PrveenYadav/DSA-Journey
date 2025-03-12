#include <iostream>
#include <vector>
using namespace std;

//Problem: Print like wave
vector<int> wavePrint(vector<vector<int>>& matrix) {

    vector<int> result;
    int rows = matrix.size();

    if (rows == 0) return result;

    int cols = matrix[0].size();

    for (int col = 0; col < cols; col++) {
        // For even-indexed columns, traverse from top to bottom
        if (col % 2 == 0) {
            for (int row = 0; row < rows; row++) {
                result.push_back(matrix[row][col]);
            }
        }
        // For odd-indexed columns, traverse from bottom to top
        else {
            for (int row = rows - 1; row >= 0; row--) {
                result.push_back(matrix[row][col]);
            }
        }
    }
    return result;
}

int main() {
    //vector<vector<int>> arr = {{2}, {3,4}, {1,2,3,4}, {5,6,7,8}, {9,10,11,12},{4,4}, {1,2,4,5}, {3,6,8,10}, {11,12,13,15}, {16,14,9,7}};
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    vector<int> result = wavePrint(matrix);
    
    // Print the result in wave pattern
    cout << "Wave Print: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    
    return 0;
}