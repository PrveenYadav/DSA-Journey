#include <iostream>
#include <string>
using namespace std;

//check palindrome by Recursion
bool checkPallindrome(string str, int i, int j) {
    
    //base case
    if(i > j) {
        return true;
    }

    if(str[i] != str[j]) {
        return false;
    }else {
        //Recursive call
        return checkPallindrome(str, i+1, j-1);
    }
}

int main() {
    string name = "madam";
    int n = name.length();
    cout<<endl;

    bool isPalindrome = checkPallindrome(name, 0, n-1);
    if(isPalindrome) {
        cout<<"It is Palindrome"<<endl;
    }else {
        cout<<"It is not a Palindrome"<<endl;
    }
    return 0;
}