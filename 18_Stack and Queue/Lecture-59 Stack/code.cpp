#include <iostream>
#include <stack>
using namespace std;

//Problem: Design a stack that supports getMin() in O(1) time and O(1) extra space
class MinStack {
    stack<long long> s;
    long long minElement;

public:
    MinStack() {
        while (!s.empty()) s.pop();
    }

    // Push an element onto the stack
    void push(int value) {
        if (s.empty()) {
            s.push(value);
            minElement = value; //Initialize minElement
        } else {
            if (value < minElement) {
                // Store a special encoded value
                s.push(2LL * value - minElement);
                minElement = value;
            } else {
                s.push(value);
            }
        }
    }

    // Pop the top element from the stack
    void pop() {
        if (s.empty()) return;

        long long top = s.top();
        s.pop();

        if (top < minElement) {
            // Restore the previous minimum
            minElement = 2LL * minElement - top;
        }
    }

    // Get the top element of the stack
    int top() {
        if (s.empty()) return -1;

        long long top = s.top();
        if (top < minElement) {
            // Return the minimum element as the current top
            return minElement;
        } else {
            return top;
        }
    }

    // Get the minimum element in the stack
    int getMin() {
        if (s.empty()) return -1;
        return minElement;
    }
};

int main() {
    MinStack minStack;

    minStack.push(10);
    minStack.push(20);
    cout << "Minimum: " << minStack.getMin() << endl; // Output: 10
    minStack.push(5);
    cout << "Minimum: " << minStack.getMin() << endl; // Output: 5
    minStack.pop();
    cout << "Minimum: " << minStack.getMin() << endl; // Output: 10
    minStack.pop();
    cout << "Top: " << minStack.top() << endl;       // Output: 10
    cout << "Minimum: " << minStack.getMin() << endl; // Output: 10

    return 0;
}
