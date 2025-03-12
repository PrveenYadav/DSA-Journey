#include <iostream>
#include <queue>
#include <vector>
using namespace std;

//Construct Tree from Inorder & Preorder
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node (int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void buildFromLevelorder(Node* &root) {
    queue<Node*> q;

    cout<<"Enter root data: ";
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

void levelOrderTraversal(Node* root) {
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


int findPosition(int in[], int element, int n) {
    for(int i=0; i<n; i++) {
        if(in[i] == element) {
            return i;
        }
    }
    return -1;
}

Node* solve(int in[], int pre[], int &index, int inorderStart, int inorderEnd, int n) {
    //base case
    if(index >= n || inorderStart > inorderEnd) {
        return NULL;
    }

    int element = pre[index++];
    Node* root = new Node(element);
    int position = findPosition(in, element, n);

    //Recursive call
    root->left = solve(in, pre, index, inorderStart, position-1, n);
    root->right = solve(in, pre, index, position+1, inorderEnd, n);

    return root;
}

Node* buildTree(int in[], int pre[], int n) {

    int preOrderIndex = 0;
    Node* ans = solve(in, pre, preOrderIndex, 0, n-1, n); // 0 = Inorder starting index
    return ans;
}

// Helper function for testing: print tree in inorder
void printInorder(Node* root) {
    if (root == NULL) return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main() {
    cout<<endl;

    Node* root = NULL;

    //1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
    buildFromLevelorder(root);
    cout<<"Level Order Traversal: "<<endl;
    levelOrderTraversal(root);

    int inorder[]= {4, 2, 5, 1, 6, 3, 7};
    int preorder[]= {1, 4, 2, 5, 6, 3, 7};

    root = buildTree(inorder, preorder, 7);
    printInorder(root);
    return 0;
}