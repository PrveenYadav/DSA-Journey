#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

//Top view of a Binary Tree : Bottom view of binary tree
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


vector<int> topView(Node* root) {
    vector<int> ans;
    if(root == NULL) return ans;

    map<int, int> topNode;
    queue<pair<Node*, int>> q;

    q.push(make_pair(root, 0));
    while(!q.empty()) {
        pair<Node*, int> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second; //hd = horizontal distance

        //if one value is present for a horizontal distance then do nothing
        if(topNode.find(hd) == topNode.end()) {
            topNode[hd] = frontNode->val;
        }

        if(frontNode->left) {
            q.push(make_pair(frontNode->left, hd-1));
        }
        if(frontNode->right) {
            q.push(make_pair(frontNode->right, hd+1));
        }
    }

    for(auto i : topNode) {
        ans.push_back(i.second);
    }
    return ans;
}

vector<int> bottomView(Node* root) {
    vector<int> ans;
    if(root == NULL) return ans;

    map<int, int> topNode;
    queue<pair<Node*, int>> q;

    q.push(make_pair(root, 0));
    while(!q.empty()) {
        pair<Node*, int> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second; //hd = horizontal distance

        topNode[hd] = frontNode->val;

        if(frontNode->left) {
            q.push(make_pair(frontNode->left, hd-1));
        }
        if(frontNode->right) {
            q.push(make_pair(frontNode->right, hd+1));
        }
    }

    for(auto i : topNode) {
        ans.push_back(i.second);
    }
    return ans;
}

int main() {
    cout<<endl;

    Node* root = NULL;

    //1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
    buildFromLevelorder(root); 
    cout<<endl<<"Level order Traversal"<<endl;
    levelorderTraversal(root);
    

    topView(root);
    bottomView(root);

    cout<<"Top View: ";
    for(auto i : topView(root)) {  //4 2 1 3 7
        cout<< i <<" ";
    }
    cout<<endl;

    cout<<"Bottom View: ";
    for(auto i : bottomView(root)) {  //4 2 6 3 7
        cout<< i <<" ";
    }
    cout<<endl;
    return 0;
}