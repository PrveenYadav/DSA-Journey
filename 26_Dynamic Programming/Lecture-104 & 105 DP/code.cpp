#include <iostream>
#include <vector>
#include <climits>
using namespace std;

//Problem --- Practice here --- Min Elements
//GeeksforGeeks: Min coin(midium) | Minimum number of coins(easy)
//Leetcode: 2952. Minimum Number of Coins to be Added(Midium)

//Recursion
int minElementsRec(vector<int> &num, int x) { //x is target
    if(x == 0) return 0;
    if(x < 0) return INT_MAX;

    int mini = INT_MAX;

    for(int i=0; i<num.size(); i++) {
        int ans = minElementsRec(num, x-num[i]);
        if(ans == INT_MAX) return -1;
        if(ans != INT_MAX) {
            mini = min(mini, 1+ans);
        }
    }
    return mini;
}

//Memoization
int solve(vector<int> &num, int x, vector<int> &dp) {
    if(x == 0) return 0;
    if(x < 0) return INT_MAX;

    if(dp[x] != -1) return dp[x];
    int mini = INT_MAX;

    for(int i=0; i<num.size(); i++) {
        int ans = solve(num, x-num[i], dp);
        if(ans == INT_MAX) return -1;
        if(ans != INT_MAX) {
            mini = min(mini, 1+ans);
        }
    }
    
    dp[x] = mini;
    return mini;
}

int minElementMem(vector<int> &num, int x) {
    vector<int> dp(x+1, -1);
    int ans = solve(num, x, dp);
    if(ans == INT_MAX) return -1;
    return ans;
}

//Tabulation
int solve1(vector<int> &num, int x) {
    vector<int> dp(x+1, INT_MAX);
    dp[0] = num[0];

    for(int i=1; i<=x; i++) {
        //i am trying to solve for every amount figure from 1 to x
        for(int j=0; j<num.size(); j++) {
            if(i-num[j] >= 0 && dp[i-num[j]] != INT_MAX) {
                dp[i] = min(dp[i], dp[i-num[j]]);
            }
        }
    }
    
    if(dp[x] == INT_MAX) return -1;
    return dp[x];
}


int main() {
    cout<<endl;

    vector<int> num = {1, 2, 3};
    int x = 7; //Target

    cout<<"Min elements: "<< minElementsRec(num, x) <<endl;
    cout<<"Min elements: "<< minElementMem(num, x) <<endl;
    cout<<"Min elements: "<< solve1(num, x) <<endl;
    return 0;
}