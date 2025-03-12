#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

//Problem: N stacks in an Array

class NStack {
    int *arr;   // Array to store all stack elements
    int *top;   // Array to store the top of each stack
    int *next;  // Array to store the next available index
    int free;   // Index of the next free slot
    int n, size;

public:
    // Constructor
    NStack(int N, int S) {
        n = N;            // Number of stacks
        size = S;         // Size of the array
        arr = new int[S];
        top = new int[N];
        next = new int[S];

        // Initialize top array
        for (int i = 0; i < N; i++) top[i] = -1;

        // Initialize next array
        for (int i = 0; i < S - 1; i++) next[i] = i + 1;
        next[S - 1] = -1;

        // Initialize free index
        free = 0;
    }

    // Push an element into the stack
    bool push(int stackNum, int value) {
        if (free == -1) return false; // No space available

        int index = free;         // Get the current free index
        free = next[index];       // Update free to the next available slot

        next[index] = top[stackNum]; // Link the new element to the current top
        top[stackNum] = index;    // Update the top of the stack

        arr[index] = value;       // Store the value
        return true;
    }

    // Pop an element from the stack
    int pop(int stackNum) {
        if (top[stackNum] == -1) return INT_MIN; // Stack is empty

        int index = top[stackNum]; // Get the top element's index
        top[stackNum] = next[index]; // Update the top to the next element in the stack

        next[index] = free;       // Link the popped index to the free list
        free = index;             // Update free to the popped index

        return arr[index];        // Return the popped value
    }
};

int main() {
    int N = 3, S = 10;
    NStack stacks(N, S);

    // Push elements into stack 1
    stacks.push(0, 10);
    stacks.push(0, 20);

    // Push elements into stack 2
    stacks.push(1, 30);
    stacks.push(1, 40);

    // Push elements into stack 3
    stacks.push(2, 50);
    stacks.push(2, 60);

    // Pop elements
    cout << "Popped from stack 0: " << stacks.pop(0) << endl;
    cout << "Popped from stack 1: " << stacks.pop(1) << endl;
    cout << "Popped from stack 2: " << stacks.pop(2) << endl;

    return 0;
}