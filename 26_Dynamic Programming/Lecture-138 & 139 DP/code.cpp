#include <iostream>
#include <vector>
#include <stack>
#include <climits>
using namespace std;

// Leetcode(85): Maximal Rectangle
// Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

// we'll take help of Problem: Largest area in histogram

vector<int> nextSmallerElement(vector<int> arr, int n) {
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--) {
        int curr = arr[i];

        while (s.top() != -1 && arr[s.top()] >= curr) {
            s.pop();
        }

        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

vector<int> prevSmallerElement(vector<int> arr, int n) {
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for (int i = 0; i < n; i++) {
        int curr = arr[i];

        while (s.top() != -1 && arr[s.top()] >= curr) {
            s.pop();
        }

        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

int largestRectangleArea(vector<int> &arr) {
    int n = arr.size();

    vector<int> next(n);
    next = nextSmallerElement(arr, n);

    vector<int> prev(n);
    prev = prevSmallerElement(arr, n);

    int maxArea = INT8_MIN;
    for (int i = 0; i < n; i++) {
        int length = arr[i];

        if (next[i] == -1) {
            next[i] = n;
        }

        int width = next[i] - prev[i] - 1;

        int area = length * width;
        maxArea = max(area, maxArea);
    }
    return maxArea;
}

//we will go at every row and find largest area(use histogram code) and finally we will return the max(every row's area)
int maximalRectangle(vector<vector<char>>& matrix) {
    vector<int> histogram(matrix[0].size(), 0); //matrix[0] = column
    int maxi = INT_MIN;

    for(int i=0; i<matrix.size(); i++) {
        //to create histogram array
        for(int j=0; j<histogram.size(); j++) {
            if(matrix[i][j] == '1') {
                histogram[j]++;
            }else {
                histogram[j] = 0;
            }
        }
        maxi = max(maxi, largestRectangleArea(histogram));
    }    
    return maxi;
}

int main() {
    cout<<endl;
    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };//output = 6

    cout<<"Maximal rectangle area: "<< maximalRectangle(matrix) <<endl;
    return 0;
}