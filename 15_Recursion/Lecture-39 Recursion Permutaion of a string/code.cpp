#include <iostream>
#include <vector>
using namespace std;

void solve(vector<int> nums, int index, vector<vector<int>> &ans){

    //base case
    if(index >= nums.size()) {
        ans.push_back(nums);
        return ;
    }

    //Loops for swaping further from index
    for(int j=index; j<nums.size(); j++) {
        swap(nums[index], nums[j]);
        solve(nums, index+1, ans);

        //backtrack
        swap(nums[index], nums[j]);
    }
}

//Permutations : Permutation of string : Leetcode 46 (medium)
//This is for numbers we can solve also for strings as like that
vector<vector<int>> permute(vector<int> &nums) {

    vector<vector<int>> ans;
    int index = 0;
    solve(nums, index, ans);
    return ans;
}

int main() {
    cout<<endl;

    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = permute(nums);

    // cout << "All subsets:\n";
    // for (const auto& subset : result) {
    //     cout << "[";
    //     for (int num : subset) {
    //         cout << num << " ";
    //     }
    //     cout << "]";
    //     cout << endl;
    // }

    cout << "[";
    for (size_t i = 0; i < result.size(); ++i) {
        cout << "{";
        
        // Print each number in the subset
        for (size_t j = 0; j < result[i].size(); ++j) {
            cout << result[i][j];
            if (j < result[i].size() - 1) {
                cout << " ";  // Add space between numbers in the same subset
            }
        }
        
        cout << "}";
        
        // Add a comma after each subset except the last one
        if (i < result.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    return 0;
}