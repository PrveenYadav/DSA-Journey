#include <iostream>
#include <queue>
using namespace std;

//Determine if two tree are identical

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node (int data) {
        val = data;
        left = NULL;
        right = NULL;
    }
};

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


bool isIdentical(Node* r1, Node* r2) {
    //base case
    if(r1 == NULL && r2 == NULL) {
        return true;
    }

    if(r1 == NULL && r2 != NULL) {
        return false;
    }

    if(r1 != NULL && r2 == NULL) {
        return false;
    }
    
    bool left = isIdentical(r1->left, r2->left);
    bool right = isIdentical(r1->right, r2->right);

    bool value = r1->val == r2->val;
    
    if(left && right && value) {
        return true;
    }else {
        return false;
    }
}


int main() {
    cout<<endl;

    Node* root = NULL;
    Node* root1 = NULL;

    //1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
    buildFromLevelorder(root);
    levelOrderTraversal(root);
    buildFromLevelorder(root1);
    levelOrderTraversal(root1);

    if(isIdentical(root, root1)) {
        cout<<"Tree is Identical"<<endl;
    }else{
        cout<<"Tree is Not Identical"<<endl;
    }
    return 0;
}