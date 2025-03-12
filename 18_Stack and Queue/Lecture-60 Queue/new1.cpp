#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class Queue {
    Node *front, *rear;

public:
    // Constructor
    Queue() {
        front = rear = nullptr;
    }

    // Enqueue an element
    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (rear == nullptr) {
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }

    // Dequeue an element
    void dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty\n";
            return;
        }
        Node* temp = front;
        front = front->next;

        if (front == nullptr) rear = nullptr; // Queue becomes empty
        delete temp;
    }

    // Get the front element
    int peek() {
        if (front == nullptr) {
            cout << "Queue is empty\n";
            return -1;
        }
        return front->data;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Destructor
    ~Queue() {
        while (front != nullptr) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element: " << q.peek() << endl; // Output: 10
    q.dequeue();
    cout << "Front element: " << q.peek() << endl; // Output: 20

    q.enqueue(40);
    q.enqueue(50);

    while (!q.isEmpty()) {
        cout << q.peek() << " ";
        q.dequeue();
    }

    return 0;
}
