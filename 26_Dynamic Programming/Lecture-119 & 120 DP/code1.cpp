#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Return the maximum number of envelops you can Russian Doll(put one inside the another)
//Leetcode(354): Russian Doll Envelopes(Hard)


//Approach---
    //step-1: sort envelopes by width in ascending order, If two envelopes have the same width, sort by height in descending order (to avoid nesting envelopes with the same width).
    //step-2: Extract the Height of sorted envelopes, And on these Height use (LIS)Largest increasing subsequence which gives the maximum number of envelopes that can be nested


int maxEnvelopes(vector<vector<int>>& envelopes) {
    // Step 1: Sort envelopes by width and then by height in descending order for the same width
    sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0]) return a[1] > b[1]; // Descending order for height if widths are equal
        return a[0] < b[0]; // Ascending order for width
    });

    // Step 2: Extract the heights of the sorted envelopes
    vector<int> heights;
    for (const auto& envelope : envelopes) {
        heights.push_back(envelope[1]);
    }

    // Step 3: Find the Longest Increasing Subsequence (LIS) of heights
    vector<int> lis;
    for (int height : heights) {
        auto it = lower_bound(lis.begin(), lis.end(), height);
        if (it == lis.end()) {
            lis.push_back(height); // Add to LIS if height is larger than all elements in LIS
        } else {
            *it = height; // Replace the first element greater than or equal to height
        }
    }
    return lis.size();
}


int main() {
    cout<<endl;
    vector<vector<int>> arr = {{5, 4}, {6, 4}, {6, 7}, {2, 3}}; //width(5) and height(4) it given in 2D vector

    cout<<"Max Envelopes: "<< maxEnvelopes(arr) <<endl;
    return 0;
}