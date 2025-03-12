#include <iostream>
#include <queue>
using namespace std;

//Find Kth Predecer and successor 
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        this->data =  val;
        left = NULL;
        right = NULL;
    }
};

void levelorderTraversal(Node* root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if(temp == NULL) {
            cout<<endl;

            if(!q.empty()) {
                q.push(NULL);
            }

        }else {
            cout<< temp->data <<" ";

            if(temp->left) {
                q.push(temp->left);
            }
            if(temp->right) {
                q.push(temp->right);
            }
        }
    }
}
 
Node* insertIntoBST(Node* &root, int data) {
    //base case
    if(root == NULL) {
        root = new Node(data);
        return root;
    }

    if(data < root->data) {
        root->left = insertIntoBST(root->left, data);

    }else {
        root->right = insertIntoBST(root->right, data);
    }

    return root;
}

void takeInput(Node* &root) {
    int data;
    cin>>data;

    while(data != -1) {
        insertIntoBST(root, data);
        cin>>data;
    }
}

void inorder(Node* root) {
    if(root == NULL) return ;

    inorder(root->left);
    cout<< root->data <<" ";
    inorder(root->right);
}

//Find Predecessor and Successor of key
pair<int, int> predecessorSuccessor(Node* root, int key) {
    //Find key
    Node* temp = root;
    int pred = -1;
    int succ = -1;

    while(temp->data != key) {

        if(temp->data > key) {
            succ = temp->data; //also temp->data can be successor
            temp = temp->left;
        }else {
            pred = temp->data;
            temp = temp->right;
        }
    }

    //Now finding pred and succ
    
    //pred : will be max value in left subtree
    Node* leftTree = temp->left;
    while(leftTree != NULL) {
        pred = leftTree->data;
        leftTree = leftTree->right; //going right for max val in left tree
    }

    //succ : will be min value in right subtree
    Node* rightTree = temp->right;
    while(rightTree != NULL) {
        succ = rightTree->data;
        rightTree = rightTree->left;
    }

    //return {pred, succ};
    pair<int, int> ans = make_pair(pred, succ);
    return ans;
}

int main() {
    cout<<endl;

    Node* root = NULL;

    cout<<"Enter the data for BST: ";
    takeInput(root);
    cout<<"Printing the BST: "<<endl;
    levelorderTraversal(root);
    cout<<"Inorder Traversal: ";
    inorder(root);

    pair<int, int> ans = predecessorSuccessor(root, 5);
    cout<<endl<<"Predecessor is: "<< ans.first <<endl;
    cout<<"Successor is: "<< ans.second <<endl;
    return 0;
}