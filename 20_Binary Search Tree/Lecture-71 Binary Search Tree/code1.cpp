#include <iostream> 
#include <queue>
using namespace std;

//Flatten BST to a sorted list : left pointer of linked list will point NULL and Right will point to the next
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

Node* flatten(Node* root) {
    vector<int> inorderVal;
    //store inorder -> sorted value
    inorder(root, inorderVal);
    int n = inorderVal.size();

    Node* newRoot = new Node(inorderVal[0]);
    Node* curr = newRoot;

    //2nd step
    for(int i=1; i<n; i++) {
        Node* temp = new Node(inorderVal[i]);

        curr->left = NULL;
        curr->right = temp;
        curr = temp;
    }

    //3rd step: reached at the last
    curr->left = NULL;
    curr->right = NULL;

    return newRoot;
}

int main() {
    cout<<endl;

    Node* root = NULL;

    cout<<"Enter data for BST: ";
    takeInput(root);
    cout<<"Printing the BST: "<<endl;
    levelorderTraversal(root);

    cout<<"Flatten BST to a Sorted List: "<<endl;

    flatten(root);
    // for(int i=0; i<6; i++) {
    //     cout<< flatten(root)->data <<" ";
    // }cout<<endl;

    return 0;
}