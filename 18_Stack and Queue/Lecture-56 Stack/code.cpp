#include <iostream>
#include <stack>
#include <vector>
using namespace std;

//Que- Next smaller element: for input(2, 1, 4, 3) next smaller element is (1, -1, 3, -1)
vector<int> nextSmallerElement(vector<int> &arr, int n) {
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    //loop till the smaller element not found
    for(int i=n-1; i>=0; i--) {
        int curr = arr[i];
        while(s.top() >= curr) {
            s.pop();
        }
        //Now, smaller element found,  ans is top() of stack
        ans[i] = s.top();
        s.push(curr);
    }
    return ans;
}

int main() {
    cout<<endl;

    vector<int> arr = {2, 3, 1};
    int n = 3;

    cout<<"Array is: ";
    for(int i=0; i<n; i++) {
        cout<< arr[i] <<" ";
    }
    cout<<endl;

    nextSmallerElement(arr, n);
    cout<<"Next smaller element: ";
    for(int i=0; i<n; i++) {
        cout<< arr[i] <<" ";
    }
    cout<<endl;


    return 0;
}