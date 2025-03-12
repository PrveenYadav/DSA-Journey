#include <iostream>
#include <queue>
using namespace std;

//Problem: Deletion in BST: solve leetcode 700 search bst

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

Node* insertIntoBST(Node* &root, int data) {
    //base case
    if(root == NULL) {
        root = new Node(data);
        return root;
    }

    if(data < root->data) {
        root->left = insertIntoBST(root->left, data);
    }else {
        root->right = insertIntoBST(root->right, data);
    }

    return root;
}

void takeInput(Node* &root) {
    int data;
    cin>>data;

    while(data != -1) {
        insertIntoBST(root, data);
        cin>>data;
    }
}


Node* findMin(Node* root) {
    
    Node* temp = root;
    while(temp->left != NULL) {
        temp = temp->left;
    }

    return temp;
}

int findMax(Node* root) {
    
    Node* temp = root;
    while(temp->right != NULL) {
        temp = temp->right;
    }

    return temp->data;
}


//Deletion in BST
//step-1: search element in BST to delete
//step-2: for deleting can be 4 cases like: nodeToDelete has 0 child, 1, or two child
 
Node* deleteFromBST(Node* &root, int element) {
    //base case
    if(root == NULL) return root;

    if(root->data == element) {
        //0 child
        if(root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }

        //1 child: left
        if(root->left != NULL && root->right == NULL) {
            Node* temp = root->left; //root is the node to delete, so storing root->left in temp
            delete(root); 
            return temp;
        }
        //1 child: right
        if(root->left == NULL && root->right != NULL) {
            Node* temp = root->right;
            delete(root); 
            return temp;
        }

        //2 child
        if(root->left != NULL && root->right != NULL) {

            int minVal = findMin(root->right) -> data;
            root->data = minVal; //copying val
            root->right = deleteFromBST(root->right, minVal); //deleting minVal, if not then after copying it will print again
            return root;
        }


    }else if(element < root->data) {
        root->left = deleteFromBST(root->left, element);
        return root;
    }else {
        root->right = deleteFromBST(root->right, element);
        return root;
    }
}

int main() {
    cout<<endl;

    Node* root = NULL;

    //5 4 7 3 8 9 -1 : 5 2 7 1 3 9 11 -1
    cout<<"Enter the data for BST: ";
    takeInput(root);
    
    cout<<"Printing the BST: "<<endl;
    levelorderTraversal(root);

    Node* min = findMin(root);
    cout<<"Min val of BST is: "<< min->data <<endl;
    cout<<"Max val of BST is: "<< findMax(root) <<endl;
    
    cout<<"After Deleting a node in BST: "<<endl;
    deleteFromBST(root, 5);
    levelorderTraversal(root);
    return 0;
}