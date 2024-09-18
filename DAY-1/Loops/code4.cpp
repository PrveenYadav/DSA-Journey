#include <iostream>
using namespace std;

// Implement a program that checks if a given number is prime using a loop.
int main()
{
    int n;
    cin>>n;

    int i = 2;
    while (i<=(n-1))
    {
        if (n%i == 0)
        {
            cout<<"Not Prime";
            break;
        }else{
            i += 1;
            cout<<"Prime";
            break;
        }
        
    }
    
    return 0;
    
}