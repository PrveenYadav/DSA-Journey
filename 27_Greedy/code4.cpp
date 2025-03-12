#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Reverse Words

string reverseWords1(string s) {
    vector<string> words;
    string word;
    int i = 0, n = s.length();
    
    // Extract words manually without using stringstream
    while (i < n) {
        while (i < n && s[i] == ' ') i++; // Skip leading spaces
        if (i >= n) break;
        int start = i;
        while (i < n && s[i] != ' ') i++; // Find end of word
        words.push_back(s.substr(start, i - start));
    }
    
    // Reverse the order of words
    reverse(words.begin(), words.end());
    
    // Construct the result string
    string result;
    for (int i = 0; i < words.size(); i++) {
        if (i > 0) result += " ";
        result += words[i];
    }
    
    return result;
}

int main() {
    cout<<endl;
    string str = " i like this program very much ";
    //output = "much very program this like i"

    // string ans = reverseWords(str);
    // for(int i=0; i<str.length(); i++) {
    //     cout<< ans[i] <<" ";
    // }cout<<endl;
    cout<<"Reverse Words: "<< reverseWords1(str) <<endl;
    return 0;
}