#include <iostream> 
#include <queue>
using namespace std;

//Preorder Traversal of a BST 
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


Node* solve(vector<int> &preorder, int min, int max, int &i) { // i is travelling to every node
    if(i >= preorder.size()) return NULL;

    if(preorder[i] < min || preorder[i] > max) return NULL;

    //creating a new node and increasing i
    Node* root = new Node(preorder[i++]); //i++ for go to next node
    root->left = solve(preorder, min, root->data, i);
    root->right = solve(preorder, root->data, max, i);
    
    return root;
}

//Preorder Traversal of a BST
Node* preorderToBST(vector<int> &preorder) {
    int mini = INT8_MIN;
    int maxi = INT8_MAX;
    int i = 0;

    return solve(preorder, mini, maxi, i);
}

int main() {
    cout<<endl;

    Node* root = NULL;

    cout<<"Enter data for BST: ";
    takeInput(root);
    cout<<"Printing the BST: "<<endl;
    levelorderTraversal(root);

    vector<int> preorder = {20, 10, 5, 15, 13, 35, 30, 42};
    cout<<"Preorder to BST: "<<endl;
    preorderToBST(preorder);
    levelorderTraversal(root);
    return 0;
}