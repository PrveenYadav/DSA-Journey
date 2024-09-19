#include <iostream>
using namespace std;

/*
Printing Pattern
A
B A
C B A
D C B A
*/

int main()
{
    int n;
    cin>>n;
    
    for (int i = 1; i <= n; i++)
    {
        char ch = 'A';

        for (int j = 1; j <= i; j++)
        {
            cout<<char(ch + i - j)<<" ";
        }

        cout<<endl;
    }

    return 0;
}
