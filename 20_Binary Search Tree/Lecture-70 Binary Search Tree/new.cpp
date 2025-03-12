#include <iostream>
#include <queue>
using namespace std;

//Revision: 
//validate BST, kth smallest and largest, pred/succ of inorder, LCA of two nodes in BST

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

void inorder(Node* root) {
    if(root == NULL) return ;

    inorder(root->left);
    cout<< root->data <<" ";
    inorder(root->right);
}


//checking validate BST
bool isBST(Node* root, int min, int max) {
    if(root == NULL) return true;

    if(root->data <= min || root->data >= max) {
        return false;
    }

    bool left = isBST(root->left, min, root->data);
    bool right = isBST(root->right, root->data, max);

    return left && right;
}


//Kth smallest element in BST
void inorderTraversal(Node* root, int& k, int& result) {
    if (!root || k <= 0) return;

    inorderTraversal(root->left, k, result);
    k--;
    if (k == 0) {
        result = root->data;
        return;
    }
    inorderTraversal(root->right, k, result);
}

int kthSmallest(Node* root, int k) {
    int result = -1;
    inorderTraversal(root, k, result);
    return result;
}


//Kth largest in BST
void reverseInorderTraversal(Node* root, int& k, int& result) {
    if (!root || k <= 0) return;

    reverseInorderTraversal(root->right, k, result);
    k--;
    if (k == 0) {
        result = root->data;
        return;
    }
    reverseInorderTraversal(root->left, k, result);
}

int kthLargest(Node* root, int k) {
    int result = -1;
    reverseInorderTraversal(root, k, result);
    return result;
}


//Find pred and succ
Node* findPredecessor(Node* root, int key) {
    Node* predecessor = NULL;
    while (root) {
        if (key <= root->data) {
            root = root->left;
        } else {
            predecessor = root;
            root = root->right;
        }
    }
    return predecessor;
}

Node* findSuccessor(Node* root, int key) {
    Node* successor = NULL;
    while (root) {
        if (key >= root->data) {
            root = root->right;
        } else {
            successor = root;
            root = root->left;
        }
    }
    return successor;
}


//LCA in a BST
Node* findLCA(Node* root, int n1, int n2) {
    if (!root) return NULL;

    if (root->data > n1 && root->data > n2) {
        return findLCA(root->left, n1, n2);
    }

    if (root->data < n1 && root->data < n2) {
        return findLCA(root->right, n1, n2);
    }

    return root;
}

int main() {
    cout<<endl;

    Node* root = NULL;

    cout<<"Enter the data for BST: ";
    takeInput(root);
    cout<<"Printing the BST: "<<endl;
    levelorderTraversal(root);

    // Validate BST
    if (isBST(root, INT8_MIN, INT8_MAX)) {
        cout << "The tree is a valid BST" << endl;
    } else {
        cout << "The tree is not a valid BST" << endl;
    }

    cout<<"Inorder is: ";
    inorder(root);

    // Kth smallest and largest elements
    int k;
    cout<<endl << "Enter the value of k: ";
    cin >> k;

    int smallest = kthSmallest(root, k);
    cout << k << "th smallest element is: " << smallest << endl;

    int largest = kthLargest(root, k);
    cout << k << "th largest element is: " << largest << endl;

    // Predecessor and Successor
    int key;
    cout << "Enter the key to find predecessor and successor: ";
    cin >> key;

    Node* predecessor = findPredecessor(root, key);
    Node* successor = findSuccessor(root, key);

    if (predecessor) {
        cout << "Predecessor of " << key << " is: " << predecessor->data << endl;
    } else {
        cout << "No predecessor exists for " << key << endl;
    }

    if (successor) {
        cout << "Successor of " << key << " is: " << successor->data << endl;
    } else {
        cout << "No successor exists for " << key << endl;
    }

    // Lowest Common Ancestor
    int n1, n2;
    cout << "Enter two nodes to find their LCA: ";
    cin >> n1 >> n2;

    Node* lca = findLCA(root, n1, n2);
    if (lca) {
        cout << "Lowest Common Ancestor of " << n1 << " and " << n2 << " is: " << lca->data << endl;
    } else {
        cout << "No LCA exists for " << n1 << " and " << n2 << endl;
    }
    
    return 0;
}