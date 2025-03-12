#include <iostream> 
#include <stack>
using namespace std;

//Que - Redundant brackets: A pair of brackets said to be rebundant when subexpression sorrounded by needless/useless brackets

bool findRedundant(string &s) {
    stack<char> st;

    for(int i=0; i<s.length(); i++) {
        char ch = s[i];

        if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            st.push(ch);
        }else {
            //ch is '(' or lowercase letter
            if(ch == ')') {
                bool isRedundant = true;

                while(st.top() != '(') {
                    char top = st.top();

                    if(top == '+' || top == '-' || top == '*' || top == '/') {
                        isRedundant = false;
                    }
                    st.pop();
                }
                
                if(isRedundant == true) {
                    return true;
                }
                st.pop();
            }
        }
    }
    return false;
}

int main() {
    cout<<endl;

    string s;
    cout<<"Enter a string: ";
    cin>>s;

    if(findRedundant(s)) {
        cout<<"Yes!, String is Redundant"<<endl;
    }else{
        cout<<"No!, Not Redundant"<<endl;
    }

    return 0;
}