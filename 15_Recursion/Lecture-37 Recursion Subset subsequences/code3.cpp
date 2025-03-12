#include <iostream>
#include <vector>
#include <string>

using namespace std;

void generateSubsequences(int index, string &s, string current, vector<string> &result) {
    // Base case: if we've considered all characters
    if (index == s.size()) {
        result.push_back(current);
        return;
    }

    // Case 1: Exclude the current character and move to the next
    generateSubsequences(index + 1, s, current, result);

    // Case 2: Include the current character and move to the next
    current.push_back(s[index]);
    generateSubsequences(index + 1, s, current, result);
}

vector<string> subsequences(string s) {
    vector<string> result;
    generateSubsequences(0, s, "", result);
    return result;
}

int main() {
    string s = "abc";
    vector<string> result = subsequences(s);

    cout << "All subsequences:\n";
    for (const string &subsequence : result) {
        cout << "\"" << subsequence << "\" ";
    }
    cout << endl;

    return 0;
}
