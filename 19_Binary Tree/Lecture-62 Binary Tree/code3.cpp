#include <iostream>
#include <queue>
using namespace std;

//Home Work: Reverse Level Order Traversal
//Home Work: Inorder + Preorder + Postorder Traversal solve with iterative approach

//Problem: Count Leaf Nodes
class Node {
public:
    int data;
    Node* left;
    Node* right;

    //constructor
    Node (int d) {
        data = d;
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

        cout<<"Enter left node for "<< temp->data <<endl;
        int leftData;
        cin>>leftData;

        if(leftData != -1) {
            temp->left = new Node(leftData);
            q.push(temp->left);
        }

        cout<<"Enter right node for "<< temp->data <<endl;
        int rightData;
        cin>>rightData;

        if(rightData != -1) {
            temp->right = new Node(rightData);
            q.push(temp->right);
        }

    }

}


//helper function for leaf node
void inorderTraversal(Node* root, int &count) {  //LNR
    //base case
    if(root == NULL) {
        return ;
    }

    inorderTraversal(root->left, count);
    
    //Leaf node condition
    if(root->left == NULL && root->right == NULL) {
        count++;
    }
    
    inorderTraversal(root->right, count);
}

//Count leaf nodes
int leafNodes(Node* &root) {
    int count = 0;
    inorderTraversal(root, count);
    return count;
}


int main() {
    cout<<endl;
    
    Node* root = NULL;

    buildFromLevelorder(root);
    levelOrderTraversal(root);
    //Input: 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1

    cout<<"Number of Leaf Nodes is: ";
    cout<< leafNodes(root) <<endl;
    return 0;
}