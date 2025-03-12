#include <iostream>
#include <queue>
#include <vector>
#include <unordered_set>
using namespace std;

//Problem: Two sum in BST: Given target and find is there any two nodes exist in BST which sum is equal to target

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        this->data = val;
        left = NULL;
        right = NULL;
    }
};

// Inorder traversal for storing values in a vector
void inorder(Node* root, vector<int> &in) {
    if (root == NULL) return;

    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

// Flatten BST into a sorted linked list
Node* flatten(Node* root) {
    vector<int> inorderVal;
    inorder(root, inorderVal); // Store inorder -> sorted value
    int n = inorderVal.size();

    if (n == 0) return NULL;

    Node* newRoot = new Node(inorderVal[0]);
    Node* curr = newRoot;

    for (int i = 1; i < n; i++) {
        Node* temp = new Node(inorderVal[i]);
        curr->left = NULL;
        curr->right = temp;
        curr = temp;
    }

    curr->left = NULL;
    curr->right = NULL; // Redundant but ensures safety
    return newRoot;
}


// Convert sorted inorder array to BST
Node* inorderToBST(int start, int end, vector<int> &inorderVal) {
    if (start > end) return NULL;

    int mid = start + (end - start) / 2;
    Node* root = new Node(inorderVal[mid]);
    root->left = inorderToBST(start, mid - 1, inorderVal);
    root->right = inorderToBST(mid + 1, end, inorderVal);

    return root;
}

// Convert a normal BST to a balanced BST
Node* balancedBST(Node* root) {
    vector<int> inorderVal;
    inorder(root, inorderVal); // Store inorder -> sorted value
    return inorderToBST(0, inorderVal.size() - 1, inorderVal);
}

// Check if there exist two elements in BST whose sum is equal to target
bool twoSumBST(Node* root, int target, unordered_set<int> &visited) {
    if (!root) return false;

    if (visited.count(target - root->data)) return true;
    visited.insert(root->data);

    return twoSumBST(root->left, target, visited) || twoSumBST(root->right, target, visited);
}

bool hasTwoSum(Node* root, int target) {
    unordered_set<int> visited;
    return twoSumBST(root, target, visited);
}

// Preorder Traversal
void preorder(Node* root) {
    if (!root) return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Helper to build a simple BST for testing
Node* insertIntoBST(Node* root, int val) {
    if (!root) return new Node(val);

    if (val < root->data) root->left = insertIntoBST(root->left, val);
    else root->right = insertIntoBST(root->right, val);

    return root;
}

int main() {
    cout<<endl;
    
    Node* root = NULL;
    root = insertIntoBST(root, 10);
    root = insertIntoBST(root, 5);
    root = insertIntoBST(root, 20);
    root = insertIntoBST(root, 3);
    root = insertIntoBST(root, 7);
    root = insertIntoBST(root, 15);

    cout << "Preorder Traversal: ";
    preorder(root);
    cout << endl;

    // Check Two Sum
    int target = 17;
    if (hasTwoSum(root, target)) {
        cout << "Found two nodes with sum " << target << endl;
    } else {
        cout << "No two nodes with sum " << target << " found" << endl;
    }

    // Flatten BST
    Node* flattenedRoot = flatten(root);
    cout << "Flattened BST to sorted list: ";
    while (flattenedRoot) {
        cout << flattenedRoot->data << " ";
        flattenedRoot = flattenedRoot->right;
    }
    cout << endl;

    // Balance BST
    Node* balancedRoot = balancedBST(root);
    cout << "Preorder of Balanced BST: ";
    preorder(balancedRoot);
    cout << endl;

    return 0;
}