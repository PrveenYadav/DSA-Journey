#include <iostream>
#include <vector>
using namespace std;

// Problem: Search a 2D Matrix : Leetcode 74 (medium)
// Time complexity O(log n)
// It is sorted Array
bool searchMatrix(vector<vector<int>> &matrix, int target) {

    int row = matrix.size();    //toatal rows
    int col = matrix[0].size(); //toatal cols

    int st = 0;
    int end = (row * col) - 1;

    while (st <= end) {

        int mid = st + (end - st) / 2;
        int element = matrix[mid / col][mid % col]; // [mid/col] = row indes and [mid%col] = col index

        if (element == target)
            return 1;

        if (element < target) {
            st = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    return 0;
}

int main(){
    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target = 3;

    cout<<searchMatrix(matrix, target);
    return 0;
}