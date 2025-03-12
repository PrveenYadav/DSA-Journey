#include <iostream>
using namespace std;

//Trie Implementation : Home Work write code for deletion 
//Time complexity: insertion/deletion/searching = O(l) where l is the length of word
class TrieNode {
public: 
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch) {
        data = ch;
        for(int i=0; i<26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
public: 
    TrieNode* root;

    Trie() {
        root = new TrieNode('\0');  //intialize with null to root node
    }

    void insertUtil(TrieNode* root, string word) {
        //base case
        if(word.length() == 0) {
            root->isTerminal = true; //reach at last then terminal marks true
            return ;
        }

        //assumption, that words will be in capital
        int index = word[0] - 'A'; //index of first character
        TrieNode* child;

        //present: then moving farword
        if(root->children[index] != NULL) {
            child = root->children[index];
        }else {
            //absent: then create a new node and move farword
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        //Recursive call
        insertUtil(child, word.substr(1));
    }

    void insertWord(string word) {
        insertUtil(root, word);
    }

    bool searchUtil(TrieNode* root, string word) {
        //base case
        if(word.length() == 0) {
            return root->isTerminal;
        }

        int index = word[0] - 'A';
        TrieNode* child;

        //present
        if(root->children[index] != NULL) {
            child = root->children[index];
        }else {
            //absent
            return false;
        }

        //Recursive call 
        return searchUtil(child, word.substr(1));
    }

    bool searchWord(string word) {
        searchUtil(root, word);
    }
};

int main() {
    cout<<endl;

    Trie* t = new Trie();
    t->insertWord("ARM");
    t->insertWord("DO");
    t->insertWord("TIME");

    cout<<"Present or Not: "<< t->searchWord("ARM") <<endl;
    return 0;
}