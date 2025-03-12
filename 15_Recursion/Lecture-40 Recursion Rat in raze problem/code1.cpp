#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Helper function for backtracking
void findPaths(vector<vector<int>> &mat, int x, int y, int n, string path, vector<string> &paths, vector<vector<bool>> &visited) {
    
    // Base condition: If destination is reached, add the path to the list of paths
    if (x == n - 1 && y == n - 1) {
        paths.push_back(path);
        return;
    }

    // Mark the current cell as visited
    visited[x][y] = true;

    // Moving Down
    if (x + 1 < n && mat[x + 1][y] == 1 && !visited[x + 1][y]) {
        findPaths(mat, x + 1, y, n, path + "D", paths, visited);
    }

    // Moving Left
    if (y - 1 >= 0 && mat[x][y - 1] == 1 && !visited[x][y - 1]) {
        findPaths(mat, x, y - 1, n, path + "L", paths, visited);
    }

    // Moving Right
    if (y + 1 < n && mat[x][y + 1] == 1 && !visited[x][y + 1]) {
        findPaths(mat, x, y + 1, n, path + "R", paths, visited);
    }

    // Moving Up
    if (x - 1 >= 0 && mat[x - 1][y] == 1 && !visited[x - 1][y]) {
        findPaths(mat, x - 1, y, n, path + "U", paths, visited);
    }

    // Backtrack: Mark the current cell as unvisited
    visited[x][y] = false;
}

// Main function to find all paths from (0,0) to (n-1,n-1)
vector<string> ratInMaze(vector<vector<int>> &mat, int n) {
    vector<string> paths;
    vector<vector<bool>> visited(n, vector<bool>(n, false));

    // Start from (0, 0) if it is not blocked
    if (mat[0][0] == 1) {
        findPaths(mat, 0, 0, n, "", paths, visited);
    }

    // Sort paths lexicographically
    sort(paths.begin(), paths.end());
    return paths;
}

// Example usage
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