#include <iostream>
#include <vector>
using namespace std;

//Backtracking
//Problem: Rat in a maze

bool isSafe(int newx, int newy, vector<vector<bool>> &visited, vector<vector<int>> &arr, int n) {
    
    if((newx >= 0 && newx < n) && (newy >= 0 && newy < n) && visited[newx][newy] != 1 && arr[newx][newy] == 1) {
        return true;
    }else {
        return false;
    }
}

void solve(int x, int y, vector<vector<int>> &arr, int n, vector<string> &ans, vector<vector<bool>> &visited, string path) {
    //base case
    if(x == n-1 && y == n-1) {
        ans.push_back(path);
        return ;
    }

    //4 movements : D L R U

    visited[x][y] = true;
    
    //Down
    if(isSafe(x+1, y, visited, arr, n)) {
        solve(x+1, y, arr, n, ans, visited, path + 'D');
    }
    
    //Left
    if(isSafe(x, y-1, visited, arr, n)) {
        solve(x, y-1, arr, n, ans, visited, path + 'L');
    }

    //Right
    if(isSafe(x, y+1, visited, arr, n)) {
        solve(x, y+1, arr, n, ans, visited, path + 'R');
    }

    //Up
    if(isSafe(x-1, y, visited, arr, n)) {
        solve(x-1, y, arr, n, ans, visited, path + 'U');
    }
    
    visited[x][y] = false;
}

vector<string> searchMaze(vector<vector<int>> &arr, int n) {
    
    vector<string> ans;
    vector<vector<bool>> visited(n, vector<bool> (n, 0));
    string path = "";

    if(arr[0][0] == 0) return ans;
    solve(0,0, arr, n, ans, visited, path);
    return ans;
}

int main() {
    cout<<endl;

    vector<vector<int>> arr = {
        {1, 0, 0, 0},
        {1, 1, 0, 0},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };
    int n = arr.size();

    cout<<"Rat in a maze path: ";
    vector<string> ans = searchMaze(arr, n);
    for(int i=0; i<n; i++) {
        cout<< ans[i] <<" ";
    }cout<<endl;
    return 0;
}