#include <iostream>
#include <queue>
using namespace std;

//Problem: Sum Tree: if sum of left and right subtree is equal to root node then return true

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node (int data) {
        val = data;
        left = NULL;
        right = NULL;
    }
};

void levelOrderTraversal(Node* root) {

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if(temp == NULL) {
            //previous level is completly traversed
            cout<<endl;

            if(!q.empty()) {  //Queue still has some child nodes
                q.push(NULL);
            }
        
        }else {
            cout<< temp->val <<" ";

            if(temp->left) {
                q.push(temp->left);
            }

            if(temp->right) {
                q.push(temp->right);
            }
        }
    }

}

void buildFromLevelorder(Node* &root) {
    queue<Node*> q;

    cout<<"Enter data for root: ";
    int data;
    cin>>data;
    root = new Node(data);
    q.push(root);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        cout<<"Enter left node for "<< temp->val <<endl;
        int leftData;
        cin>>leftData;

        if(leftData != -1) {
            temp->left = new Node(leftData);
            q.push(temp->left);
        }

        cout<<"Enter right node for "<< temp->val <<endl;
        int rightData;
        cin>>rightData;

        if(rightData != -1) {
            temp->right = new Node(rightData);
            q.push(temp->right);
        }

    }

}


//sum tree
pair<bool, int> sumTreeFast(Node* root) {
    //base case
    if(root == NULL) {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }
    
    if(root->left == NULL && root->right == NULL) {
        pair<bool, int> p = make_pair(true, root->val);
        return p;
    }

    pair<int, int> leftAns = sumTreeFast(root->left);
    pair<int, int> rightAns = sumTreeFast(root->right);

    bool left = leftAns.first;
    bool right = rightAns.first;

    int leftSum = leftAns.second;
    int rightSum = rightAns.second;

    bool condition = root->val == leftSum + rightSum;

    pair<bool, int> ans;

    if(left && right && condition) {
        ans.first = true;
        ans.second = root->val + leftSum + rightSum;
        //ans.second = 2*root->val;
    }else {
        ans.first = false;
    }

    return ans;
}

bool isSumTree(Node* root) {
    return sumTreeFast(root).first;
}

int main() {
    cout<<endl;

    Node* root = NULL;

    //1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
    //1 2 3 4 5 -1 -1 -1 -1 -1 -1
    buildFromLevelorder(root);
    levelOrderTraversal(root);

    //3 1 2 -1 -1 -1 -1
    if(isSumTree(root)) {
        cout<<"It is a Sum Tree"<<endl;
    }else {
        cout<<"Not a Sum Tree"<<endl;
    }
    return 0;
}