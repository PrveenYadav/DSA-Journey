#include <iostream>
#include <queue>
#include <stack>
using namespace std;

//Reverse first k elements of queue
queue<int> modifyQueue(queue<int> q, int k) {
    //step-1: pop first k elements from queue and push into stack
    stack<int> s;

    for(int i=0; i<k; i++) {
        int val = q.front();
        q.pop();
        s.push(val);
    }

    //step-2: fetch from stack and push into queue
    while(!s.empty()) {
        int val = s.top();
        s.pop();
        q.push(val);
    }

    //step-3: fetch first (n-k) elements from queue ans push_back
    int t = q.size() - k;
    while(t--) {
        int val = q.front();
        q.pop();
        q.push(val);
    }
    return q;
}

void printQueue(queue<int> q) {
    while(!q.empty()) {
        cout<< q.front() <<" ";
        q.pop();
    }
    cout<<endl;
}

int main() {
    cout<<endl;

    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    int k = (5, 3);

    modifyQueue(q, k);
    printQueue(q);
    return 0;
}