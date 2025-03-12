#include <iostream>
#include <vector>
#include <climits>
using namespace std;

//Problem: Get Minimum Squares

//Recursion
int minSquaresRec(int n) {
    //base case
    if(n == 0) return 0;

    int ans = n; //max answer can be n, we have to give min so intiallizing with 
    for(int i=1; i*i<=n; i++) {
        int temp = i*i;
        ans = min(ans, 1 + minSquaresRec(n-temp));
    }
    return ans;
}

//Memoization
int minSquaresMem(int n) {
    vector<int> dp(n+1, -1);
    //base case
    if(n == 0) return 0;
    if(dp[n] != -1) return dp[n];

    int ans = n;
    for(int i=1; i*i<=n; i++) {
        int temp = i*i;
        ans = min(ans, 1 + minSquaresMem(n-temp));
    }
    dp[n] = ans;
    return dp[n];
}

//Tabulation
int minSquaresTab(int n) {
    vector<int> dp(n+1, INT_MAX); //we are returning min so initialize with max num
    dp[0] = 0;

    for(int i=1; i<=n; i++) {
        for(int j=1; j*j<=n; j++) {
            int temp = j*j;
            if(i-temp >= 0)
                dp[i] = min(dp[i], 1 + dp[i-temp]);
        }
    }
    return dp[n];
}

int main() {
    cout<<endl;
    int n = 5;

    cout<<"Min Squares Rec: "<< minSquaresRec(n) <<endl;
    cout<<"Min Squares Mem: "<< minSquaresMem(n) <<endl;
    cout<<"Min Squares Tab: "<< minSquaresTab(n) <<endl;
    return 0;
}