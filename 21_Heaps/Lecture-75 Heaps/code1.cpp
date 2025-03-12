#include <iostream>
#include <queue>
using namespace std;

//Problem: Is Binary Tree Heap
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

Node* buildFromLevelOrder(Node* &root) {
    queue<Node*> q;
    int data;
    cin>>data;
    root = new Node(data);
    q.push(root);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        int leftInput;
        cin>>leftInput;
        if(leftInput != -1) {
            temp->left = new Node(leftInput);
            q.push(temp->left);
        }

        int rightInput;
        cin>>rightInput;
        if(rightInput != -1) {
            temp->right = new Node(rightInput);
            q.push(temp->right);
        }
    }
}

void levelorder(Node* root) {
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
        }
        else {
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


int countNodes(Node* root) {
    if(root == NULL) return 0;

    int ans = countNodes(root->left) + countNodes(root->right) + 1;
    return ans;
}

bool isCBT(Node* root, int index, int cnt) {
    if(root == NULL) return true;

    if(index >= cnt) {
        return false;
    }
    else{
        bool left = isCBT(root->left, 2*index+1, cnt);
        bool right = isCBT(root->right, 2*index+2, cnt);
        return (left && right);
    }
}

bool isMaxorder(Node* root) {
    //check for leaf node
    if(root->left == NULL && root->right == NULL) return true;

    if(root->right == NULL) {
        return (root->data > root->left->data);
    }
    else {
        bool left = isMaxorder(root->left);
        bool right = isMaxorder(root->right);

        if(left && right && root->data > root->left->data && root->data > root->right->data) {
            return true;
        }else {
            return false;
        }
        //or we can write this one line for line 52-56
        // return (left && right && root->data > root->left->data && root->data > root->right->data);
    }
}

//Problem: Is Binary Tree Heap
bool isHeap(Node* root) {
    int index = 0;
    int totalCount = countNodes(root);

    //checking CBT(complete binary tree) or not && checking that, following max order property of heap
    if(isCBT(root, index, totalCount) && isMaxorder(root)) {
        return true;
    }else {
        return false;
    }
}

int main() {
    cout<<endl;

    Node* root = NULL;

    //5 4 3 2 1 -1 -1 -1 -1 -1 -1 OR 1 2 3 4 5 -1 -1 -1 -1 -1 -1 
    cout<<"Enter the data: ";
    buildFromLevelOrder(root);
    cout<<"Tree is: "<<endl;
    levelorder(root);

    if(isHeap(root)) { //this checks binary tree for max heap it will give false for min heap
        cout<<"Yes, Binary tree is Heap"<<endl;
    }else {
        cout<<"No, Binary tree is not Heap"<<endl;
    }
    return 0;
}