#include <iostream>
#include <queue>
using namespace std;

//Problem: Merge Two BSTs: and make one
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* insert(Node* root, int val) {
    if (root == NULL) {
        return new Node(val);
    }

    if (val < root->data) {
        root->left = insert(root->left, val);
    }
    else {
        root->right = insert(root->right, val);
    }

    return root;
}

void inorder(Node* root) {
    if (root == NULL) {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

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


//Problem: Merge Two BST... , 3 helper functions: Time and space O(n)
void inorder(Node* root, vector<int> &in) {
    if(root == NULL) return ;

    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

vector<int> mergeArrays(vector<int> &a, vector<int> &b) {
    
    vector<int> ans(a.size() + b.size());

    int i = 0, j = 0;
    int k = 0;
    while(i < a.size() && j < b.size()) {
        
        if(a[i] < b[j]) {
            ans[k++] = a[i];
            i++;
        }else {
            ans[k++] = b[j];
            j++;
        }
    }

    while(i < a.size()) {
        ans[k++] = a[i];
        i++;
    }

    while(j < b.size()) {
        ans[k++] = b[j];
        j++;
    }

    return ans;
}

Node* inorderToBST(int start, int end, vector<int> &in) {
    if(start > end) return NULL;

    int mid = start + (end-start) / 2;
    Node* root = new Node(in[mid]);

    root->left = inorderToBST(start, mid-1, in);
    root->right = inorderToBST(mid+1, end, in);

    return root;
}

Node* mergeTwoBst(Node* &root1, Node* &root2) {

    //step-1: store inorder
    vector<int> bst1, bst2;
    inorder(root1, bst1);
    inorder(root2, bst2);

    //step-2: merge both sorted arrays
    vector<int> mergeArray = mergeArrays(bst1, bst2);
    
    //step-3: use merged inorder array to build BST
    int start = 0, end = mergeArray.size() - 1;

    return inorderToBST(start, end, mergeArray);
}

int main() {
    cout<<endl;
    
    Node* root1 = NULL;
    Node* root2 = NULL;
    root1 = insert(root1, 50);
    root1 = insert(root1, 30);
    root1 = insert(root1, 20);
    root1 = insert(root1, 40);

    root2 = insert(root2, 3);
    root2 = insert(root2, 7);
    root2 = insert(root2, 6);
    root2 = insert(root2, 9);

    cout << "Inorder Traversal First BST: ";
    inorder(root1);
    cout<<endl<< "Inorder Traversal Second BST: ";
    inorder(root2);

    cout<<endl<< "Level Order Traversal 1st BST: ";
    levelOrder(root1);
    cout<<endl<< "Level Order Traversal 2nd BST: ";
    levelOrder(root2);
    cout<<endl;

    Node* root3 = mergeTwoBst(root1, root2);
    cout<<endl<<"Merged BST, level order: ";
    levelOrder(root3);
    cout<<endl<<"Merged BST, Inorder: ";
    inorder(root3);
    cout<<endl;
    return 0;
}