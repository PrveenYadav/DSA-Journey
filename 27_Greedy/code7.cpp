#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//Huffman Encoding : visualized a tree when we go left then 0 and when right then 1

class Node {
public:
    int data;
    Node* left;
    Node* right;

    //constructor
    Node (int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

//comparator
class cmp {
public:
    bool operator()(Node* a, Node* b) {
        return a->data > b->data;
    }
};


void traversal(Node* root, vector<string> &ans, string temp) {
    //base case
    if(root->left == NULL && root->right == NULL) {
        ans.push_back(temp);
    }

    traversal(root->left, ans, temp + '0');
    traversal(root->right, ans, temp + '1');
}

vector<string> huffmanCodes(string S,vector<int> f,int N) {
	
    priority_queue<Node*, vector<Node*>, cmp> pq;

    for(int i=0; i<N; i++) {
        Node* temp = new Node(f[i]);
        pq.push(temp);
    }

    while(pq.size() > 1) {
        Node* left = pq.top();
        pq.pop();

        Node* right = pq.top();
        pq.pop();

        Node* newNode = new Node(left->data + right->data);
        newNode->left = left;
        newNode->right = right;
        pq.push(newNode);
    }
    Node* root = pq.top();
    vector<string> ans;
    string temp = "";

    traversal(root, ans, temp);
    return ans;
}


int main() {
    cout<<endl;

    string S = "abcdef";
    vector<int> f = {5, 9, 12, 13, 16, 45};
    int N = f.size();
    
    vector<string> ans = huffmanCodes(S, f, N);
    for(const string& i : ans) {
        cout<< i <<" ";
    }cout<<endl;
    return 0;
}