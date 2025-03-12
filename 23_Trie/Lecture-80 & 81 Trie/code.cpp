#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;

//Lowest Common Prefix
class TrieNode {
public:
    char data;
    TrieNode* children[26];
    bool endOfTheWord;
    int childCount;

    TrieNode(char ch) {
        data = ch;
        for(int i=0; i<26; i++) {
            children[i] = NULL;
        }
        endOfTheWord = false;
        childCount = 0;
    }
};

class Trie {
public: 
    TrieNode* root;

    Trie(char ch) {
        root = new TrieNode(ch);
    }

    void insertUtil(TrieNode* root, string word) {
        //base case
        if(word.length() == 0) {
            root->endOfTheWord = true;
            return ;
        }

        int index = word[0] - 'a';
        TrieNode* child;

        if(root->children[index] != NULL) {
            child = root->children[index];
        }else {
            child = new TrieNode(word[0]);
            root->childCount++;
            root->children[index] = child;
        }

        insertUtil(child, word.substr(1));
    }

    void insert(string word) {
        insertUtil(root, word);
    }

    void lcp(string str, string &ans) {

        for(int i=0; i<str.length(); i++) {
            char ch = str[i];

            if(root->childCount == 1) {
                ans.push_back(ch);
                
                //moving farword
                int index = ch - 'a';
                root = root->children[index];
            }else {
                break;
            }

            if(root->endOfTheWord) break;
        }
    }
};

//It is better than TRIE, Time O(m*n) and space O(1)
string longestCommonPrefixSimple(vector<string> &arr, int n) {
    string ans = "";

    //traversing all string 
    for(int i=0; i<arr[0].length(); i++) {
        char ch = arr[0][i];
        bool match = true;

        //for comparing ch from the rest of the string 
        for(int j=0; j<n; j++) {
            if(arr[j].size() < i || ch != arr[j][i]) {
                match = false;
                break;
            }
        }
        if(match == false) {
            break;
        }else {
            ans.push_back(ch);
        }
    }
    return ans;
}

//Using Trie: Time O(m*n) and space O(m*n) : while child == 1 then store in ans and move, if child more than 1 then return ans
string longestCommonPrefix(vector<string> &arr, int n) {

    Trie* t = new Trie('\0');
    for(int i=0; i<n; i++) {
        t->insert(arr[i]);
    }

    string first = arr[0];
    string ans = "";

    t->lcp(first, ans);
    return ans;
}

int main() {
    cout<<endl;

    vector<string> arr = {"code", "codence", "codebase", "coding"};
    int n = arr.size();

    cout<<"Longest common prefix: "<< longestCommonPrefixSimple(arr, n) <<endl;
    cout<<"LCP using Trie is: "<< longestCommonPrefix(arr, n) <<endl;

    return 0;
}