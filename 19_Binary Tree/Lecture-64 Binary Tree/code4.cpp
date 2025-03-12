#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

//Left view of a Binary Tree : Right view of Binary Tree
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


void solve(Node* root, vector<int> &ans, int level) {
    //base case
    if(root == NULL) return ;

    //we entered into a new level
    if(level == ans.size()) {
        ans.push_back(root->val);
    }

    //Recursive call for left and right
    solve(root->left, ans, level+1);
    solve(root->right, ans, level+1);
}

vector<int> leftView(Node* root) {
    vector<int> ans;
    solve(root, ans, 0); //0 is level, a variable whick will keep track of level
    return ans;
}


void solveRight(Node* root, vector<int> &ans, int level) {
    //base case
    if(root == NULL) return ;

    //we entered into a new level
    if(level == ans.size()) {
        ans.push_back(root->val);
    }

    //Recursive call : Only order changing for Right
    solveRight(root->right, ans, level+1);
    solveRight(root->left, ans, level+1);
}

vector<int> rightView(Node* root) {
    vector<int> ans;
    solveRight(root, ans, 0); //0 is level, a variable whick will keep track of level
    return ans;
}

int main() {
    cout<<endl;

    Node* root = NULL;

    //1 2 3 4 5 6 -1 -1 -1 -1 -1 -1 -1
    buildFromLevelorder(root); 
    cout<<endl<<"Level order Traversal"<<endl;
    levelorderTraversal(root);

    leftView(root);
    cout<< "Left View: ";
    for(auto i : leftView(root)) {
        cout<< i <<" ";
    }
    cout<<endl;

    rightView(root);
    cout<< "Right View: ";
    for(auto i : rightView(root)) {
        cout<< i <<" ";
    }
    cout<<endl;
    return 0;
}