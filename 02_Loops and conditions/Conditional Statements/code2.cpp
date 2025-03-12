#include <iostream>
using namespace std;

// Create a program to find the largest of three numbers using `if-else` statements.
int main()
{
    int a, b, c;
    cin>>a;
    cin>>b;
    cin>>c;

    if (a>b && a>c)
    {
        cout<<"Largest number is: " << a;
    }else if (b>a && b>c)
    {
        cout<<"Largest number is: " << b;
    }else{
        cout<<"Largest number is: " << c;
    }
    
    return 0;
    
}