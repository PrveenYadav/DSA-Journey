#include <iostream>
#include <vector>
using namespace std;

//Leetcode(96): Unique Binary Search Trees
//Catalan numbers(Formula: 2n! / (n+1)! * n!) : catalan numbers(1,1,2,5,14...) are same as unique binary search tree nubers are
//for 0 index catalan number -> 1, 1->1, 2->2, 3->5, 4->14, 5->42, 6->132 ......

//Also Solve using the formula of catalan number

//Recursion
int numTree(int n) {
    if(n <= 1) return 1;
    int ans = 0;
    //Assuming i as a root node
    for(int i=1; i<=n; i++) {
        ans += numTree(i-1) * numTree(n-i);
    }
    return ans;
}

//Memoization
int numTreeMem(int n) {
    vector<int> dp(n+1, -1);
    if(n <= 1) return 1;
    if(dp[n] != -1) return dp[n];

    int ans = 0;
    //Assuming i as a root node
    for(int i=1; i<=n; i++) {
        ans += numTreeMem(i-1) * numTreeMem(n-i);
    }
    return dp[n] = ans;
}

//Tabulation
int numTreeTab(int n) {
    vector<int> dp(n+1, 0);
    dp[0] = dp[1] = 1;

    //i-> number of nodes
    for(int i=2; i<=n; i++) {
        //j-> root node
        for(int j=1; j<=i; j++) {
            dp[i] += dp[j-1] * dp[i-j];
        }
    }
    return dp[n];
}

int main() {
    cout<<endl;
    int n = 3;

    cout<<"Num Trees Rec: "<< numTree(n) <<endl;
    cout<<"Num Trees Mem: "<< numTreeMem(n) <<endl;
    cout<<"Num Trees Tab: "<< numTreeTab(n) <<endl;
    return 0;
}