#include <iostream> 
using namespace std;

//Implementing stack: without using c++ stl, creating a class for stack which do basic operations like - push, pop, top, empty, size etc.
//we can implement stack in 2 ways - using Arrays and using Linked List

//Implementing stack in Arrays
class Stack {
public:
    //properties  
    int *arr;
    int top;
    int size;

    //behaviour
    Stack(int size) {
        this->size = size;
        arr = new int[size];
        top = -1; 
    }

    //Functions to perform Operations 

    void push(int element) {
        if(size-top > 1) {
            top++;
            arr[top] = element;
        }else {
            cout<<"Stack Overflow"<<endl;
        }
    }

    void pop() {
        if(top >= 0) {
            top--;
        }else {
            cout<<"Stack Underflow"<<endl;
        }
    }

    int peak() {
        if(top >= 0) {
            return arr[top];
        }else {
            cout<<"Stack is Empty"<<endl;
        }
    }

    bool isEmpty() {
        if(top == -1) {
            return true;
        }else {
            return false; 
        }
    }

};

int main() {
    cout<<endl;

    Stack s1(5); //5 elements can insert, 5 is size

    s1.push(7);
    s1.push(8);

    cout<< s1.peak() <<endl;
    cout<< s1.peak() <<endl;
    cout<< s1.peak() <<endl;
    return 0;
}