#include <iostream> 
using namespace std;

//Two stack Implementation in a single Array: one from left-right, second from right-left
class TwoStack {
public:
    //properties  
    int *arr;
    int top1;
    int top2;
    int size;

    //behaviour/constructor/Initializing two stack
    TwoStack(int s) {
        size = s;
        top1 = -1; 
        top2 = s;
        arr = new int[s];
    }

    //Functions to perform Operations 

    //push in stack 1
    void push1(int num) {
        //Atleast one empty space is present
        if(top2-top1 > 1) {
            top1++;
            arr[top1] = num;
        }
    }

    //push in stack 2
    void push2(int num) {
        if(top2-top1 > 1) {
            top2--;
            arr[top2] = num;
        }
    }

    //pop in stack 1
    int pop1() { 
        if(top1 >= 0) {
            int ans = arr[top1];
            top1--;
            return ans;
        }else {
            return -1;
        }
    }

    //pop in stack 2
    int pop2() {
        if(top2 >= 0) {
            int ans = arr[top2];
            top2++;
            return ans;
        }else {
            return -1;
        }
    }
};

int main() {
    cout<<endl;

    TwoStack s1(5);
    TwoStack s2(5);

    s1.push1(7);
    s1.push2(8);

    cout<< s1.pop1() <<endl;
    return 0;
}