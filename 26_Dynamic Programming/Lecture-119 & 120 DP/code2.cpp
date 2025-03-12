#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Leetcode(1691): Maximum Height by Stacking Cuboids(Hard)

//This  code is returnig the size

bool check(vector<int> &base, vector<int> &newCube) {
    if(newCube[0] <= base[0] && newCube[1] <= base[1] && newCube[2] <= base[2]) {
        return true;
    }else {
        return false;
    }
}

//Tabulation: Largest increasing subsequence
int solveTab(int n, vector<vector<int>> &arr) {
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    
    for(int curr=n-1; curr>=0; curr--) {
        for(int prev=curr-1; prev>=-1; prev--) {
            int include = 0; 
            if(prev == -1 || check(arr[curr], arr[prev])) {
                include = 1 + dp[curr+1][curr+1];
            }
            int exclude = 0 + dp[curr+1][prev+1];
            dp[curr][prev+1] = max(include, exclude);
        }
    }
    return dp[0][0];
}

int maxHeight(vector<vector<int>> &cuboids) {
    //step-1: sort all dimentions for every cuboids
    for(auto &a : cuboids) {
        sort(a.begin(), a.end());
    }

    //step-2: sort cuboids basis on width
    sort(cuboids.begin(), cuboids.end());

    //step-3: use logic of largest increasing subsequence
    return solveTab(cuboids.size(), cuboids);

}

//This code is returing the sum of Heights of all cuboids
//And this is the actual: Leetcode(1691)

int maxHeightNew(vector<vector<int>>& cuboids) {
    // Step 1: Normalize dimensions of each cuboid
    for (auto& cuboid : cuboids) {
        sort(cuboid.begin(), cuboid.end()); // Ensure dimensions are in ascending order
    }

    // Step 2: Sort all cuboids based on dimensions
    sort(cuboids.begin(), cuboids.end());

    int n = cuboids.size();
    vector<int> dp(n, 0); // dp[i] stores the maximum height achievable with the i-th cuboid on top

    int maxHeight = 0;

    // Step 3: Dynamic Programming to calculate maximum height
    for (int i = 0; i < n; i++) {
        dp[i] = cuboids[i][2]; // Start with the height of the current cuboid
        for (int j = 0; j < i; j++) {
            // Check if cuboid j can be placed below cuboid i
            if (cuboids[j][0] <= cuboids[i][0] &&
                cuboids[j][1] <= cuboids[i][1] &&
                cuboids[j][2] <= cuboids[i][2]) {
                dp[i] = max(dp[i], dp[j] + cuboids[i][2]);
            }
        }
        maxHeight = max(maxHeight, dp[i]); // Update the global maximum height
    }
    return maxHeight;
}


int main() {
    cout<<endl;
    vector<vector<int>> cube = { //3 dimensions: hight,width,length
        {50, 45, 20},
        {95, 37, 53},
        {45, 23, 12}
    };

    cout<<"Max Height: "<< maxHeight(cube) <<endl;
    cout<<"Max Height: "<< maxHeightNew(cube) <<endl;
    return 0;
}