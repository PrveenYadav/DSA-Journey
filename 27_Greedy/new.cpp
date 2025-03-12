#include <iostream>
#include <vector>
#include <queue>
#include <string> // Include string header
using namespace std;

//Huffman encoding problem

class Node {
public:
    int data;
    char ch; // Store the character (optional, but helpful)
    Node* left;
    Node* right;

    Node(int val, char c = '\0') { // Initialize char in constructor
        data = val;
        ch = c;
        left = nullptr;
        right = nullptr;
    }
};

class cmp {
public:
    bool operator()(Node* a, Node* b) {
        return a->data > b->data;
    }
};

void traversal(Node* root, vector<string>& ans, string temp) {
    if (root == nullptr) return; // Handle null root (important for empty input)

    if (root->left == nullptr && root->right == nullptr) {
        ans.push_back(temp);
        return; // Important: Return after adding the code for a leaf node.
    }

    traversal(root->left, ans, temp + '0');
    traversal(root->right, ans, temp + '1');
}

vector<string> huffmanCodes(string S, vector<int> f, int N) {
    priority_queue<Node*, vector<Node*>, cmp> pq;

    for (int i = 0; i < N; i++) {
        if (f[i] > 0) { // Only add nodes for frequencies > 0
            Node* temp = new Node(f[i], S[i]); // Store character with the node
            pq.push(temp);
        }
    }

    if (pq.empty()) { // Handle empty input case
        return {}; // Return an empty vector
    }

    while (pq.size() > 1) {
        Node* left = pq.top();
        pq.pop();

        Node* right = pq.top();
        pq.pop();

        Node* newNode = new Node(left->data + right->data);
        newNode->left = left;
        newNode->right = right;
        pq.push(newNode);
    }

    Node* root = pq.top();
    vector<string> ans;
    string temp = "";

    traversal(root, ans, temp);
    return ans;
}

int main() {
    cout<<endl;
    
    string S = "abcdef";
    vector<int> f = {5, 9, 12, 13, 16, 45};
    int N = f.size();

    vector<string> ans = huffmanCodes(S, f, N);
    for (const string& code : ans) { // Use range-based for loop
        cout << code << " ";
    }
    cout << endl;

    return 0;
}