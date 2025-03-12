#include <iostream> 
using namespace std;

// Write a program to swap two variables without using a third variable.
int main()
{
    int a, b;
    cout<<"Enter first number: ";
    cin>>a;
    cout<<"Enter second number: ";
    cin>>b;

    a = a + b;
    b = a - b;
    a = a - b;

    cout<<"After swaping value of a is: " << a << endl;
    cout<<"After swaping value of b is: " << b;

    return 0;

}