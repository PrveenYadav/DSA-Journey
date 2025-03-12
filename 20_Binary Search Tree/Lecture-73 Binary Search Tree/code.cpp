#include <iostream>
#include <queue>
using namespace std;

//Largest BST in a Binary Tree : return size(number of nodes)

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

//when we use struct type then * is not need to use
struct info {
public:
    int max;
    int min;
    bool isBST;
    int size;
};

void levelorder(Node* root) {
    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        cout<< temp->data <<" ";

        if(temp->left) {
            q.push(temp->left);
        }
        if(temp->right) {
            q.push(temp->right);
        }
    }
}

Node* insert(Node* &root, int data) {
    if(root == NULL) {
        root = new Node(data);
        return root;
    }

    if(data < root->data) {
        root->left = insert(root->left, data);
    }else {
        root->right = insert(root->right, data);
    }

    return root;
}


info solve(Node* root, int &ans) {
    //base case
    if(root == NULL) {
        return {INT8_MIN, INT8_MAX, true, 0};
    }

    info left = solve(root->left, ans);
    info right = solve(root->right, ans);

    info currNode;

    currNode.size = left.size + right.size + 1;
    currNode.max = max(root->data, right.max);
    currNode.min = min(root->data, left.min);

    if(left.isBST && right.isBST && (root->data > left.max && root->data < right.min)) {
        currNode.isBST = true;
    }else {
        currNode.isBST = false;
    }

    //answer update
    if(currNode.isBST) {
        ans = max(ans, currNode.size);
    }

    return currNode;
}

info largestBST(Node* root) {
    int ans = 0;
    return solve(root, ans);
}

int main() {
    cout<<endl;

    Node* root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);

    cout<<"Level order: ";
    levelorder(root);

    cout<<endl<<"Largest BST size: ";
    cout<< largestBST(root).size <<endl;
    return 0;
}