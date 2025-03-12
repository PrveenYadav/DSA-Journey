#include <iostream>
#include <stack>
#include <vector>
using namespace std;


vector<int> nextSmallerElement(int *arr, int n) {
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for(int i=n-1; i>=0; i--) {
        int curr = arr[i];

        while(s.top() != -1 && arr[s.top()] >= curr) {
            
            s.pop();
        }

        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

vector<int> prevSmallerElement(int *arr, int n) {
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for(int i=0; i<n; i++) {
        int curr = arr[i];

        while(s.top() != -1 && arr[s.top()] >= curr) {

            s.pop();
        }

        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

//Largest Rectangle in Histogram
int largestRectangleArea(int *arr, int n) {
    //int n = arr.size();

    vector<int> next(n);
    next = nextSmallerElement(arr, n);

    vector<int> prev(n);
    prev = prevSmallerElement(arr, n);

    int maxArea = INT8_MIN;
    for(int i=0; i<n; i++) {
        int length = arr[i];

        if(next[i] == -1) {
            next[i] = n;
        }

        int width = next[i] - prev[i] - 1;

        int area = length * width;
        maxArea = max(area, maxArea);
    }
    return maxArea;
}


//Problem: Max Rectangle in binary matrix with all 1's
int maxRectangle(int M[INT8_MAX][INT8_MAX], int m, int n) {

    //step-1: Compute maxArea for first row
    //step-2: for every remaining row, Add above row element in curr row
    //step-3: Compute the Area

    int maxArea = largestRectangleArea(M[0], m);

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {

            //row update: by adding previous row's value
            if(M[i][j] != 0) {
                M[i][j] = M[i][j] + M[i-1][j];
            }else{
                M[i][j] = 0;
            }
        }

        //Entire row is updated now
        int newArea = largestRectangleArea(M[i], m);
        maxArea = max(maxArea, newArea);
    }
    return maxArea;
}


int main() {
    cout<<endl;

    int matrix[4][4] = {
        {0, 1, 1, 0},
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 0, 0}
    };

    int row = 4;
    int col = 4;

    //cout<< maxRectangle(matrix, row, col) <<endl;
    return 0;
}