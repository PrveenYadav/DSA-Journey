#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//Boundry Traversal of Binary Tree
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


void traverseLeft(Node* root, vector<int> &ans) {
    //base case
    if(root == NULL) return ;
    if(root->left == NULL && root->right == NULL) return ;

    ans.push_back(root->val);
    if(root->left) {
        traverseLeft(root->left, ans);
    }else {
        traverseLeft(root->right, ans);
    } 
}

void traverseLeaf(Node* root, vector<int> &ans) {
    //base case
    if(root == NULL) return ;
    if(root->left == NULL && root->right == NULL) {
        ans.push_back(root->val);
        return ;
    }  

    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);
} 

void traverseRight(Node* root, vector<int> &ans) {
    //base case
    if(root == NULL) return ;
    if(root->left == NULL && root->right == NULL) return ;

    if(root->right) { //if root->right exist
        traverseRight(root->right, ans);
    }else{
        traverseRight(root->left, ans);
    }

    //after traversing when coming back then print
    ans.push_back(root->val);
}

vector<int> boundry(Node* root) {
    vector<int> ans;
    if(root == NULL) return ans;

    ans.push_back(root->val);

    //left part print/store
    traverseLeft(root->left, ans);

    //traverse leaf node: 1. in left subtree, 2. right subtree
    //left subtree
    traverseLeaf(root->left, ans);
    //right subtree
    traverseLeaf(root->right, ans);

    //traverse right part
    traverseRight(root->right, ans);

    return ans;
}

int main() {
    cout<<endl;

    Node* root = NULL;

    //1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
    buildFromLevelorder(root); 
    cout<<endl<<"Level order Traversal"<<endl;
    levelorderTraversal(root);

    boundry(root);
    cout<<"Boundry Traversal of Tree: ";
    for(auto i : boundry(root)) {
        cout<< i <<" ";
    }
    cout<<endl;
    return 0;
}