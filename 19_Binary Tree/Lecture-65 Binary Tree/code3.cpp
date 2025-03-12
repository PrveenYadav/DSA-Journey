#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//Kth Ancestor in a tree
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


Node* solve(Node* root, int &k, int node) {
    //base case
    if(root == NULL) return NULL;
    if(root->val == node) return root;

    Node* leftAns = solve(root->left, k, node);
    Node* rightAns = solve(root->right, k, node);

    if(leftAns != NULL && rightAns == NULL) {
        k--;
        if(k<=0) {
            //answer lock
            k = INT8_MAX;
            return root;
        }
        return leftAns;
    }

    if(leftAns == NULL && rightAns != NULL) {
        k--;
        if(k<=0) {
            //answer lock
            k = INT8_MAX;
            return root;
        }
        return rightAns;
    }
    return NULL;
}

int kthAncestor(Node* root, int k, int node) {
    Node* ans = solve(root, k, node);
    if(ans == NULL || ans->val == node) {
        return -1;
    }else {
        return ans->val;
    }
}

int main() {
    cout<<endl;

    Node* root = NULL;

    //1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
    buildFromLevelorder(root); 
    cout<<endl<<"Level order Traversal"<<endl;
    levelorderTraversal(root);

    cout<<"Kth Ancestor: "<< kthAncestor(root, 2, 4);
    
    return 0;
}