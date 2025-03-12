#include <iostream>
#include <vector>
#include <string>
using namespace std;

//function for Recursion
void solve(string str, string output, int index, vector<string> &ans) {

    //base case
    if(index >= str.size()) {
        ans.push_back(output);
        return ;
    }

    //Exclude
    solve(str, output, index+1, ans);

    //Include
    char element = str[index];
    output.push_back(element);
    solve(str, output, index+1, ans); 
}

//Subsequence of String
vector<string> subsequence(string str) {

    vector<string> ans;
    string output;
    int index = 0;
    solve(str, output, index, ans);
    return ans;
}

int main() {
    cout<<endl;

    string str = "abc";
    vector<string> result = subsequence(str);

    cout << "All subsequences:\n";
    for (const string &subsequence : result) {
        cout << "\"" << subsequence << "\" ";
    }
    cout << endl;

    return 0;
}
