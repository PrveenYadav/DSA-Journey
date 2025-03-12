#include <iostream>
#include <queue>
#include <vector>
#include <climits> //For INT_MIN and INT_MAX
using namespace std;

//Smallest range from k sorted list
class Node {
public:
    int data;
    int row;
    int col;

    Node(int val, int i, int j) {
        this->data = val;
        this->row = i;
        this->col = j;
    }
};

class compare{
public:
    bool operator()(Node* a, Node* b) {
        return a->data > b->data;
    }
};

int kSorted(vector<vector<int>> &arr, int k, int n) {
    int mini = INT_MIN, maxi = INT_MAX;
    priority_queue<Node*, vector<Node*>, compare> minHeap;

    //step-1: create a min heap for starting element of each list and tracking min/max value
    for(int i=0; i<k; i++) {
        int element = arr[i][0];
        mini = min(mini, element);
        maxi = max(maxi, element);
        minHeap.push(new Node(element, i, 0));
    }

    //step-2: process ranges
    int start = mini, end = maxi;
    while(!minHeap.empty()) {
        //mini fetch
        Node* temp = minHeap.top();
        minHeap.pop();

        mini = temp->data;

        //range or answer updatation
        if(maxi-mini < end-start) {
            start = mini;
            end = maxi;
        }

        //next element exist
        if(temp->col + 1 < n) {
            maxi = max(maxi, arr[temp->row][temp->col+1]);
            minHeap.push(new Node(arr[temp->row][temp->col+1], temp->row, temp->col+1));
        }else {
            //next element not exist
            break;
        }
    }
    
    //return the difference of ranges value
    return (end-start+1);
}

int main() {
    cout<<endl;

    vector<vector<int>> list = {
        {1, 10, 11},
        {2, 3, 20},
        {5, 6, 12}
    };
    int n = list.size();
    cout<<"Smallest range from k sorted list: "<< kSorted(list, 2, n) <<endl;
    
    return 0;
}