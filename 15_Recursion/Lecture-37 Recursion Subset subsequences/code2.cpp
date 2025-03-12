#include <iostream>
#include <vector>

using namespace std;

void generateSubsets(int index, vector<int>& nums, vector<int>& currentSet, vector<vector<int>>& result) {
    // Base case: when we've considered all elements
    if (index == nums.size()) {
        result.push_back(currentSet); // Add the current subset to the result
        return;
    }

    // Case 1: Exclude the current element and move to the next
    generateSubsets(index + 1, nums, currentSet, result);

    // Case 2: Include the current element and move to the next
    currentSet.push_back(nums[index]);
    generateSubsets(index + 1, nums, currentSet, result);

    // Backtrack: Remove the last added element before returning to the previous state
    currentSet.pop_back();
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> currentSet;
    generateSubsets(0, nums, currentSet, result);
    return result;
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = subsets(nums);

    cout << "All subsets:\n";
    for (const auto& subset : result) {
        cout << "[";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "]";
        cout << endl;
    }

    return 0;
}
