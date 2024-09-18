#include <iostream>
using namespace std;

// Average of five input numbers
int main()
{
    int a, b, c, d, e;
    cout<<"Enter 5 numbers: ";
    cin>>a;
    cin>>b;
    cin>>c;
    cin>>d;
    cin>>e;

    int avg = (a + b + c + d + e) / 5;
    cout<<"Average is: "<<avg;
    
    return 0;
}