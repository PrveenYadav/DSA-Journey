#include <iostream>
#include <vector>
#include <climits>
using namespace std;

//Leetcode(1824): Minimum Sideway Jumps

//Recursion
int solve(vector<int> &obs, int currLane, int currPos) {
    int n = obs.size() - 1;
    //base case
    if(currPos == n) return 0;

    if(obs[currPos+1] != currLane) { //if obstacle is not on the next pos of currlane then recursion will solve rest
        return solve(obs, currLane, currPos+1);
    }else{
        //Sideway Jumps 
        int ans = INT_MAX;
        for(int i=1; i<=3; i++) { //3 Lanes are given
            if(currLane != i && obs[currPos] != i) {
                ans = min(ans, 1 + solve(obs, i, currPos));
            }
        }
        return ans;
    }
}

int minSideJump(vector<int> &obstacles) {
    return solve(obstacles, 2, 0); //given, frog's current Lane is 2nd lane
}

//Memoization(Top-Down)
int solve1(vector<int> &obs, int currLane, int currPos, vector<vector<int>> &dp) {
    int n = obs.size() - 1;
    //base case
    if(currPos == n) return 0;
    if(dp[currLane][currPos] != -1) return dp[currLane][currPos];

    if(obs[currPos+1] != currLane) {
        return solve1(obs, currLane, currPos+1, dp);
    }else {
        //sideway jump
        int ans = INT_MAX;
        for(int i=1; i<=3; i++) {
            if(obs[currPos] != i && currLane != i) {
                ans = min(ans, 1 + solve1(obs, i, currPos, dp));
            }
        }
        dp[currLane][currPos] = ans;
    }
    return dp[currLane][currPos];
}

int minSideJumpMem(vector<int> &obs) {
    int lane = 3;
    int n = obs.size();
    vector<vector<int>> dp(lane+1, vector<int>(n, -1));
    return solve1(obs, 2, 0, dp);
}


//Tabulation(Bottom-Up)
int minSideJumpTab(vector<int> &obs) {
    int n = obs.size()-1;
    vector<vector<int>> dp(4, vector<int>(obs.size(), INT_MAX)); //or 1e9

    //base case
    dp[0][n] = 0;
    dp[1][n] = 0;
    dp[2][n] = 0;
    dp[3][n] = 0;

    for(int pos=n-1; pos>=0; pos--) {
        for(int lane=1; lane<=3; lane++) {

            if(obs[pos+1] != lane) {
                dp[lane][pos] = dp[lane][pos+1];
            }else{
                //Sideway Jumps 
                int ans = INT_MAX; //or 1e9
                for(int i=1; i<=3; i++) {
                    if(lane != i && obs[pos] != i) {
                        ans = min(ans, 1 + dp[i][pos+1]);
                    }
                }
                dp[lane][pos] = ans;
            }
        }
    }
    return min(dp[2][0], min(1+dp[1][0], 1+dp[3][0]));
}

//Space Optimized: O(1)
int minSideJumpOptimized(vector<int> &obs) {
    int n = obs.size()-1;
    vector<int> curr(4, 0); //or INT_MAX in both vector
    vector<int> next(4, 0);

    //base case
    next[n] = 0;
    next[n] = 0;
    next[n] = 0;
    next[n] = 0;

    for(int pos=n-1; pos>=0; pos--) {
        for(int lane=1; lane<=3; lane++) {

            if(obs[pos+1] != lane) {
                curr[lane] = next[lane];
            }else{
                //Sideway Jumps 
                int ans = INT_MAX; //or 1e9
                for(int i=1; i<=3; i++) {
                    if(lane != i && obs[pos] != i) {
                        ans = min(ans, 1 + next[i]);
                    }
                }
                curr[lane] = ans;
            }
        }
        next = curr;
    }
    return min(next[2], min(1+next[1], 1+next[3]));
}

//all test cases pass
int minSideJumpOptimized1(vector<int>& obs) {
    int n = obs.size() - 1;
    vector<int> curr(4, 1e9);
    vector<int> next(4, 1e9);

    // Base case: at the last position, no jumps are needed.
    next[1] = 0;
    next[2] = 0;
    next[3] = 0;

    // Iterate from the second-to-last position to the first.
    for (int pos = n - 1; pos >= 0; pos--) {
        for (int lane = 1; lane <= 3; lane++) {
            if (obs[pos + 1] != lane && obs[pos] != lane) {
                curr[lane] = next[lane];
            } else {
                // Calculate the minimum sideways jumps
                int ans = 1e9;
                for (int i = 1; i <= 3; i++) {
                    if (lane != i && obs[pos] != i) {
                        ans = min(ans, 1 + next[i]);
                    }
                }
                curr[lane] = ans;
            }
        }
        next = curr;
    }

    // Start from lane 2 and calculate the minimum jumps needed.
    return min(next[2], min(1 + next[1], 1 + next[3]));
}

int main() {
    cout<<endl;
    vector<int> obstacles = {0, 1, 2, 3, 0}; //output = 2

    cout<<"Sideway Jumps Rec: "<< minSideJump(obstacles) <<endl;
    cout<<"Sideway Jumps Mem: "<< minSideJumpMem(obstacles) <<endl;
    cout<<"Sideway Jumps Tab: "<< minSideJumpTab(obstacles) <<endl;
    cout<<"Sideway Jumps S.O: "<< minSideJumpOptimized(obstacles) <<endl;
    cout<<"Sideway Jumps S.O: "<< minSideJumpOptimized1(obstacles) <<endl;
    return 0;
}