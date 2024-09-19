#include <iostream>
using namespace std;

// Butterfly Pattern
int main()
{
    int n;
    cin >> n;

    // Top
    for (int i = 1; i <= n; i++)
    {
        //stars
        for (int j = 1; j <= i; j++)
        {
            cout<<"*";
        }

        //spaces
        for (int j = 1; j <= 2* (n-i); j++)
        {
           cout<<" ";
        }

        //stars
        for (int j = 1; j <= i; j++)
        {
            cout<<"*";
        }

        cout<<endl;
    }

    // Bottom
    for (int i = 1; i <= n; i++)
    {
         //stars
         for (int j = 1; j <= n-i; j++)
         {
             cout<<"*";
         }

        //spaces
        if (i < n)
        {
            for (int j = 1; j <= 2 * i; j++)
            {
                cout << " ";
            }
        }

        //stars
        for (int j = 1; j <= n-i; j++)
        {
            cout<<"*";
        }

        cout << endl;
    }

    return 0;
}