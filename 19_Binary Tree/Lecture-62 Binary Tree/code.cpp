#include <iostream>
#include <queue>
using namespace std;

//Binary Tree Implementation

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

//Taking input for making a binary tree
Node* buildTree(Node* root) {

    cout<<"Enter the data: ";
    int val;
    cin>>val;
    root = new Node(val);

    if(val == -1) {
        return NULL;
    }

    cout<<"Enter data for inserting in left of ";
    root->left = buildTree(root->left);
    cout<<"Enter data for inserting in right of ";
    root->right = buildTree(root->right);
    
    return root;
}


//Level Order Traversing
void levelOrderTraversal(Node* root) {

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if(temp == NULL) {
            //previous level is completly traversed
            cout<<endl;

            if(!q.empty()) {  //Queue still has some child nodes
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

//Inorder Traversing 
void inorderTraversal(Node* root) {  //LNR
    //base case
    if(root == NULL) {
        return ;
    }

    inorderTraversal(root->left);
    cout<< root->data <<" ";
    inorderTraversal(root->right);
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


//Build from Level Order / Taking input as level order
void buildFromLevelorder(Node* &root) {
    queue<Node*> q;

    cout<<"Enter data for root: ";
    int data;
    cin>>data;
    root = new Node(data);
    q.push(root);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        cout<<"Enter left node for "<< root->data <<endl;
        int leftData;
        cin>>leftData;

        if(leftData != -1) {
            temp->left = new Node(leftData);
            q.push(temp->left);
        }

        cout<<"Enter right node for "<< root->data <<endl;
        int rightData;
        cin>>rightData;

        if(rightData != -1) {
            temp->right = new Node(rightData);
            q.push(temp->right);
        }

    }

}

int main() {
    cout<<endl;

    Node* root = NULL;

    //creating a tree
    root = buildTree(root);

    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    cout<<"Level order Traversal"<<endl;
    levelOrderTraversal(root);

    cout<<"Inorder Traversal: ";
    inorderTraversal(root);   //Tree will be - 7 3 11 1 17 5

    cout<<"Preorder Traversal: ";
    preorderTraversal(root);   //Tree will be - 1 3 7 11 5 17
    
    cout<<"Postorder Traversal: ";
    postOrderTraversal(root);   //Tree will be - 7 11 3 17 5 1

    return 0;
}