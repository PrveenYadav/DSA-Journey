#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//Sum of the Longest Bloodline in a tree(sum of nodes on the longest path from root to leaf node) : geeksforgeeks for all Binary tree problems
//Means sum of nodes of longest path in binary tree
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
                //root = NULL;
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


void solve(Node* root, int sum, int &maxSum, int len, int &maxLen) {
    //base case
    if(root == NULL) {
        if(len > maxLen) {
            maxLen = len;
            maxSum = sum;
        }
        else if(len == maxLen) {
            maxSum = max(sum, maxSum);
        }
        return ;
    }

    sum = sum + root->val;

    //function call for left and right
    solve(root->left, sum, maxSum, len+1, maxLen);
    solve(root->right, sum, maxSum, len+1, maxLen);
}

int sumOfLongest(Node* root) {
    
    int len = 0;
    int maxLen = 0;

    int sum = 0;
    int maxSum = INT8_MIN;

    solve(root, sum, maxSum, len, maxLen);
    
    return maxSum;
}

int main() {
    cout<<endl;

    Node* root = NULL;

    //1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
    buildFromLevelorder(root); 
    cout<<endl<<"Level order Traversal"<<endl;
    levelorderTraversal(root);

    cout<<"Longest Path's Sum: "<< sumOfLongest(root);
    return 0;
}