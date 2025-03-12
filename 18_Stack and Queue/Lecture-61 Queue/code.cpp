#include <iostream>
#include <stack>
#include <queue>
using namespace std;

//Queue Reverse: 2 ways - using stack and using recursion
queue<int> reverse(queue<int> &q) {

    stack<int> s;

    while(!q.empty()) {
        int element = q.front();
        q.pop();
        s.push(element);
    }

    while(!s.empty()) {
        int element = s.top();
        s.pop();
        q.push(element);
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

    cout<<"Original Queue: ";
    printQueue(q);

    reverse(q);
    cout<<"Reversed Queue: ";
    printQueue(q);
    return 0;
}