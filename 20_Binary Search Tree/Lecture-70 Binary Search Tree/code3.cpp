#include <iostream>
#include <queue>
using namespace std;

//LCA in BST : Least/Lowest common ancestor of two nodes
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


Node* LCAinBST(Node* root, Node* P, Node* Q) {
    //base case
    if(root == NULL) return NULL;

    if(root->data < P->data && root->data < Q->data) {
        return LCAinBST(root->right, P, Q);
    }
    if(root->data > P->data && root->data > Q->data) {
        return LCAinBST(root->left, P, Q);
    }

    return root;
}

//space optimized in Iterative way
Node* LCAinBST1(Node* root, Node* P, Node* Q) {

    while(root != NULL) {
        
        if(root->data < P->data && root->data < Q->data) {
            root = root->right;
        }
        else if(root->data > P->data && root->data > Q->data) {
            root = root->left;
        }
        else {
            return root;
        }
    }
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

    Node* P = new Node(3);
    int p = P->data;
    Node* Q = new Node(8);
    int q = Q->data;
    Node* LCA = LCAinBST(root, P, Q);
    cout<<endl<<"LCA in a BST: "<< LCA->data <<endl;
    return 0;
}