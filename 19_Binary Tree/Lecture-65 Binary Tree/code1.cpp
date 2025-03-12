#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//Lowest common Ancestor in a binary tree
class Node {
public:
    int val;
    Node* left;
    Node* right;

    //constructor
    Node (int data) {
        val = data;
        left = NULL;
        right = NULL;
    }
};

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

        cout<<"Enter left node for "<< temp->val <<endl;
        int leftData;
        cin>>leftData;
        if(leftData != -1) {
            temp->left = new Node(leftData);
            q.push(temp->left);
        }

        cout<<"Enter right node for "<< temp->val <<endl;
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
                //root = NULL;
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


Node* lca(Node* root, int n1, int n2) {
    //base case
    if(root == NULL) return NULL;
    if(root->val == n1 || root->val == n2) return root;

    Node* leftAns = lca(root->left, n1, n2);
    Node* rightAns = lca(root->right, n1, n2);

    if(leftAns != NULL && rightAns != NULL) {
        return root;
    }else if(leftAns != NULL && rightAns == NULL) {
        return leftAns;
    }else if(leftAns == NULL && rightAns != NULL) {
        return rightAns;
    }else {
        return NULL;
    }
}

int main() {
    cout<<endl;

    Node* root = NULL;

    //1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
    buildFromLevelorder(root); 
    cout<<endl<<"Level order Traversal"<<endl;
    levelorderTraversal(root);

    Node* ans = lca(root, 4, 3);
    cout<<"Lowest common Ancestor: "<< ans->val;
    
    return 0;
}