#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 1. Two Sum in BST
bool findTarget(TreeNode* root, int k) {
    vector<int> inorder;
    inorderTraversal(root, inorder);

    int left = 0;
    int right = inorder.size() - 1;

    while (left < right) {
        int sum = inorder[left] + inorder[right];
        if (sum == k) {
            return true;
        } else if (sum < k) {
            left++;
        } else {
            right--;
        }
    }

    return false;
}

void inorderTraversal(TreeNode* root, vector<int>& inorder) {
    if (root == nullptr) {
        return;
    }

    inorderTraversal(root->left, inorder);
    inorder.push_back(root->val);
    inorderTraversal(root->right, inorder);
}

/*
// 2. Flatten BST to a Sorted List
TreeNode* flatten(TreeNode* root) {
    if (root == nullptr) {
        return nullptr;
    }

    vector<TreeNode*> nodes;
    inorderTraversal(root, nodes);

    TreeNode* head = nodes[0];
    for (int i = 0; i < nodes.size() - 1; ++i) {
        nodes[i]->right = nodes[i + 1];
        nodes[i]->left = nullptr;
    }

    return head;
}
*/

// 3. Normal BST to a Balanced BST
TreeNode* balanceBST(TreeNode* root) {
    vector<int> inorder;
    inorderTraversal(root, inorder);

    return constructBalancedBST(inorder, 0, inorder.size() - 1);
}

TreeNode* constructBalancedBST(vector<int>& nums, int left, int right) {
    if (left > right) {
        return nullptr;
    }

    int mid = left + (right - left) / 2;
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = constructBalancedBST(nums, left, mid - 1);
    root->right = constructBalancedBST(nums, mid + 1, right);

    return root;
}


// 4. Preorder Traversal of a BST
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> result;
    preorder(root, result);
    return result;
}

void preorder(TreeNode* root, vector<int>& result) {
    if (root == nullptr) {
        return;
    }

    result.push_back(root->val);
    preorder(root->left, result);
    preorder(root->right, result);
}


int main() {
    // Create a sample BST
    TreeNode* root = new TreeNode(50);
    root->left = new TreeNode(30);
    root->right = new TreeNode(70);
    root->left->left = new TreeNode(20);
    root->left->right = new TreeNode(40);
    root->right->left = new TreeNode(60);
    root->right->right = new TreeNode(80);

    // Test Two Sum in BST
    int targetSum = 90;
    if (findTarget(root, targetSum)) {
        cout << "Two nodes found that sum to " << targetSum << endl;
    } else {
        cout << "No two nodes found that sum to " << targetSum << endl;
    }

/*
    // Test Flatten BST
    TreeNode* flattenedRoot = flatten(root);
    cout << "Flattened BST: ";
    TreeNode* current = flattenedRoot;
    while (current != nullptr) {
        cout << current->val << " ";
        current = current->right;
    }
    cout << endl;
*/
    // Test Balance BST
    TreeNode* balancedRoot = balanceBST(root);
    cout << "Inorder traversal of balanced BST: ";
   // inorderTraversal(balancedRoot);
    cout << endl;

    // Test Preorder Traversal
    vector<int> preorder = preorderTraversal(root);
    cout << "Preorder traversal: ";
    for (int val : preorder) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}