#include <iostream> 
#include <stack>
#include <vector>
using namespace std;

//The celebrity problem: this can be solve using brute force (using 2 loops for row & col), but using stack we can optimized at O(n)

bool knows(vector<vector<int>> &M, int a, int b, int n) {
    if(M[a][b] == 1) {
        return true;
    }else {
        return false;
    }
}

int celebrity(vector<vector<int>> &M, int n) {
    stack<int> s;

    //step-1: push all elements in stack
    for(int i=0; i<n; i++) {
        s.push(i);
    }

    //step-2: get two elements and compare them
    while(s.size() > 1) {
        int a = s.top();
        s.pop();

        int b = s.top();
        s.pop();

        if(knows(M, a, b, n)) {
            s.push(b);
        }else{
            s.push(a);
        }
    }

    int ans = s.top();
    //step-3: Now single element in stack is potential celebrity
    //So Verify it
    int zeroCount = 0;
    for(int i=0; i<n; i++) {
        if(M[ans][i] == 0) {
            zeroCount++;
        }
    }

    //all zeros
    if(zeroCount != n) return -1;

    //column check
    int oneCount = 0;
    for(int i=0; i<n; i++) {
        if(M[i][ans] == 1) {
            oneCount++;
        }
    }

    if(oneCount != n-1) return -1;

    return ans; 
}


int main() {
    cout<<endl;

    vector<vector<int>> matrix = 
    {
        {0, 1, 0},
        {0, 0, 0},
        {0, 1, 0}
    };
    int n = matrix.size();

    cout<< celebrity(matrix, n) <<endl;

    return 0;
}