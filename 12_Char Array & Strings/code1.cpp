#include <iostream>
#include <string>
using namespace std;

// Function to check valid
bool valid(char ch) { 

    if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z' || ch >= '0' && ch <= '9') {

       return 1;
    }
    return 0;
}

//Functoion for lower case
int toLowerCase(char ch) {
    if (ch >= 'a' && ch <= 'z' || ch >= '0' && ch <= '9' )
    {
       return ch;
    }else {
        char temp = ch - 'A' + 'a';
        return temp;
    }
}

//check palindrome
bool checkPalindrome(string str) {
    int st = 0, end = str.length()-1;

    while (st <= end)
    {
        if (str[st] != str[end])
        {
            return 0;
        }else {
            st++;
            end--;
        }
    } 
    return 1;
}

// MAIN WORK: Valid Palindrome : Leetcode 125
bool isPalindrome(string s) {

    //step-1: faltu characters hatao
    string temp = "";
    for (int i = 0; i < s.length(); i++) {
        if (valid(s[i])) {
            temp.push_back(s[i]);
        }
    }
    
    //step-2: lower case me kardo
    for (int i = 0; i < temp.length(); i++) {
        temp[i] = toLowerCase(temp[i]);
    }
    
    //step-3: check palindrome
    return checkPalindrome(temp);
}

int main() {
    string str = "A man, a plan, a canal: Panama";  //true: "amanaplanacanalpanama" is a palindrome

    cout<<isPalindrome(str);
    return 0;
}