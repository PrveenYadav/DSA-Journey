#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Function to find the largest rectangle area in a histogram
int largestRectangleArea(vector<int>& heights) {
    
    stack<int> st;
    int maxArea = 0;
    heights.push_back(0); // Add a dummy zero height to ensure stack empties

    for (int i = 0; i < heights.size(); ++i) {

        while (!st.empty() && heights[st.top()] > heights[i]) {

            int height = heights[st.top()];
            st.pop();
            int width = st.empty() ? i : i - st.top() - 1;
            maxArea = max(maxArea, height * width);
        }
        st.push(i);
    }

    heights.pop_back(); // Remove the dummy height
    return maxArea;
}

// Function to find the maximum rectangle area in a binary matrix
int maximalRectangle(vector<vector<int>>& mat) {

    if (mat.empty() || mat[0].empty()) return 0;

    int n = mat.size(), m = mat[0].size();
    vector<int> heights(m, 0);
    int maxArea = 0;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            // Update the heights array
            heights[j] = (mat[i][j] == 1) ? heights[j] + 1 : 0;
        }
        // Calculate the maximum area for the current histogram
        maxArea = max(maxArea, largestRectangleArea(heights));
    }
    return maxArea;
}

int main() {
    cout<<endl;

    vector<vector<int>> mat = {
        {0, 1, 1, 0},
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 0, 0}
    };

    cout << "Maximum Rectangle Area: " << maximalRectangle(mat) << endl;
    return 0;
}