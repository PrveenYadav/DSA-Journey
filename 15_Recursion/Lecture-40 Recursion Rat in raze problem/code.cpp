#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Function to check condition that moving is safe or not
bool isSafe(int x, int y, int n, vector<vector<int>> visited, vector<vector<int>> &m) {

    if((x>=0 && x<n) && (y>=0 && y<n) && visited[x][y] == 0 && m[x][y] == 1) {

        return true;
    } else {
        return false;
    }
}

//Function of Recursion to solve the problem 
void solve(vector<vector<int>> &m, int n, vector<string> &ans, int x, int y, vector<vector<int>> visited, string path) {

    //base case : You have reached on x, y here
    if(x == n-1 && y == n-1) {
        ans.push_back(path);
        return ;
    }

    visited[x][y] = 1;

    //Now you have 4 choices to move: D L U R
    //Down
    int newX = x+1, newY = y;
    if(isSafe(newX, newY, n, visited, m)) {
        path.push_back('D');
        solve(m, n, ans, newX, newY, visited, path);

        //backtrack
        path.pop_back();
    }

    //Left
    newX = x, newY = y-1;
    if(isSafe(newX, newY, n, visited, m)) {
        path.push_back('L');
        solve(m, n, ans, newX, newY, visited, path);
        //backtrack
        path.pop_back();
    }

    //Right
    newX = x, newY = y+1;
    if(isSafe(newX, newY, n, visited, m)) {
        path.push_back('R');
        solve(m, n, ans, newX, newY, visited, path);
        //backtrack
        path.pop_back();
    }

    //Up
    newX = x-1, newY = y;
    if(isSafe(newX, newY, n, visited, m)) {
        path.push_back('U');
        solve(m, n, ans, newX, newY, visited, path);
        //backtrack
        path.pop_back();
    }

    visited[x][y] = 1;
}

//Rat in a Maze Problem - I : GeeksForGeeks (medium) : Amazon, Microsoft
vector<string> ratInMaze(vector<vector<int>> &m, int n) {

    vector<string> ans;
    if(m[0][0] == 0) return ans;
    int srcX = 0;
    int srcY = 0;

    vector<vector<int>> visited = m;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            visited[i][j] = 0;
        }
    }

    string path = " ";
    solve(m, n, ans, srcX, srcY, visited, path);
    sort(ans.begin(), ans.end());
    return ans;
}

int main() {

    vector<vector<int>> mat = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };

    int n = mat.size();
    vector<string> result = ratInMaze(mat, n);

    if (result.empty()) {
        cout << "-1";
    } else {
        for (string path : result) {
            cout << path << " ";
        }
    }
    return 0;
}
