#include <iostream>
#include <vector>
#include <map>
#include <climits>
using namespace std;

// Lecture - 127, 128, 129 => Merge Interval Pattern
//Leetcode(1130): Minimum Cost Tree From Leaf Values

//Recursion
int solve(vector<int> &arr, map<pair<int,int>,int> &maxi, int left, int right) {
    //base case
    if(left == right) return 0;

    int ans = INT_MAX;
    for(int i=left; i<right; i++) {
        ans = min(ans, maxi[{left, i}] * maxi[{i+1, right}] + solve(arr, maxi, left, i) + solve(arr, maxi, i+1, right));
    }
    return ans;
}

int mctFromLeafValues(vector<int>& arr) {
    map<pair<int,int>, int> maxi;

    for(int i=0; i<arr.size(); i++) {
        maxi[{i, i}] = arr[i];
        for(int j=i+1; j<arr.size(); j++) {
            maxi[{i, j}] = max(arr[j], maxi[{i, j-1}]);
        }
    }
    return solve(arr, maxi, 0, arr.size()-1);
}

//Memoization
int solve1(vector<int> &arr, map<pair<int,int>, int> &maxi, int left, int right) {
    int n = arr.size();
    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    //base case
    if(left == right) return 0;
    if(dp[left][right] != -1) return dp[left][right];

    int ans = INT_MAX;
    for(int i=left; i<right; i++) {
        ans = min(ans, maxi[{left, i}] * maxi[{i+1, right}] + solve1(arr, maxi, left, i) + solve1(arr, maxi, i+1, right));
    }
    return dp[left][right] = ans;
}

int solveMem(vector<int> &arr) {
    map<pair<int,int>, int> maxi;

    for(int i=0; i<arr.size(); i++) {
        maxi[{i, i}] = arr[i];
        for(int j=i+1; j<arr.size(); j++) {
            maxi[{i, j}] = max(arr[j], maxi[{i, j-1}]);
        }
    }
    return solve1(arr, maxi, 0, arr.size()-1);
}

//Tabulation
int solve2(vector<int> &arr, map<pair<int,int>, int> &maxi) {
    int n = arr.size();
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

    for(int left=n-1; left>=0; left--) {
        for(int right=left+1; right<=n; right++) {
            
            int ans = INT_MAX;
            for(int i=left; i<right; i++) {
                ans = min(ans, maxi[{left, i}] * maxi[{i+1, right}] + dp[left][i] + dp[i+1][right]);
            }
            dp[left][right] = ans;
        }
    }
    return dp[0][n-1];
}

int solveTab(vector<int> &arr) {
    map<pair<int,int>, int> maxi;

    for(int i=0; i<arr.size(); i++) {
        maxi[{i, i}] = arr[i];
        for(int j=i+1; j<arr.size(); j++) {
            maxi[{i, j}] = max(arr[j], maxi[{i, j-1}]);
        }
    }
    return solve2(arr, maxi);
}

int main() {
    cout<<endl;
    vector<int> arr = {6, 2, 4}; //output = 32

    cout<<"Min cost tree from leaf values Rec: "<< mctFromLeafValues(arr) <<endl;
    cout<<"Min cost tree from leaf values Mem: "<< solveMem(arr) <<endl;
    cout<<"Min cost tree from leaf values Tab: "<< solveTab(arr) <<endl;
    return 0;
}