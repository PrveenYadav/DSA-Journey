#include <iostream>
#include <vector>
#include <queue>
#include<map>
using namespace std;

//Vertical Traversal of Binary Tree: Lecture 64 : Time 40:00
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


vector<int> verticalOrder(Node* root) {

    map<int, map<int, vector<int>> > nodes;
    queue< pair<Node*, pair<int, int>> > q;

    vector<int> ans;
    if(root == NULL) return ans;

    q.push(make_pair(root, make_pair(0, 0)));

    while(!q.empty()) {
        pair<Node*, pair<int, int>> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second.first; //horizontal distance
        int level = temp.second.second;

        nodes[hd][level].push_back(frontNode->val);

        if(frontNode->left) {
            q.push(make_pair(frontNode->left, make_pair(hd-1, level+1)));
        }

        if(frontNode->right) {
            q.push(make_pair(frontNode->right, make_pair(hd+1, level+1)));
        }
    }

    for(auto i: nodes) { //: means belongs to
        for(auto j: i.second) {
            for(auto k: j.second) {
                ans.push_back(k);
            }
        }
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

    verticalOrder(root);
    cout<<"Vertical Traversal: ";
    for(auto i : verticalOrder(root)) {
        cout<< i <<" ";
    }
    cout<<endl;
    return 0;
}