#include <iostream>
#include <climits>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Helper structure to store information for each subtree
struct Info {
    bool isBST;       // Whether the current subtree is a BST
    int size;         // Size of the subtree
    int minVal;       // Minimum value in the subtree
    int maxVal;       // Maximum value in the subtree
    int maxBSTSize;   // Size of the largest BST in the subtree
};

// Helper function to find the largest BST in a binary tree
Info findLargestBST(TreeNode* root) {
    // Base case: An empty tree is a BST of size 0
    if (!root) {
        return {true, 0, INT_MAX, INT_MIN, 0};
    }

    // Recursively get information about the left and right subtrees
    Info leftInfo = findLargestBST(root->left);
    Info rightInfo = findLargestBST(root->right);

    // Initialize current subtree information
    Info currInfo;
    currInfo.size = 1 + leftInfo.size + rightInfo.size;

    // Check if the current subtree is a BST
    if (leftInfo.isBST && rightInfo.isBST && 
        root->data > leftInfo.maxVal && root->data < rightInfo.minVal) {
        currInfo.isBST = true;
        currInfo.minVal = min(root->data, leftInfo.minVal);
        currInfo.maxVal = max(root->data, rightInfo.maxVal);
        currInfo.maxBSTSize = currInfo.size;
    } else {
        currInfo.isBST = false;
        currInfo.maxBSTSize = max(leftInfo.maxBSTSize, rightInfo.maxBSTSize);
    }

    return currInfo;
}

// Main function to find the size of the largest BST
int largestBST(TreeNode* root) {
    return findLargestBST(root).maxBSTSize;
}

// Function to create a sample binary tree for testing
TreeNode* createSampleTree() {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(8);
    root->right->right = new TreeNode(7);
    return root;
}

int main() {
    cout<<endl;
    
    TreeNode* root = createSampleTree();

    cout << "Size of the largest BST is: " << largestBST(root) << endl;

    return 0;
}