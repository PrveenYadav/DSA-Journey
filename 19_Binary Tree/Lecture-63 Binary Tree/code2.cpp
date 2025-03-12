#include <iostream>
#include <queue>
using namespace std;

//Problem: check for balance tree
//A Tree is heigh balanced if deference between left and right subtree is not more then one for all nodes of tree

class Node {
public:
    int val;
    Node* left;
    Node* right;

    //constructor
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

int height(Node* node) {
    //base case
    if(node == NULL) {
        return 0;
    }

    int left = height(node->left);
    int right = height(node->right);

    int ans = max(left, right) + 1;
    return ans;
}

//Time complexity O(n2)
bool isBalanced(Node* root) {
    //base case
    if(root == NULL) {
        return true;
    }

    bool left = isBalanced(root->left);
    bool right = isBalanced(root->right);

    bool diff = abs(height(root->left) - height(root->right)) <= 1;

    if(left && right && diff) {
        return 1;
    }else {
        return 0;
    }
}


pair<bool, int> balancedFast(Node* root) {
    //base case
    if(root == NULL) {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }

    pair<bool, int> left = balancedFast(root->left);
    pair<bool, int> right = balancedFast(root->right);

    bool leftAns = left.first; 
    bool rightAns = right.first; 
   
    bool diff = abs(left.second - right.second) <= 1;

    pair<bool, int> ans;
    ans.second = max(left.second, right.second) + 1;

    if(leftAns && rightAns && diff) {
        ans.first = true;
    }else {
        ans.first = false;
    }

    return ans;
}

//Optimized Approach O(n)
bool isBalancedFast(Node* root) {
    return balancedFast(root).first;
}

int main() {
    cout<<endl;

    Node* root = NULL;

    //1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
    buildFromLevelorder(root);
    levelOrderTraversal(root);
    cout<<"Maximum Height of Tree is: "<< height(root) <<endl;

    if(isBalancedFast(root)) {
        cout<<"Tree is Balanced"<<endl;
    }else{
        cout<<"Tree is Not Balanced"<<endl;
    }
    return 0;
}