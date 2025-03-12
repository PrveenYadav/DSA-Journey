#include <iostream>
#include <vector> 
using namespace std;

//House Robbery Problem : It is like prev question(Nont-Adjacency elements sum) but it is Circular

int solve(vector<int> &num) {
    int n = num.size();
    int prev2 = 0; 
    int prev1 = num[0];

    for(int i=1; i<n; i++) {
        int inc = prev2 + num[i];
        int exc = prev1 + 0;

        int ans = max(inc, exc);
        prev2 = prev1; 
        prev1 = ans;
    }
    return prev1;
}

int houseRobber(vector<int> &valueInHouse) {
    int n = valueInHouse.size();
    if(n == 1) return valueInHouse[0];
    vector<int> first, second; //solve array in 2 parts, first((0 to n-1)all elements but not last one), second((1 to n)all elements but not first one)
    
    for(int i=0; i<n; i++) {
        if(i != n-1) {
            first.push_back(valueInHouse[i]);
        }
        if(i != 0) {
            second.push_back(valueInHouse[i]);
        }
    }

    return max(solve(first), solve(second));
}

int main() {
    cout<<endl;

    //vector<int> num = {8, 9, 7, 4, 6};
    vector<int> num = {2,7,9,3,1}; //12
    //it will tell max money a robber can make, conditions(non-adjacent, and circular)
    cout<<"Max money: "<< houseRobber(num) <<endl;
    return 0;
}