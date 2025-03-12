#include <iostream>
#include <vector>
using namespace std;

// Home-Work => Problem: Rotate Image : Leetcode 48 (medium)

// Problem: Search a 2D Matrix II : Leetcode 240 (medium)
// Time complexity 
// It is not sorted and previous Qs was sorted
bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int row = matrix.size();   
    int col = matrix[0].size();

    int rowIndex = 0;
    int colIndex = col-1;

    while (rowIndex < row && colIndex >= 0) {

        int element = matrix[rowIndex][colIndex]; // [mid/col] = row indes and [mid%col] = col index

        if (element == target)
            return 1;

        if (element < target) {
            rowIndex++;
        }
        else {
           colIndex--;
        }
    }
    return 0;
}

int main(){
    vector<vector<int>> matrix = {
        {1,4,7,11,15},
        {2,5,8,12,19},
        {3,6,9,16,22},
        {10,13,14,17,24},
        {18,21,23,26,30}
    };

    int target = 5;

    cout<<searchMatrix(matrix, target);
    return 0;
}