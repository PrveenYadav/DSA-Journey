#include <iostream>
#include <queue>
using namespace std;

//Problem: find min and max val of BST : Deletion in BST
//Note: Inorder of BST always comes in sorted order.

//Home Work: Inorder Predecessor(prev) and successor(next): Exa: for input 5 4 7 3 8 9, inorder is 3 4 5 7 8 9, and its predecessor(prev) for 5 is 3 and successor(next) is 7

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node (int val) {
        this->data = val;
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


int findMin(Node* root) {
    
    Node* temp = root;
    while(temp->left != NULL) {
        temp = temp->left;
    }

    return temp->data;
}
int findMax(Node* root) {
    
    Node* temp = root;
    while(temp->right != NULL) {
        temp = temp->right;
    }

    return temp->data;
}

//Note: Inorder of BST always comes in sorted order.
void inorder(Node* root) {
    if(root == NULL) return ;
    inorder(root->left);
    cout<< root->data <<" ";
    inorder(root->right);
}

int main() {
    cout<<endl;

    Node* root = NULL;

    //5 4 7 3 8 9 -1
    cout<<"Enter the data for BST: ";
    takeInput(root);
    
    cout<<"Printing the BST: "<<endl;
    levelorderTraversal(root);

    cout<<"Min val of BST is: "<< findMin(root) <<endl;
    cout<<"Max val of BST is: "<< findMax(root) <<endl;
    
    cout<<"Inorder: ";
    inorder(root);
    return 0;
}