#include <iostream>
#include <stack>
using namespace std;

//Reverse a string using stack

int main() {
    cout<<endl;

    string str = "Hello";

    stack<char> s;

    for(int i=0; i<str.length(); i++) {
        char ch = str[i];
        s.push(ch);
    }

    string ans = "";
    
    while(!s.empty()) { //while s(stack) is not empty
        char ch = s.top();
        ans.push_back(ch);

        s.pop();
    }
    cout<< ans <<endl;
    return 0;
}