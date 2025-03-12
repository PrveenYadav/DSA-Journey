#include <iostream>
#include <queue>
using namespace std;

//Problem : Validate BST
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


bool isBST(Node* &root, int min, int max) {
    //base case
    if(root == NULL) true;

    if(root->data >= min && root->data <= max) {
        bool left = isBST(root->left, min, root->data);
        bool right = isBST(root->right, root->data, max);
        return left && right;
    }else {
        return false;
    }
}

//Another one
bool isBST1(Node* root, int min, int max) {
    if(root == NULL) return true;

    if(root->data <= min || root->data >= max) {
        return false;
    }
    bool left = isBST1(root->left, min, root->data);
    bool right = isBST1(root->right, root->data, max);
    
    return left && right;
}

//validate BST
bool isValidateBST(Node* root) {
    return isBST(root, INT8_MIN, INT8_MAX);
}

int main() {
    cout<<endl;

    Node* root = NULL;

    // 5 4 7 3 8 9 -1
    //Implementation
    cout<<"Enter data for BST: ";
    takeInput(root);
    cout<<"Printing the BST: "<<endl;
    levelorderTraversal(root);

    isValidateBST(root);
    if(isValidateBST(root)) {
        cout<<"Tree is Validate"<<endl;
    }else {
        cout<<"Not Validate"<<endl;
    }
    return 0;
}