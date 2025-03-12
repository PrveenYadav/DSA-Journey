#include <iostream>
using namespace std;

/* 
Printing Pattern:
*   or  1   or  1   or  A
**      22      12      BB
***     333     123     CCC
*/      


int main()
{
    int n;
    cin>>n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout<<"*";
            // cout<<i;
           // cout<<j;
        }
        cout<<endl;
    }
    return 0;
}

/*
int main()
{
    int n;
    cin>>n;
    
    for (int i = 1; i <= n; i++)
    {
        char ch = 'A';
        char value = ch + i - 1;

        for (int j = 1; j <= i; j++)
        {
            cout<<value;
        }

        cout<<endl;
    }

    return 0;
}
*/