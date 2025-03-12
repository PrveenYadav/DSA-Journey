#include <iostream>
using namespace std;

//Count ways to Reach the Nth stairs (Medium level) : DP Que
//stairs means sidhi

int waysToClimbStairs(long long stairs) {

    if(stairs < 0)
        return 0;
    
    if(stairs == 0)
        return 1;

    int ans = waysToClimbStairs(stairs-1) + waysToClimbStairs(stairs-2);

    return ans;
}

int main() {

    long long stairs = 5;
    
    cout<<waysToClimbStairs(stairs)<<endl;
}
