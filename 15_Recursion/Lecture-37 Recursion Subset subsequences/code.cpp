#include <iostream>
#include <vector>
using namespace std;

//function for Recursion
void solve(vector<int> nums, vector<int> output, int index, vector<vector<int>> &ans) {

    //base case
    if(index >= nums.size()) {
        ans.push_back(output);
        return ;
    }

    //Exclude
    solve(nums, output, index+1, ans);

    //Include
    int element = nums[index];
    output.push_back(element);
    solve(nums, output, index+1, ans); 
}

//Subsets : set of subsets : Leetcode 78 (medium)
vector<vector<int>> subsets(vector<int> &nums) {

    vector<vector<int>> ans;
    vector<int> output;
    int index = 0;
    solve(nums, output, index, ans);
    return ans;
}

int main() {
    cout<<endl;

    vector<int> nums = {1, 2, 3};
    int n = 3;
    vector<vector<int>> result = subsets(nums);
    
    // cout << "All subsets:\n";
    // for (const auto& subset : result) {
    //     //cout << "[";
    //     for (int num : subset) {
    //         cout << num << " ";
    //     }
    //    // cout << "]";
    //     cout << endl;
    // }

    cout << "[";
    for (size_t i = 0; i < result.size(); ++i) {
        cout << "[";
        
        // Print each number in the subset
        for (size_t j = 0; j < result[i].size(); ++j) {
            cout << result[i][j];
            if (j < result[i].size() - 1) {
                cout << " ";  // Add space between numbers in the same subset
            }
        }
        
        cout << "]";
        
        // Add a comma after each subset except the last one
        if (i < result.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
    return 0;
}