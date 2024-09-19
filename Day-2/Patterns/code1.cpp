#include <iostream>
using namespace std;

/* Printing Pattern
123 or  *** or  ABC
123     ***     ABC
123     ***     ABC
*/

int main()
{
    int n;
    cin>>n;

    // We can use iteration like i=0 to i<n OR i=1 to i<=n

    for (int i = 1; i <= n; i++) // Outer Loop 
    {
        for (int j = 1; j <= n; j++) // Inner Loop
        {
            cout<<"j"; // cout j or *
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

        for (int j = 1; j <= n; j++)
        {
            cout<<ch;
            ch++;
        }
        cout<<endl;
    }

    return 0;
}
*/