#include <iostream>
#include <vector>
using namespace std;

//Suduko solver backtracking : and then Graph
//NOTE: ---Deeply **understand because these problems are **most ***important----

bool isSafe(int row, int col, vector<vector<int>> &board, int val) {
    
    for(int i=0; i<board.size(); i++) {
        //row check
        if(board[row][i] == val) {
            return false;
        }

        //col check
        if(board[i][col] == val) {
            return false;
        }

        //3*3 matrix check
        if(board[3*(row/3) + i/3][3*(col/3) + i%3] == val) { //this formula use for 3*3 matrix check fully
            return false;
        }
    }

    return true;
}

bool solve(vector<vector<int>> &board) {
    int n = board[0].size();

    for(int row=0; row<n; row++) {
        for(int col=0; col<n; col++) {
            
            //cell empty
            if(board[row][col] == 0) {
                for(int val=1; val<=9; val++) {
                    if(isSafe(row, col, board, val)) {
                        board[row][col] = val;

                        //Recursive call
                        bool isFurtherSolutionPossible = solve(board);
                        if(isFurtherSolutionPossible) {
                            return true;
                        }else {
                            //backtrack
                            board[row][col] = 0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
} 

void solveSudoku(vector<vector<int>> &sudoku) {  
    solve(sudoku);
}

int main() {
    cout<<endl;

    //9*9 Matrix and has 9 matrix of 3*3 : 0 means empty cell : Condition is 1-9 number can be in a row/col/3*3 matrix
    vector<vector<int>> sudoku = {

        {3, 0, 6, 5, 7, 8, 0, 9, 2},
        {5, 2, 9, 1, 3, 4, 7, 6, 8},
        {4, 8, 0, 6, 2, 9, 5, 3, 1},
        {2, 6, 3, 4, 1, 5, 9, 8, 7},
        {9, 7, 4, 8, 6, 3, 1, 2, 5},
        {8, 5, 1, 7, 9, 2, 6, 4, 3},
        {1, 3, 8, 9, 4, 7, 2, 5, 6},
        {6, 9, 2, 3, 5, 0, 8, 7, 4},
        {7, 4, 5, 2, 8, 6, 3, 1, 9}
    };
    int n = sudoku.size();

    cout<<"Sudoku solver: "<<endl;
    solveSudoku(sudoku);

    return 0;
}