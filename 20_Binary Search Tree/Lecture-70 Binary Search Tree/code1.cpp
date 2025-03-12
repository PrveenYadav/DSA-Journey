#include <iostream>
#include <queue>
using namespace std;

//Find Kth smallest element in BST : kth largest : Home work 
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        this->data =  val;
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

//we know that inorder of BST always be sorted
int solve(Node* root, int &i, int k) {
    //base case
    if(root == NULL) return -1;

    //L
    int left = solve(root->left, i, k);
    if(left != -1) {
        return left;
    }

    //N
    i++;
    if(i == k) return root->data;

    //R
    int right = solve(root->right, i, k);
    return right;
}

int kthSmallest(Node* root, int i, int k) {
    int ans = solve(root, i, k);
    return ans;
}

void inorder(Node* root) {
    if(root == NULL) return ;

    inorder(root->left);
    cout<< root->data <<" ";
    inorder(root->right);
}

int main() {
    cout<<endl;

    Node* root = NULL;

    cout<<"Enter the data for BST: ";
    takeInput(root);
    cout<<"Printing the BST: "<<endl;
    levelorderTraversal(root);
    cout<<"Inorder Traversal: ";
    inorder(root);

    cout<<endl<<"Kth smallest: "<< kthSmallest(root, 6, 3) <<endl;

    return 0;
}