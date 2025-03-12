#include <iostream>
using namespace std;

//Write a program that prints the multiplication table of a given number using a `for` loop.
int main()
{
    int n;
    cout<<"Enter the Number: ";
    cin>>n;

    for (int i = 1; i <= 10; i++)
    {
        cout<< n*i <<endl;
    }

    return 0;
    
}