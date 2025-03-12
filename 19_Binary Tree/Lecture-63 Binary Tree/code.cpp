#include <iostream>
#include <queue>
using namespace std;

//Problem: Height of Binary Tree
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


//Level Order Traversing
void levelOrderTraversal(Node* root) {

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if(temp == NULL) {
            //previous level is completly traversed
            cout<<endl;

            if(!q.empty()) {  //Queue still has some child nodes
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

//Build from Level Order / Taking input as level order
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

//Maximum height of Tree: Lecture 63: Time 11:50 - DRY RUN(Explanation of Recursive Tree)
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

int main() {
    cout<<endl;

    Node* root = NULL;
    buildFromLevelorder(root);
    levelOrderTraversal(root);
    //1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1

    cout<<"Maximum Height of Tree is: "<< height(root) <<endl;
    return 0;
}