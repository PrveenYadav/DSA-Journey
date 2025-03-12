#include <iostream>
#include <stack>
using namespace std;

//Delete middle element from the stack

void solve(stack<int> &s, int count, int size) {
    //base case
    if(count == size/2) {
        s.pop();
        return ;
    }

    int num = s.top();
    s.pop();

    //Recursive call
    solve(s, count+1, size);

    s.push(num);
}

void deleteMiddle(stack<int> &s, int n) {
    int count = 0;
    solve(s, count, n);
}


// Function to print the stack
void printStack(stack<int> st) {

    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop(); // Remove the top element
    }
    cout << endl;
}

int main() {
    cout<<endl;

    stack<int> st;

    // Push elements onto the stack
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    cout<<"Printing Stacks: ";
    printStack(st);

    deleteMiddle(st, 5);
    cout<<"Stack after deleting middle element: ";
    printStack(st);

    return 0;
}