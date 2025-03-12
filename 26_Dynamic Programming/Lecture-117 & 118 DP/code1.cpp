#include <iostream> 
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

//Leetcode(1402): Reducing dishes(hard)

//Recursion
int solve(vector<int> &satisfaction, int index, int time) {
    //base case
    if(index == satisfaction.size()) return 0;

    int include = satisfaction[index]*(time+1) + solve(satisfaction, index+1, time+1);
    int exclude = 0 + solve(satisfaction, index+1, time);

    return max(include, exclude);
}

int maxSatisfaction(vector<int> &satisfaction) {
    sort(satisfaction.begin(), satisfaction.end());
    return solve(satisfaction, 0, 0);
}

//Memoization
int solve1(vector<int> &satisfaction, int index, int time, vector<vector<int>> &dp) {
    //base case
    if(index == satisfaction.size()) return 0;
    if(dp[index][time] != -1) return dp[index][time];

    int include = satisfaction[index]*(time+1) + solve1(satisfaction, index+1, time+1, dp);
    int exclude = 0 + solve1(satisfaction, index+1, time, dp);

    return dp[index][time] = max(include, exclude);
}

int maxSatisfactionMem(vector<int> &satisfaction) {
    int n = satisfaction.size();
    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));

    sort(satisfaction.begin(), satisfaction.end());
    return solve(satisfaction, 0, 0);
}

//Tabulation
int maxSatisfactionTab(vector<int> &satisfaction) {
    int n = satisfaction.size();
    sort(satisfaction.begin(), satisfaction.end());
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

    for(int index=n-1; index>=0; index--) {
        for(int time=index; time>=0; time--) {
            int include = satisfaction[index]*(time+1) + dp[index+1][time+1];
            int exclude = 0 + dp[index+1][time];

            dp[index][time] = max(include, exclude);
        }
    }
    return dp[0][0]; //we're going(for index & time both) from n-1 to 0 then our ans will on 0
}

//all prev on O(n^2) time & space

//Space optimized : O(n)
int maxSatisfactionOptimized(vector<int> &satisfaction) {
    int n = satisfaction.size();
    sort(satisfaction.begin(), satisfaction.end());
    vector<int> next(n+1, 0);
    vector<int> curr(n+1, 0);

    for(int index=n-1; index>=0; index--) {
        for(int time=index; time>=0; time--) {

            int include = satisfaction[index]*(time+1) + next[time+1];
            int exclude = 0 + next[time];
            curr[time] = max(include, exclude);
        }
        next = curr;
    }
    return next[0];
}

//Home work : we can space optimized at O(1): single vector can use instead of (curr and next)

int main() {
    cout<<endl;
    vector<int> val = {-1, -8, 0, 5, -9}; //output 14

    cout<<"Max Satisfaction Rec: "<< maxSatisfaction(val) <<endl;
    cout<<"Max Satisfaction Mem: "<< maxSatisfactionMem(val) <<endl;
    cout<<"Max Satisfaction Tab: "<< maxSatisfactionTab(val) <<endl;
    cout<<"Max Satisfaction S.O: "<< maxSatisfactionOptimized(val) <<endl;
    return 0;
}