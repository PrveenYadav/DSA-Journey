#include <iostream>
#include <queue>
using namespace std;

//Heap exist in C++ STL : To use it we insert queue and use by name of priority queue
//Priority Queue

int main() {
    cout<<endl;

    cout<<"---Priority Queue---"<<endl;

    //Max Heap
    priority_queue<int> pq;

    pq.push(4);
    pq.push(2);
    pq.push(5);
    pq.push(3);

    cout<<"Top element: "<< pq.top() <<endl;
    pq.pop();
    cout<<"Top element after pop: "<< pq.top() <<endl;
    cout<<"Size is: "<< pq.size() <<endl;
    if(pq.empty()) {
        cout<<"Empty"<<endl;
    }else {
        cout<<"Not Empty"<<endl;
    }

    //Min Heap
    cout<<endl<<"---Priority Queue Min Heap---"<<endl;
    priority_queue<int, vector<int>, greater<int>> minheap; 

    minheap.push(4);
    minheap.push(2);
    minheap.push(5);
    minheap.push(3);

    cout<<"Top element: "<< minheap.top() <<endl;
    minheap.pop();
    cout<<"Top element after pop: "<< minheap.top() <<endl;
    cout<<"Size is: "<< minheap.size() <<endl;
    if(minheap.empty()) {
        cout<<"Empty"<<endl;
    }else {
        cout<<"Not Empty"<<endl;
    }

    return 0;
}