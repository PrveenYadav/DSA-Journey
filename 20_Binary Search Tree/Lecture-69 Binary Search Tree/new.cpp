#include <iostream>
#include <queue>
using namespace std;

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


Node* insertion(Node* &root, int element) {
    //base case
    if(root == NULL) {
        return root = new Node(element);
    }

    if(element < root->data) {
        root->left = insertion(root->left, element);
    }else if(element > root->data) {
        root->right = insertion(root->right, element);
    }

    return root;
}

bool search(Node* root, int x) {
    if(root == NULL) return false;

    if(root->data == x) return true;

    if(x < root->data) {
        return search(root->left, x);
    }else {
        return search(root->right, x);
    }
}

int findMin(Node* root) {
    Node* temp = root;

    while(temp->left != NULL) {
        temp = temp->left;
    }

    return temp->data;
}

int findMax(Node* root) {
    Node* temp = root;

    while(temp->right != NULL) {
        temp = temp->right;
    }

    return temp->data;
}


Node* deletion(Node* &root, int element) {
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
            Node* temp = root->left;
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
            
            int minVal = findMin(root->right);
            root->data = minVal;
            root->right = deletion(root->right, minVal);
            return root;
        }
    }
    else if(element < root->data) {
        root->left = deletion(root->left, element);
        return root;
    }else {
        root->right = deletion(root->right, element);
        return root;
    }
}

int main() {
    cout<<endl;

    Node* root = NULL;

    // 5 4 7 3 8 9 -1
    //Implementation
    cout<<"Enter data for BST: ";
    takeInput(root);
    cout<<"Printing the BST: "<<endl;
    levelorderTraversal(root);

    //Insertion
    cout<<"After Inserting an element: "<<endl;
    insertion(root, 2);
    levelorderTraversal(root);

    //Search in BST
    if(search(root, 6)) {
        cout<<"Present"<<endl;
    }else {
        cout<<"Not Present"<<endl;
    }

    //Min & Max in BST
    cout<<"Min is: "<< findMin(root) <<endl;
    cout<<"Max is: "<< findMax(root) <<endl;

    //Deletion
    cout<<"After Deleting an element from BST: "<<endl;
    deletion(root, 5);
    levelorderTraversal(root);
    return 0;
}