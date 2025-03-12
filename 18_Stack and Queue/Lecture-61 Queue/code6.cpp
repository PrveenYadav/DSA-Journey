#include <iostream>
using namespace std;

//K queues in an Array
class kQueues {
public:
    int n;
    int k;
    int *arr;
    int *front;
    int *rear;
    int *next;
    int freeSlot;

public:
    //constructor
    kQueues(int n, int k) {
        this->n = n;
        this->k = k;
        front = new int[k];
        rear = new int[k];

        for(int i=0; i<k; i++) {
            front[i] = -1;
            rear[i] = -1;
        }

        next = new int[n];
        for(int i=0; i<n; i++) {
            next[i] = i+1;
        }
        next[n-1] = -1;

        arr = new int(n);
        freeSlot = 0;
    }

    //push/enqueue function
    void enqueue(int data, int qn) {
        //Overflow
        if(freeSlot == -1) {
            cout<<"No empty space is available"<<endl;
            //return ;
        }

        //find first free index
        int index = freeSlot;

        // update freeSpot
        freeSlot = next[index];

        //check wheater first element
        if(front[qn-1] == -1) {
            front[qn-1] = index;
        }else {
            //link new element to the previous element
            next[rear[qn-1]] = index;
        }

        //Update next
        next[index] = -1;

        //Update rear
        rear[qn-1] = index;

        //push element
        arr[index] = data;
    }

    int dequeue(int qn) {
        //UnderFlow check
        if(front[qn-1] == -1) {
            cout<<"Queue UnderFlow"<<endl;
            return -1;
        }

        //find index to pop
        int index = front[qn-1];

        //move forward to front
        front[qn-1] = next[index];

        //managing the free slot
        next[index] = freeSlot;
        freeSlot = index;

        return arr[index];
    }
};

int main() {
    cout<<endl;

    kQueues q(10, 3);

    q.enqueue(10, 1);
    q.enqueue(15, 1);
    q.enqueue(20, 2);
    q.enqueue(25, 1);

    cout<< q.dequeue(1) <<endl;
    cout<< q.dequeue(2) <<endl;
    cout<< q.dequeue(1) <<endl;
    cout<< q.dequeue(1) <<endl;

    cout<< q.dequeue(1) <<endl;
    return 0;
}