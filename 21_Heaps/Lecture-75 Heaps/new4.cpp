#include <iostream>
#include <vector>
using namespace std;

// Define the structure for a tree node
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function for in-order traversal to collect node values in sorted order
void inOrderTraversal(TreeNode* root, vector<int>& values) {
    if (root == nullptr) return;
    inOrderTraversal(root->left, values);
    values.push_back(root->data);
    inOrderTraversal(root->right, values);
}

// Function to build the Min Heap using a level-order traversal
void convertToMinHeap(TreeNode* root, vector<int>& values, int& index) {
    if (root == nullptr) return;
    root->data = values[index++];
    convertToMinHeap(root->left, values, index);
    convertToMinHeap(root->right, values, index);
}

// Helper function to convert BST to Min Heap
void bstToMinHeap(TreeNode* root) {
    if (root == nullptr) return;

    // Step 1: Perform in-order traversal to get sorted values
    vector<int> values;
    inOrderTraversal(root, values);

    // Step 2: Build Min Heap by assigning values in level-order
    int index = 0;
    convertToMinHeap(root, values, index);
}

// Utility function to perform level-order traversal and print tree
void printLevelOrder(TreeNode* root) {
    if (root == nullptr) return;
    vector<TreeNode*> queue = {root};
    while (!queue.empty()) {
        TreeNode* current = queue.front();
        queue.erase(queue.begin());
        cout << current->data << " ";
        if (current->left) queue.push_back(current->left);
        if (current->right) queue.push_back(current->right);
    }
    cout << endl;
}

// Main function
int main() {
    cout<<endl;

    // Create a sample BST
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);

    cout << "Original BST: ";
    printLevelOrder(root);

    // Convert BST to Min Heap
    bstToMinHeap(root);

    cout << "Min Heap: ";
    printLevelOrder(root);

    return 0;
}