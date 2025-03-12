#include <iostream>
#include <vector>
using namespace std;

//Dynamic Programming : Recursion + Memoization => Tabulation => Space optimization

//Recursive Implementation
int fib1(int n) {
    if(n <= 1) return n;
    int fib = fib1(n-1) + fib1(n-2);
    return fib;
}

//Memoization(Top-Down)
int fib2(int n) {
    vector<int> dp(n+1); //create an array to store ans 
    for(int i=0; i<n; i++) {
        dp[i] = -1; //In starting we intialize the array with -1
    }

    if(n <= 1) return n; //base case
    dp[n] = fib2(n-1) + fib2(n-2); //function call
    return dp[n];
}

//Tabulation(Bottom-Up)
int fib3(int n) {
    vector<int> dp(n+1);
    for(int i=0; i<n; i++) {
        dp[i] = -1;
    }

    if(n <= 1) return n;
    
    dp[0] = 0;
    dp[1] = 1;

    for(int i=2; i<=n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

//Space Optimized Approach
int fib4(int n) {
    vector<int> dp(n+1);
    for(int i=0; i<n; i++) {
        dp[i] = -1;
    }

    int prev1 = 0;
    int prev2 = 1;

    if(n == 0) return prev1; //means 0

    int curr;

    for(int i=2; i<=n; i++) {
        int curr = prev1 + prev2;
        prev1 = prev2;
        prev2 = curr;
    }

    return prev2;
}

int main() {
    cout<<endl;

    int n = 7;
    
    cout<<"Fibonacci of n | Dynamic Programming | All Appraches "<<endl;
    cout<<"Basic Recursion: "<< fib1(n) <<endl;
    cout<<"Memoization: "<< fib2(n) <<endl;
    cout<<"Tabulation: "<< fib3(n) <<endl;
    cout<<"Space Optimized: "<< fib4(n) <<endl;
    return 0;
}