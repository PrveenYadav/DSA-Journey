#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    //constructor
    Node (int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

//Building Tree in Simple method
Node* buildTree(Node* root) {

    int val;
    cin>>val;
    root = new Node(val);

    if(val == -1) {
        return NULL;
    }

    root->left = buildTree(root->left);
    root->right = buildTree(root->right);
    
    return root;
}


//helper function for inorder
void inorder(Node* root, vector<int> &ans) {  //LNR
    //base case
    if(root == NULL) {
        return ;
    }

    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);
}

//Inorder Traversing if vector
vector<int> inorderTraversal(Node* root) {
    vector<int> ans;
    inorder(root, ans);
    return ans;
}


//PreOrder Traversing 
void preorderTraversal(Node* root) {  //NLR
    //base case
    if(root == NULL) {
        return ;
    }

    cout<< root->data <<" ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

//PostOrder Traversing 
void postOrderTraversal(Node* root) {  //LRN
    //base case
    if(root == NULL) {
        return ;
    }

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<< root->data <<" ";
}

//Preorder Traversal Iterativaly
vector<int> preorderTraversalIterativaly(Node* root) {
    vector<int> result;
    if (root == NULL) {
        return result; // If the tree is empty, return an empty vector.
    }

    stack<Node*> s;
    s.push(root);

    while (!s.empty()) {
        Node* current = s.top();
        s.pop();

        // Add the value of the current node to the result
        result.push_back(current->data);

        // Push the right child first, so the left child is processed first
        if (current->right) {
            s.push(current->right);
        }
        if (current->left) {
            s.push(current->left);
        }
    }

    return result;
}

int main() {
    cout<<endl;

    Node* root = NULL;

    //creating a tree
    cout<<"Enter the data: ";
    root = buildTree(root);

    //Input: 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 : Binary Tree is - 1 3 7 11 5 17

    cout<<endl<<"Inorder Traversal: "; //Tree will be - 7 3 11 1 17 5
    vector<int> ans = inorderTraversal(root);
    for(auto i : ans) {
        cout<< i <<" ";
    }

    cout<<endl<<"Preorder Traversal: ";
    preorderTraversal(root);   //Tree will be - 1 3 7 11 5 17

    cout<<endl<<"Preorder Traversal Iterativaly: ";
    vector<int> result = preorderTraversalIterativaly(root);
    for(auto i : result) {
        cout<< i <<" ";
    }
    
    cout<<endl<<"Postorder Traversal: ";
    postOrderTraversal(root);   //Tree will be - 7 11 3 17 5 1
    cout<<endl;
    return 0;
}