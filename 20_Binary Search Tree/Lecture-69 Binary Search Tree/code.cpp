#include <iostream>
#include <queue>
using namespace std;

//Binary Search Tree Implementation
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node (int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

//for traversing 
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

    if(data > root->data) {
        //then insert in right part
        root->right = insertIntoBST(root->right, data);
    }else {
        //insert in left part
        root->left = insertIntoBST(root->left, data);
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


//we can print preorder, inorder and postorder
void preorder(Node* root) {
    if(root == NULL) return ;
    cout<< root->data <<" ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(Node* root) {
    if(root == NULL) return ;
    cout<< root->data <<" ";
    inorder(root->left);
    inorder(root->right);
}
void postorder(Node* root) {
    if(root == NULL) return ;
    cout<< root->data <<" ";
    postorder(root->left);
    postorder(root->right);
}

int main() {
    cout<<endl;

    Node* root = NULL;

    //10 8 21 7 27 5 4 3 -1
    cout<<"Enter data to create BST: ";
    takeInput(root);
    
    cout<<"Printing the BST"<<endl;
    levelorderTraversal(root);

    cout<<"Preorder: ";
    preorder(root);

    cout<<endl<<"Inorder: ";
    inorder(root);
    
    cout<<endl<<"Postorder: ";
    postorder(root);
    return 0;
}
