#include <iostream>
#include <queue>
#include <map>
using namespace std;

//Tree from postorder and inorder
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


void createMapping(int in[], map<int, int> &nodeToIndex, int n) {
    for(int i=0; i<n; i++) {
        nodeToIndex[in[i]] = i;
    }
}

Node* solve(int in[], int post[], int &index, int inorderStart, int inorderEnd, int n, map<int, int> &nodeToIndex) {
    //base case
    if(index <  0 || inorderStart > inorderEnd) {
        return NULL;
    }

    //create a root node for element
    int element = post[index-- ];
    Node* root = new Node(element);
    
    //find element's index in inorder
    int position = nodeToIndex[element];

    //Recursive call
    root->right = solve(in, post, index, position+1, inorderEnd, n, nodeToIndex);
    root->left = solve(in, post, index, inorderStart, position-1, n, nodeToIndex);

    return root;
}

Node* buildTree(int in[], int post[], int n) {

    int postOrderIndex = n-1;
    map<int, int> nodeToIndex;
    //create nodes to index mapping
    createMapping(in, nodeToIndex, n);
    Node* ans = solve(in, post, postOrderIndex, 0, n-1, n, nodeToIndex); // 0 = Inorder starting index
    return ans;
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

    Node* ans = buildTree(inorder, preorder, 7);
    buildTree(inorder, preorder, 7);
    return 0;
}