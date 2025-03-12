#include <iostream>
#include <stack>
using namespace std;

//Input and Output in Stack

// Input Function || Functon to take input to push elements in stack
void inputStack(stack<int> &s, int n) {

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s.push(x);
    }
}

// Printing Function || Function to print stack elements
void printStack(stack<int> s) {
    while(!s.empty()) {
        cout<< s.top() <<" ";
        s.pop();
    }
    cout<<endl;
}

int main() {
    cout<<endl;

    stack<int> st;
    int n;
    
    //Taking numbers of elements to push
    cout << "Enter the number of elements to push into the stack: ";
    cin >> n;

    //Taking input
    cout << "Enter " << n << " elements: ";
    inputStack(st, n);

    //Printing output/stack elements top to bottom
    cout << "Stack elements: ";
    printStack(st);

    return 0;
}