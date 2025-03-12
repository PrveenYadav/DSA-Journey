#include <iostream>
#include <vector>
using namespace std;


void solve(string &str, int index, vector<string> &ans) {

    //base case
    if(index >= str.size()) {
        ans.push_back(str);
        return ;
    }


    for(int j=index; j<str.size(); j++) {
        swap(str[index], str[j]);
        solve(str, index+1, ans);
        
        //backtrack 
        swap(str[index], str[j]);
    }
}


//Permutations : Permutation of string : Leetcode 46 (medium)
vector<string> permuteString(string &str) {

    vector<string> ans;
    int index = 0;
    solve(str, index, ans);
    return ans;
}

int main() {
    cout<<endl;

    string str = "abc";
    vector<string> result = permuteString(str);

    for (const string &permute : result) {
        cout << "\"" << permute << "\" ";
    }
    cout << endl;

    return 0;
}