#include <iostream>
using namespace std;

//Write a program that calculates the factorial of a number using a `for` loop.
int main()
{
    int n;
    cin>>n;
    int fac = 1;

    for (int i = 1; i <= n; i++)
    {
        fac *= i;
    }
    cout<<fac;
    
}