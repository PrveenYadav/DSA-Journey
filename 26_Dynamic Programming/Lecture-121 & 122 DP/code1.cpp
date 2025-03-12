#include <iostream>
#include <vector>
using namespace std;

//Given N dice each with M faces, numbered from 1 to M, Find the number of ways to get sum X
//N = no of Dices, M = faces(how many faces in 6 faces), X = Target Sum
//Problem: Number of Dice Rolls with Target Sum || Dice Rolls

//Recursion
long long solve(int dice, int faces, int target) {
    //base case
    if(target < 0) return 0;
    if(dice == 0 && target != 0) return 0;
    if(dice != 0 && target == 0) return 0;
    if(dice == 0 && target == 0) return 1;

    long long ans = 0;
    for(int i=1; i<=faces; i++) {
        ans = ans + solve(dice-1, faces, target-i);
    }
    return ans;
}

long long noOfWays(int M, int N, int X) {//M=faces, N=dices, X=Target
    return solve(N, M, X);
}

//Memoization
long long solveMem(int dice, int faces, int target, vector<vector<long long>> &dp) {
    //base case
    if(target < 0) return 0;
    if(dice == 0 && target != 0) return 0;
    if(dice != 0 && target == 0) return 0;
    if(dice == 0 && target == 0) return 1;

    if(dp[dice][target] != -1) return dp[dice][target];

    long long ans = 0;
    for(int i=1; i<=faces; i++) {
        ans = ans + solveMem(dice-1, faces, target-i, dp);
    }
    return dp[dice][target] = ans;
}

long long solve1(int M, int N, int X) {
    vector<vector<long long>> dp(N+1, vector<long long>(X+1, -1));
    return solveMem(N, M, X, dp);
}

//Tabulation
long long solveTab(int M, int N, int X) { //N=dice, M=faces, X=target
    vector<vector<long long>> dp(N+1, vector<long long>(X+1, 0));
    //base case
    dp[0][0] = 1;

    for(int dice=1; dice<=N; dice++) {
        for(int target=1; target<=X; target++) {
            long long ans = 0;
            for(int i=1; i<=M; i++) { //M=faces
                if(target-i >= 0)
                    ans = ans + dp[dice-1][target-i];
            }
            dp[dice][target] = ans;
        }
    }
    return dp[N][X];
}

//Space Optimization
long long solveOptimized(int M, int N, int X) {
    vector<long long> prev(X+1, 0);
    vector<long long> curr(X+1, 0);
    //base case
    prev[0] = 1;

    for(int dice=1; dice<=N; dice++) {
        for(int target=1; target<=X; target++) {
            long long ans = 0;
            for(int i=1; i<=M; i++) { //M=faces
                if(target-i >= 0)
                    ans = ans + prev[target-i];
            }
            curr[target] = ans;
        }
        prev = curr;
    }
    return prev[X];
}

int main() {
    cout<<endl;
    //N=dice, M=faces, X=target
    int M = 6, N = 3, X = 12; //output: 25

    cout<<"No of Ways Rec: "<< noOfWays(M, N, X) <<endl;
    cout<<"No of Ways Mem: "<< solve1(M, N, X) <<endl;
    cout<<"No of Ways Tab: "<< solveTab(M, N, X) <<endl;
    cout<<"No of Ways S.O: "<< solveOptimized(M, N, X) <<endl;
    return 0;
}