#include <iostream>
#include <stack>
using namespace std;

//Valid Parantheses

bool isValidParenthesis(string str) {

    stack<char> s;
    for(int i=0; i<str.length(); i++) {
        char ch = str[i];

        //if opening bracket, push in stack
        //if closing bracket, check on stack top and pop()

        if(ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);

        }else {
            //for closing bracket
            if(!s.empty()) {
                char top = s.top();

                if((ch == '(' && top == ')') || (ch == '{' && top == '}') || (ch == '[' && top == ']')) {
                    s.pop();

                }else {
                    return false;
                }

            }else {
                return false;
            } 

        }
    }

    if(s.empty()) {
        return true;
    }else {
        return false;
    }
    
}

bool isValidParenthesis1(const string& s) {
    stack<char> st;

    // Traverse the string
    for (char ch : s) {
        // If it's an opening bracket, push it onto the stack
        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        }
        // If it's a closing bracket, check for matching pair
        else {
            if (st.empty()) return false; // Stack is empty but we found a closing bracket
            char top = st.top();

            if ((ch == ')' && top == '(') || 
                (ch == '}' && top == '{') || 
                (ch == ']' && top == '[')) {
                st.pop(); // Valid match, remove the top element

            } else {
                return false; // Mismatch found
            }
        }
    }

    // If the stack is empty, all brackets matched correctly
    return st.empty();
}

int main() {
    cout<<endl;

    string input;
    cout << "Enter Parentheses: ";
    cin >> input;

    if (isValidParenthesis1(input)) {
        cout << "Valid parenthesis" <<endl;
    } else {
        cout << "NOT a valid parenthesis" <<endl;
    }

    return 0;
}