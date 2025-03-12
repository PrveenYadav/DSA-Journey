#include <iostream>
#include <queue>
#include <vector>
using namespace std;

//Home Work: and watch in the last of lectur-75: Convert BST to Min Heap : and given bst is also a complete binary tree
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

Node* insertInBST(Node* &root, int val) {
    if(root == NULL) {
        root = new Node(val);
        return root;
    }

    if(val < root->data) {
        root->left = insertInBST(root->left, val);
    }else {
        root->right = insertInBST(root->right, val);
    }

    return root;
} 

//it will give the sorted order of bst
void inorder(Node* root, vector<int> in) {
    if(root == NULL) return;

    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

void preorder(Node* root, vector<int> in, int index) {
    if(root == NULL) return ;

    root->data = in[index++];
    preorder(root->left, in, index);
    preorder(root->right, in, index);

}

// vector<int> convertBSTintoMinHeap(vector<int> &arr, int n) {
//     vector<int> ans;
//     inorder()
// }

int main() {
    cout<<endl;

    Node* root = NULL;
    //Input: 4 2 6 1 3 5 7
    //Output: 1 2 5 3 4 6 7
    insertInBST(root, 4);
    insertInBST(root, 2);
    insertInBST(root, 6);
    insertInBST(root, 1);
    insertInBST(root, 3);
    insertInBST(root, 5);
    insertInBST(root, 7);

    cout<<"Inorder BST is: ";
    //inorder(root);

    return 0;
}