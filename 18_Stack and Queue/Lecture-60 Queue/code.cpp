#include <iostream>
#include <queue>
using namespace std;

//Implementaion of Queue: using C++ STL

void inputQueue(queue<int> &q, int n) {
    for(int i=0; i<n; i++) {
        int x;
        cin>>x;
        q.push(x);
    }
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

    //creation of queue
    queue<int> q;

    int n;
    cout<<"Enter the number of Queue to push: ";
    cin>>n;

    cout<<"Enter "<< n <<" Queues: ";
    inputQueue(q, n);

    cout<<"After pop operation ";
    q.pop();

    cout<<"Printing Queues: ";
    printQueue(q);

    cout <<"Size of queue: "<< q.size() <<endl;
    cout<<"Front element of queue: "<< q.front() <<endl;
    cout<<"Last element of queue: "<< q.back() <<endl;

    q.push(6);
    cout<<"After push operation printing queue: ";
    printQueue(q);
    return 0;
}