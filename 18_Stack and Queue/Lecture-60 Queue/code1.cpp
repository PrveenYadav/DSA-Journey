#include <iostream>
#include <queue>
using namespace std;

//Implementing queue - using Arrays : HomeWork is - Implementation using Linked List
//enqueue - push()
//dequeue - pop()

class Queue {
public:
    int *arr;
    int isFront;
    int rear;
    int size;

    //constructor
    Queue() {
        size = 1000001; //giving some big values to size
        arr = new int(size);
        isFront = 0;
        rear = 0;
    } 

    void push(int element) {
        if(rear == size) { //condition to chech queue is full or not and then perform push() operation
            cout<<"Queue is full"<<endl;
            return ;
        }else {
            arr[rear] = element;
            rear++;
        }
    }

    int pop() {
        if(isFront == rear) { //cheking queue is empty or not and then pop() operation
            //cout<<"Queue is empty"<<endl;
            return -1;
        }else {
            int ans = arr[isFront];
            arr[isFront] = -1;
            isFront++;
            if(isFront == rear) { //after pop() operation, utilizing the space
                isFront = 0;
                rear = 0;
            }
            return ans; //returning the pop() element
        }
    }

    int front() {
        if(isFront == rear) {
            return -1;
        }else {
            return arr[isFront];
        }
    }

    bool isEmpty() {
        if(isFront == rear) {
            return true;
        }else {
            return false;
        }
    }
};


void inputQueue(Queue &q, int n) {
    for(int i=0; i<n; i++) {
        int x;
        cin>>x;
        q.push(x);
    }
}

void printQueue(Queue q) {
    while(!q.isEmpty()) {
        cout<< q.front() <<" ";
        q.pop();
    }
    cout<<endl;
}

int main() {
    cout<<endl;

    Queue q1;
    
    q1.push(1);
    q1.push(2);
    q1.push(3);

    cout<<"Front element: "<< q1.front() <<endl;
    q1.pop();

    cout<<"After pop operation front element: "<< q1.front() <<endl;
    cout<<"Printing Queue: ";
    printQueue(q1);
    return 0;
}