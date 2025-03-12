#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;

//Problem: Implement a phone directory

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


    void printSuggestions(TrieNode* curr, vector<string> &temp, string prefix) {

        if(curr->endOfTheWord) {
            temp.push_back(prefix);
        }

        for(char ch = 'a'; ch <= 'z'; ch++) {

            TrieNode* next = curr->children[ch - 'a'];

            if(next != NULL) {
                prefix.push_back(ch);
                printSuggestions(next, temp, prefix);
                prefix.pop_back();
            }
        }
    }

    vector<vector<string>> getSuggestions(string str) {
        TrieNode* prev = root;
        vector<vector<string>> output;
        string prefix = "";

        for(int i=0; i<str.length(); i++) {
            char lastCh = str[i];

            prefix.push_back(lastCh);

            //check for last ch
            TrieNode* curr = prev->children[lastCh - 'a'];

            //if not found
            if(curr == NULL) break;

            //if found
            vector<string> temp;
            printSuggestions(curr, temp, prefix);

            output.push_back(temp);
            temp.clear();
            prev = curr;
        }
        return output;
    }
};

//Implement a phone directory
vector<vector<string>> phoneDirectory(vector<string> &contactList, string queryStr) {
    
    //creation of trie
    Trie* t = new Trie('\0');

    //insert all contacts in trie
    for(int i=0; i<contactList.size(); i++) {
        string str = contactList[i];
        t->insert(str);
    }

    //return ans
    return t->getSuggestions(queryStr);
}

int main() {
    cout<<endl;

    vector<string> arr = {"cod", "coding", "codding", "code", "coly"};
    int n = arr.size();
    string queryStr = "cod";
    
    vector<vector<string>> ans = phoneDirectory(arr, queryStr);
    cout<<"Printing Results for word: "<< queryStr <<endl;
    for(auto i : ans) {  //printing 2d vector, you often forget
        for(auto j : i) {
            cout<< j <<" ";
        }cout<<endl;
    }cout<<endl;

    return 0;
}