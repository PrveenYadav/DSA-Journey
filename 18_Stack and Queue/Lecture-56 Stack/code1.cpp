#include <iostream>
#include <stack>
#include <vector>
using namespace std;

//Time ans space complexity is O(n)

vector<int> nextSmallerElement(vector<int> arr, int n) {
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

vector<int> prevSmallerElement(vector<int> arr, int n) {
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


//Problem: Largest Rectangle in Histogram : Leetcode 84(Hard)
int largestRectangleArea(vector<int> &arr) {
    int n = arr.size();

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


void printArray(vector<int> arr) {
    int n = arr.size();
    for(int i=0; i<n; i++) {
        cout<< arr[i] <<" ";
    }
    cout<<endl;
}

int main() {
    cout<<endl;

    vector<int> arr = {2, 1, 5, 6, 2, 3};
    int n = arr.size();

    cout<<"Array: ";
    printArray(arr);
    cout<<"Largest Rectangle Area is: "<< largestRectangleArea(arr) <<endl;
    return 0;
}