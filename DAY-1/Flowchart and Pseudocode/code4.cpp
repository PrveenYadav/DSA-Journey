#include <iostream>
using namespace std;

// Check if a given number is even or odd
int main()
{
    int n;
    cin>>n;

    if (n%2 == 0)
    {
        cout<<n<<" is a Even Number";
    }else{
        cout<<n<<" is a Odd Number";
    }
    
    return 0;
}