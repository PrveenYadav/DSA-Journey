#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//Problem: K sum paths
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


void solve(Node* root, int k, vector<int> path, int &count) {
    //base case
    if(root == NULL) return ;

    path.push_back(root->val);

    //left
    solve(root->left, k, path, count);
    //right
    solve(root->right, k, path, count);

    //check for k sum
    int size = path.size();
    int sum = 0;
    for(int i = size-1; i>=0; i--) {
        sum += path[i];
        if(sum == k) {
            count++;
        }
    }
    path.pop_back();
}

int sumK(Node* root, int k) {

    vector<int> path;
    int count = 0;
    solve(root, k, path, count);
    return count;
}

int main() {
    cout<<endl;

    Node* root = NULL;

    //1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
    buildFromLevelorder(root); 
    cout<<endl<<"Level order Traversal"<<endl;
    levelorderTraversal(root);

    cout<<"K Sum Paths: "<< sumK(root, 7);
    
    return 0;
}