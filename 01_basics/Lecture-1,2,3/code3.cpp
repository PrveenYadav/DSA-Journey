#include <iostream>
using namespace std;

// Homework: check if number is prime or not and Nested loops

int main()
{
    int n;
    cin>>n;

    if (n%2 == 0)
    {
        cout<<n<<" is a Prime Number"<<endl;
    }
    else
    {
        cout<<n<<" is Not a Prime Number";
    }

    return 0;
}