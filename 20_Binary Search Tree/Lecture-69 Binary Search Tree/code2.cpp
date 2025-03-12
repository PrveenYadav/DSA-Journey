#include <iostream>
#include <queue>
using namespace std;

//Search in BST
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


//Search in BST Recursive way : Time & Space Complexity O(h) means O(log n)
bool searchInBST(Node* root, int x) {
    //base case
    if(root == NULL) return false;

    if(root->data == x) return true;

    if(x < root->data) {
        //in left part
        return searchInBST(root->left, x);
    }else {
        return searchInBST(root->right, x);
    }
}

//Search in BST Iterative way: space optimized
bool searchIterativaly(Node* root, int x) {
    
    Node* temp = root;
    
    while(temp != NULL) {
        if(temp->data == x) return true;

        if(x < temp->data) {
            temp = temp->left;
        }else {
            temp = temp->right;
        }
    }
    return false;
}


int main() {
    cout<<endl;

    Node* root = NULL;

    //5 4 7 3 8 9 -1
    cout<<"Enter the data for BST: ";
    takeInput(root);
    
    cout<<"Printing the BST: "<<endl;
    levelorderTraversal(root);


    if(searchInBST(root, 2)) {
        cout<<"Present"<<endl;
    }else {
        cout<<"Not Present"<<endl;
    }
    return 0;
}