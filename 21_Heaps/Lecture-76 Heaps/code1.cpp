#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class node {
public:
    int data;
    int row;
    int col;

    //constructor
    node (int val, int row, int col) {
        this->data = val;
        this->row = row;
        this->col = col;
    }
};

class compare {
public:
    
    bool operator() (node* a, node* b) {
        return a->data > b->data;
    }
};

//Merge k sorted Arrays : Time complexity O(n*k(log k)) and space O(n*k)
vector<int> mergeKSortedArrays(vector<vector<int>> &kArrays, int k) {

    priority_queue<node*, vector<node*>, compare> minHeap;

    //insert first element of all arrays
    for(int i=0; i<k; i++) {
        node* temp = new node(kArrays[i][0], i, 0);
        minHeap.push(temp);
    }

    vector<int> ans;
    while(minHeap.size() > 0) {
        node* temp = minHeap.top();
        ans.push_back(temp->data);
        minHeap.pop();

        int i = temp->row;
        int j = temp->col;

        if(j+1 < kArrays[i].size()) {
            node* next = new node(kArrays[i][j+1], i, j+1);
            minHeap.push(next);
        }
    }
    return ans;
}

int main() {
    cout<<endl;

    vector<vector<int>> kArrays = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };

    cout<<"Merge k sorted arrays: ";
    vector<int> ans = mergeKSortedArrays(kArrays, 2);
    for(auto i: ans) {
        cout<< ans[i] <<" ";
    }cout<<endl;

    int n = 2*kArrays.size();
    for(int i=0; i<n; i++) {
        cout<< ans[i] <<" ";
    }cout<<endl;
    return 0;
}