#include <iostream>
#include <stack>
using namespace std;

int main() {
    cout<<endl;

    //creation of stack
    stack<int> s;

    s.push(2);
    s.push(3);
    s.push(4);

    s.pop();

    cout<<"Printing top element: "<< s.top() <<endl;

    if(s.empty()) {
        cout<<"Stck is empty"<<endl;
    }else {
        cout<<"Not empty"<<endl;
    }

    cout<<"size of stack is: "<< s.size() <<endl; 
    return 0;
}