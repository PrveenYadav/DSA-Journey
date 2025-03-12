#include <iostream>
#include <vector>
using namespace std;

//N Queen Problem : Backtracking
//solve using hashmap approach

void addSolution(vector<vector<int>> &ans, vector<vector<int>> &board, int n) {
    
    vector<int> temp;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            temp.push_back(board[i][j]);
        }
    }

    ans.push_back(temp);
}

bool isSafe(int row, int col, vector<vector<int>> &board, int n) {
    //3 condition given in input: queen doesn't share same row, col and diagonal
    int x = row;
    int y = col;

    //check for same row
    while(y>=0) {
        if(board[x][y] == 1) {
            return false;
        }
        y--;
    }

    x = row, y = col; 
    //check for diagonal
    while(x>=0 && y>=0) {
        if(board[x][y] == 1) {
            return false;
        }
        y--;
        x--;
    }

    x = row, y = col; 
    //check for diagonal
    while(x<n && y>=0) {
        if(board[x][y] == 1) {
            return false;
        }
        y--;
        x++;
    }

    return true;
}

void solve(int col, vector<vector<int>> &ans, vector<vector<int>> &board, int n) {
    //base case
    if(col == n) {
        addSolution(ans, board, n);
        return ;
    }

    //solve 1 case and rest Recursion will take care
    for(int row=0; row<n; row++) {
        if(isSafe(row, col, board, n)) {
            //if placing queeen is safe
            board[row][col] = 1;
            solve(col+1, ans, board, n);
            //backtrack
            board[row][col] = 0; //or false
        }
    }
}

//Time Complexity O(n!) and space O(n*n) 
vector<vector<int>> nQueens(int n) {

    vector<vector<int>> chessBoard(n, vector<int>(n, 0));
    vector<vector<int>> ans;

    solve(0, ans, chessBoard, n);
    return ans;
}

int main() {
    cout<<endl;

    int n = 4;

    vector<vector<int>> ans = nQueens(n);
    cout<<"N Queens Placing: "<<endl;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout<< ans[i][j] <<" ";
        }cout<<endl;
    }cout<<endl;

    return 0;
}