#include <iostream> 
#include <queue>
using namespace std;

//Normal BST to balanced BST : height[left] - height[right] <= 1 at every node then bst is balanced
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


void inorder(Node* root, vector<int> &in) {
    if(root == NULL) return ;

    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

Node* inorderToBST(int start, int end, vector<int> &inorderVal) {
    //base case
    if(start > end) return NULL;

    int mid = start + (end-start) / 2;
    Node* root = new Node(inorderVal[mid]);
    root->left = inorderToBST(start, mid-1, inorderVal);
    root->right = inorderToBST(mid+1, end, inorderVal);

    return root;
}

//Normal bst to balanced bst
Node* balancedBST(Node* root) {
    vector<int> inorderVal;
    //store inorder -> sorted value
    inorder(root, inorderVal);
    int n = inorderVal.size() - 1;

    return inorderToBST(0, n, inorderVal);
}

int main() {
    cout<<endl;

    Node* root = NULL;

    cout<<"Enter data for BST: ";
    takeInput(root);
    cout<<"Printing the BST: "<<endl;
    levelorderTraversal(root);

    cout<<"Balanced BST: "<< balancedBST(root)->data <<" ";
    return 0;
}