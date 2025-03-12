#include <iostream> 
#include <queue>
#include <map>
using namespace std;

//For All Binary Tree Problems check out GeeksForGeeks
//Problem: Burning Tree(Hard) : min time to burn a tree
class Node{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void buildFromlevelorder(Node* &root) {
    queue<Node*> q;
    
    cout<<"Enter the root data: ";
    int data;
    cin>>data;
    root = new Node(data);
    q.push(root);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        cout<<"Enter the left node for "<< temp->data <<endl;
        int leftData;
        cin>>leftData;
        if(leftData != -1) {
            temp->left = new Node(leftData);
            q.push(temp->left);
        }

        cout<<"Enter the right node for "<< temp->data <<endl;
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

void inorder(Node* root) {
    if(root == NULL) {
        return ;
    }

    inorder(root->left);
    cout<< root->data <<" ";
    inorder(root->right);
}


//create mapping and return target node
Node* createParentMappint(Node* root, int target, map<Node*, Node*> &nodeToParent) {

    Node* res = NULL;

    queue<Node*> q;
    q.push(root);
    nodeToParent[root] = NULL;

    while(!q.empty()) {
        Node* front = q.front();
        q.pop();

        if(front->data == target) {
            res = front;
        }

        if(front->left) {
            nodeToParent[front->left] = front;
            q.push(front->left);
        }

        if(front->right) {
            nodeToParent[front->right] = front;
            q.push(front->right);
        }
    }

    return res;
}

int burnTree(Node* root, map<Node*, Node*> &nodeToParent) {

    map<Node*, bool> visited;
    queue<Node*> q;

    q.push(root);
    visited[root] = true;

    int ans = 0;

    while(!q.empty()) {
        bool flag = 0;  //0 or false
        int size = q.size();

        for(int i=0; i<size; i++) {
            //process neighbouring node
            Node* front = q.front();
            q.pop();

            if(front->left && !visited[front->left]) {
                flag = 1; //1 or true
                q.push(front->left);
                visited[front->left] = true; //1 or true
            }

            if(front->right && !visited[front->right]) {
                flag = 1;
                q.push(front->right);
                visited[front->right] = true;
            }

            if(nodeToParent[front] && !visited[nodeToParent[front]]) {
                flag = 1;
                q.push(nodeToParent[front]);
                visited[nodeToParent[front]] = true;
            }
        }
        if(flag == 1) {
            ans++;
        }
    }

    return ans;
}

//Time and space complexity is O(n)
int minTime(Node* root, int target) {
    //Algo: 
    //step-1: create nodeToParent mapping
    //step-2: find the target node
    //step-3: burn the tree in min time

    map<Node*, Node*> nodeToParent;
    Node* targetNode = createParentMappint(root, target, nodeToParent);

    int ans = burnTree(targetNode, nodeToParent);
    return ans;
}

int main() {
    cout<<endl;

    Node* root = NULL;

    //1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
    buildFromlevelorder(root);
    cout<<"Level order Traversal: "<<endl;
    levelOrderTraversal(root);
    
    cout<<"Min Time to burn a Tree: "<< minTime(root, 5) <<" seconds"<<endl;
    return 0;
}