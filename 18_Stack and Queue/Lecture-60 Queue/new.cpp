#include <iostream>
using namespace std;

class Queue {
    int* arr;
    int front, rear, size, capacity;

public:
    // Constructor
    Queue(int cap) {
        capacity = cap;
        arr = new int[cap];
        front = 0;
        size = 0;
        rear = -1;
    }

    // Enqueue an element
    void enqueue(int value) {
        if (size == capacity) {
            cout << "Queue is full\n";
            return;
        }
        rear = (rear + 1) % capacity; // Circular increment
        arr[rear] = value;
        size++;
    }

    // Dequeue an element
    void dequeue() {
        if (size == 0) {
            cout << "Queue is empty\n";
            return;
        }
        front = (front + 1) % capacity; // Circular increment
        size--;
    }

    // Get the front element
    int peek() {
        if (size == 0) {
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[front];
    }

    // Check if the queue is empty
    bool isEmpty() {
        return size == 0;
    }

    // Destructor
    ~Queue() {
        delete[] arr;
    }
};

int main() {
    Queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element: " << q.peek() << endl; // Output: 10
    q.dequeue();
    cout << "Front element: " << q.peek() << endl; // Output: 20

    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.enqueue(70); // Queue is full

    while (!q.isEmpty()) {
        cout << q.peek() << " ";
        q.dequeue();
    }

    return 0;
}