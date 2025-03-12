#include <iostream>
#include <queue>
using namespace std;

//Que: Home Work - Moris Traversal
//Que: Flatten binary tree to linked list

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node (int data) {
        this->val = data;
        left = NULL;
        right = NULL;
    }
};

//build tree using recursion
Node* buildTree(Node* &root) {

    int data;
    cin>>data;
    root = new Node(data);

    if(data == -1) {
        return NULL;
    }

    root->left = buildTree(root->left);
    root->right = buildTree(root->right);

    return root;
}

void buildFromLevelorder(Node* &root) {
    queue<Node*> q;
    
    cout<<"Enter the data: ";
    int data;
    cin>>data;
    root = new Node(data);
    q.push(root);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        //cout<<"Enter left node for "<< temp->val <<endl;
        int leftData;
        cin>>leftData;
        if(leftData != -1) {
            temp->left = new Node(leftData);
            q.push(temp->left);
        }

        //cout<<"Enter right node for "<< temp->val <<endl;
        int rightData;
        cin>>rightData;
        if(rightData != -1) {
            temp->right = new Node(rightData);
            q.push(temp->right);
        }
    }
}

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
            cout<< temp->val <<" ";

            if(temp->left) {
                q.push(temp->left);
            }

            if(temp->right) {
                q.push(temp->right);
            }
        }
    }
}


void flatten(Node* root) {
    Node* curr = root;
    while(curr != NULL) {

        if(curr->left) {
            
            Node* prev = curr->left;
            while(prev->right) {
                prev = prev->right;
            }
            prev->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr = curr->right;
    }
}


void preorder(Node* root) {
    if(root == NULL) return;
    cout<< root->val <<" ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    cout<<endl;

    Node* root = NULL;
    // 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
    buildFromLevelorder(root);
    //buildTree(root);
    cout<<"Level order Traversal: "<<endl;
    levelorderTraversal(root);

    cout<<"Flatten Node: ";
    flatten(root);   
    preorder(root);
    return 0;
}