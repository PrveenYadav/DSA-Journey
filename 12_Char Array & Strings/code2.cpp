#include <iostream>
#include <string>
using namespace std;

//Home work => Reverse words in a string 2 : Leetcode 186 medium(premium) 

//Problem: maximum occurance 
char getMaxOccChar(string s) {
    int arr[26] = {0};

    //create an array of count of characters
    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];

        //lowercase
        int number = 0;
        number = ch - 'a';
        arr[number]++;
    }
    
    //maximum occurance
    int maximum = -1, ans = 0;
    for (int i = 0; i < 26; i++) {
        if (maximum < arr[i])
        {
            ans = i;
            maximum = arr[i];
        }
    }
    return 'a' + ans;
}

int main() {
    //char s[150] = 't','h','e',' ','s','k','y',' ','i','s',' ','b','l','a','c','k';
    
    string s;
    cin>>s;

    cout<<getMaxOccChar(s);
    return 0;
}