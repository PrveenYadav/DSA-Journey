#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//Zig Zag Traverse: we goes left->right then R->L, L->R ...
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


vector<int> zigZagTraversal(Node* &root) {

    vector<int> result;
    if(root == NULL) return result;

    queue<Node*> q;
    q.push(root);

    bool leftToRight = true;

    while(!q.empty()) {
        int size = q.size();
        vector<int> ans(size);

        //level process
        for(int i=0; i<size; i++) {
            Node* frontNode = q.front();
            q.pop();

            //normal insert or reverse insert
            int index = leftToRight ? i : size-i-1; 
            ans[index] = frontNode->val;

            if(frontNode->left) {
                q.push(frontNode->left);
            }

            if(frontNode->right) {
                q.push(frontNode->right);
            }
        }

        //changing the direction
        leftToRight = !leftToRight;

        for(auto i : ans) {
            result.push_back(i);
        }
    }
    return result;
}

int main() {
    cout<<endl;

    Node* root = NULL;

    //1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
    buildFromLevelorder(root); 
    cout<<endl<<"Level order Traversal"<<endl;
    levelorderTraversal(root);

    zigZagTraversal(root);
    cout<<"Zig Zag Traversal: ";
    for(auto i : zigZagTraversal(root)) {
        cout<< i <<" ";
    }
    cout<<endl;
    return 0;
}