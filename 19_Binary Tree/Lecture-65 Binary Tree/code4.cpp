#include <iostream>
#include <queue>
#include <vector>
using namespace std;

//Maximum sum of Non-Adjacent Nodes
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
        
        cout<<"Enter left node for "<< temp->data <<endl;
        int rightData;
        cin>>rightData;
        if(rightData != -1) {
            temp->right = new Node(rightData);
            q.push(temp->right);
        }
    }
}

void levelOrderTraversal(Node* &root) {
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
        }
        else {
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


pair<int, int> solve(Node* root) {
    //base case
    if(root == NULL) {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }

    pair<int, int> leftAns = solve(root->left);
    pair<int, int> rightAns = solve(root->right);

    pair<int, int> result;

    result.first = root->data + leftAns.second + rightAns.second;
    result.second = max(leftAns.first, leftAns.second) + max(rightAns.first, rightAns.second);

    return result;
}

int getMaxSum(Node* root) {
    pair<int, int> ans = solve(root);
    return max(ans.first, ans.second);
}

int main() {
    cout<<endl;

    Node* root = NULL;

    //1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
    buildFromLevelorder(root);
    cout<<"Level Order Traversal: "<<endl;
    levelOrderTraversal(root);

    cout<<"Max Sum of Non-Adjacent Nodes: "<< getMaxSum(root) <<endl;
    return 0;
}