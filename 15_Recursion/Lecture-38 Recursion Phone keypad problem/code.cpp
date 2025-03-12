#include <iostream>
#include <vector>
using namespace std;

void solve(string digits, string output, int index, vector<string> &ans, string mapping[]) {

    //base case
    if(index >= digits.length()) {
        ans.push_back(output);
        return ;
    }

    //Excluding and mapping
    int number = digits[index] - '0';
    string value = mapping[number];

    //Recursive call
    for(int i=0; i<value.length(); i++) {
        output.push_back(value[i]);
        solve(digits, output, index+1, ans, mapping);
        output.pop_back();
    }
}

//Question asked in Google, microsoft, amazon, apple, uber, oracle, adobe, sumsung, intuit etc.
//Letter combination of a phone number : Leetcode 17 (medium)
vector<string> letterCombination(string digits) {

    vector<string> ans;
    if(digits.length() == 0) return ans;
    string output;
    int index = 0;
    string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    solve(digits, output, index, ans, mapping);
    return ans;
}


int main() {
    cout<<endl;

    string str = "23";
    vector<string> result = letterCombination(str);

    for (const string &letterComb : result) {
        cout << "\"" << letterComb << "\" ";
    }
    cout << endl;

    return 0;
}
