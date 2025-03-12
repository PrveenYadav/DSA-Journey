#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

//Leetcode(1218): Longest AP with given Difference
int longestSubsequence(vector<int> &arr, int difference) {
    unordered_map<int, int> dp;
    int ans = 0;

    for(int i=0; i<arr.size(); i++) {
        int temp = arr[i]-difference;
        int tempAns = 0;

        //check if ans is already exist for temp or not
        if(dp.count(temp))
            tempAns = dp[temp];
        
        //curr ans update
        dp[arr[i]] = 1 + tempAns;

        //ans update
        ans = max(ans, dp[arr[i]]);
    }
    return ans;
} 

int main() {
    cout<<endl;
    vector<int> arr = {1, 2, 3, 4};
    int diff = 1; //output = 4
    vector<int> arr1 = {1, 5, 7, 8, 5, 3, 4, 2, 1};
    int diff1 = -2; //output = 4

    cout<<"Longest AP: "<< longestSubsequence(arr1, diff1) <<endl;
    return 0;
}