#include <iostream>
#include <queue>
using namespace std;

// Problem: Diameter of a Binary Tree: Longest path between any two end nodes(root/leaf node)

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

    cout<<"Enter the data: ";
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

void levelOrderTraversal(Node* root) {
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


int height(Node* node) {
    //base case
    if(node == NULL) {
        return 0;
    }

    int left = height(node->left);
    int right = height(node->right);

    int ans = max(left, right) + 1;
    return ans;
}

//Time complexity is O(n2)
int diameter(Node* root) {

    //diameter can made in 3 ways: in left subtree, right subtree and combo of both
    if(root == NULL) {
        return 0;
    }

    int path1 = diameter(root->left);
    int path2 = diameter(root->right);
    int path3 = height(root->left) + height(root->right) + 1;

    int ans = max(path1, max(path2, path3));
    return ans;
}


pair<int, int> diameterFast(Node* root) {
    //base case
    if(root == NULL) {
        pair<int, int> p = make_pair(0, 0);  //first denotes diameter and second is height
        return p;
    }

    pair<int, int> left = diameterFast(root->left);
    pair<int, int> right = diameterFast(root->right);

    int op1 = left.first; //first means diameter
    int op2 = right.first; 
    int op3 = left.second + right.second + 1; //second means height

    pair<int, int> ans;
    ans.first = max(op1, max(op2, op3));
    ans.second = max(left.second, right.second) + 1;

    return ans;
}

//Optimize Approach O(n)
int diameterOptimized(Node* root) {
    
    return diameterFast(root).first; //because first is diameter
}

int main() {
    cout<<endl;

    Node* root = NULL;

    //Input: 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
    buildFromLevelorder(root);
    levelOrderTraversal(root);
    cout<<"Height of tree is: "<< height(root) <<endl;

    cout<<"Diameter is: "<< diameter(root) <<endl;
    cout<<"Diameter Optimized Approach: "<< diameterOptimized(root) <<endl;
    return 0;
}