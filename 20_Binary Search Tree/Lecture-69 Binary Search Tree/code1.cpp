#include <iostream>
#include <queue>
using namespace std;

//Home work : Insertion in Binary Search Tree : Home work finished

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

//For Printing using level order traversal
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
        root->right = insertIntoBST(root->right, data);
    }else if(data < root->data){
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


//Insertion in BST : Time & Space Complexity O(h) means O(log n)
Node* insert(Node* root, int element) {
    //base case
    if(root == NULL) {
        root = new Node(element);
        return root;
    }
    if(root == NULL) return new Node(element);

    if(element < root->data) {
        root->left = insert(root->left, element);
    }else {
        root->right = insert(root->right, element);
    }
}

int main() {
    cout<<endl;

    Node* root = NULL;

    //Input: 5 4 7 3 8 9 -1
    cout<<"Enter the data for BST: ";
    takeInput(root);
    cout<<"Printing the BST: "<<endl;
    levelorderTraversal(root);

    cout<<endl;

    cout<<"After inserting a element in BST: "<<endl;
    insert(root, 2);
    levelorderTraversal(root);
    return 0;
}
