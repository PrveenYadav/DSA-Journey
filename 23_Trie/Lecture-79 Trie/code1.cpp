#include <iostream>
#include <unordered_map>
using namespace std;

// Trie Node definition
struct TrieNode {
    unordered_map<char, TrieNode*> children; // Map to store child nodes
    bool isEndOfWord; // Indicates end of a valid word

    TrieNode() : isEndOfWord(false) {}
};

// Trie Class
class Trie {
private:
    TrieNode* root;

    // Helper function for deletion
    bool deleteHelper(TrieNode* node, const string& word, int depth) {
        if (!node) return false;

        // If last character of the word is being processed
        if (depth == word.length()) {
            if (!node->isEndOfWord) return false;
            node->isEndOfWord = false; // Mark the end of word as false

            // If the node has no children, delete it
            return node->children.empty();
        }

        // Recur for the child node
        char ch = word[depth];
        if (deleteHelper(node->children[ch], word, depth + 1)) {
            // If child is deleted, remove the character from the map
            delete node->children[ch];
            node->children.erase(ch);

            // Return true if the current node is now empty and not an end of another word
            return node->children.empty() && !node->isEndOfWord;
        }

        return false;
    }

public:
    // Constructor
    Trie() { root = new TrieNode(); }

    // Insert a word into the Trie
    void insert(const string& word) {
        TrieNode* currentNode = root;
        for (char ch : word) {
            if (!currentNode->children.count(ch)) {
                currentNode->children[ch] = new TrieNode();
            }
            currentNode = currentNode->children[ch];
        }
        currentNode->isEndOfWord = true;
    }

    // Search for a word in the Trie
    bool search(const string& word) {
        TrieNode* currentNode = root;
        for (char ch : word) {
            if (!currentNode->children.count(ch)) return false;
            currentNode = currentNode->children[ch];
        }
        return currentNode->isEndOfWord;
    }

    // Delete a word from the Trie
    void remove(const string& word) {
        deleteHelper(root, word, 0);
    }
};

int main() {
    Trie trie;

    // Insert words
    trie.insert("apple");
    trie.insert("app");
    trie.insert("apex");

    // Search for words
    cout << "Search 'app': " << (trie.search("app") ? "Found" : "Not Found") << endl;
    cout << "Search 'apex': " << (trie.search("apex") ? "Found" : "Not Found") << endl;

    // Delete a word
    trie.remove("app");
    cout << "Search 'app' after deletion: " << (trie.search("app") ? "Found" : "Not Found") << endl;
    cout << "Search 'apple' after deletion: " << (trie.search("apple") ? "Found" : "Not Found") << endl;

    return 0;
}