#include <iostream>
using namespace std;

//Write a program that simulates a basic calculator with operations like addition, subtraction, multiplication, and division using conditional statements.
int main()
{
    double a, b;
    char operation;
    cout<<"Enter num1: ";
    cin>>a;
    cout<<"Enter num2: ";
    cin>>b;
    cout<<"Enter operation: ";
    cin>>operation;

    if (operation = '+')
    {
        cout<<"Result is: "<<a+b;
    }else if(operation = '-')
    {
        cout<<"Result is: "<<a-b;
    }else if(operation = '*')
    {
        cout<<"Result is: "<<a*b;
    }else
    {
        cout<<"Result is: "<<a/b;
    }
    
    return 0;
    
}