#include <iostream>
#include <queue>
using namespace std;

//Revision
// Structure of a node in the Binary Search Tree
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Function to insert a new node into the BST
Node* insert(Node* root, int val) {
    // If the tree is empty, create a new root node
    if (root == NULL) {
        return new Node(val);
    }

    // Recursively insert the node in the left subtree if the value is less than the root's value
    if (val < root->data) {
        root->left = insert(root->left, val);
    }
    // Recursively insert the node in the right subtree if the value is greater than or equal to the root's value
    else {
        root->right = insert(root->right, val);
    }

    return root;
}

// Function to perform In-order traversal (Left, Root, Right)
void inorder(Node* root) {
    if (root == NULL) {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Function to perform Pre-order traversal (Root, Left, Right)
void preorder(Node* root) {
    if (root == NULL) {
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Function to perform Post-order traversal (Left, Right, Root)
void postorder(Node* root) {
    if (root == NULL) {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// Function to perform Level Order Traversal (BFS)
void levelOrder(Node* root) {
    if (root == NULL) {
        return;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        cout << temp->data << " ";

        if (temp->left) {
            q.push(temp->left);
        }
        if (temp->right) {
            q.push(temp->right);
        }
    }
}

// Function to find the minimum value in the BST
Node* findMin(Node* root) {
    if (root == NULL) {
        return NULL; // Or any appropriate value to indicate an empty tree
    }

    while (root->left != NULL) {
        root = root->left;
    }

    return root;
}

// Function to find the maximum value in the BST
int findMax(Node* root) {
    if (root == NULL) {
        return -1; // Or any appropriate value to indicate an empty tree
    }

    while (root->right != NULL) {
        root = root->right;
    }

    return root->data;
}

// Function to search for a given value in the BST
bool search(Node* root, int key) {
    if (root == NULL) {
        return false;
    }

    if (root->data == key) {
        return true;
    }

    if (key < root->data) {
        return search(root->left, key);
    }

    return search(root->right, key);
}

// Function to delete a node from the BST
Node* deleteNode(Node* root, int key) {
    // If the tree is empty
    if (root == NULL) {
        return root;
    }

    // If the key to be deleted is smaller than the root's key, 
    // then it lies in left subtree
    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    }
    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    }
    // If key is same as root's key, then This is the node
    // to be deleted
    else {
        // node with only one child or no child
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        Node* temp = findMin(root->right);

        // Copy the inorder successor's data to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main() {
    cout<<endl;
    
    Node* root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;

    cout << "Preorder Traversal: ";
    preorder(root);
    cout << endl;

    cout << "Postorder Traversal: ";
    postorder(root);
    cout << endl;

    cout << "Level Order Traversal: ";
    levelOrder(root);
    cout << endl;

    cout << "Minimum Value: " << findMin(root)->data << endl;
    cout << "Maximum Value: " << findMax(root) << endl;

    int key = 40;
    if (search(root, key)) {
        cout << key << " found in the BST" << endl;
    } else {
        cout << key << " not found in the BST" << endl;
    }

    root = deleteNode(root, 50);
    cout << "Inorder Traversal after deletion: ";
    inorder(root);
    cout << endl;

    return 0;
}