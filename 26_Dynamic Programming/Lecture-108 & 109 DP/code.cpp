#include <iostream>
#include <vector>
using namespace std;

//Problem: Count Derangements : given input n means 0 to n elements, suppose we have {0, 1, 2} in this 0 on 0th index and so on... So we have to Derange them
//Answer is : n-1 * (solution of subproblems)
//Relation is: F(n) = (n-1) * [F(n-2) + F(n-1)]

//Recursion
long long int countDerangements(int n) {
    //base case
    if(n == 1) return 0;
    if(n == 2) return 1;

    int ans = (n-1) * (countDerangements(n-1) + countDerangements(n-2));
    return ans;
}

//Memoization
long long int countMem(int n) {
    vector<long long int> dp(n+1, -1);
    //base case
    if(n == 1) return 0;
    if(n == 2) return 1;

    if(dp[n] != -1) return dp[n];

    dp[n] = (n-1) * (countMem(n-1) + countMem(n-2));
    return dp[n];
}

//Tabulation
long long int countTab(int n) {
    vector<long long int> dp(n+1, 0);
    dp[1] = 0;
    dp[2] = 1;

    for(int i=3; i<=n; i++) {
        dp[i] = (i-1) * (dp[i-1] + dp[i-2]);
    }
    return dp[n];
}

//Space Optimized
long long int countOptimized(int n) {
    long long int prev2 = 0;
    long long int prev1 = 1;
    long long int ans;

    for(int i=3; i<=n; i++) {
        ans = (i-1) * (prev1 + prev2);
        prev2 = prev1;
        prev1  = ans;
    }
    return ans;
}


int main() {
    cout<<endl;

    //Input is n : means we have elements from 0 to n
    int n = 5; 
    cout<<"Count Derangements-R: "<< countDerangements(n) <<endl;
    cout<<"Count Derangements-M: "<< countMem(n) <<endl;
    cout<<"Count Derangements-T: "<< countTab(n) <<endl;
    cout<<"Count Derangements-S: "<< countOptimized(n) <<endl;
    return 0;
}