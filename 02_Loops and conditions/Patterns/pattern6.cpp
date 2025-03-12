#include <iostream>
using namespace std;

//  Diamond Pattern (Stars) = Pyramid + Inverted Pyramid Pattern
int main()
{
    int n;
    cin>>n;

    // 1st Outer Loop
    for (int i = 0; i < n; i++)
    {
        //spaces
        for (int j = 1; j <= n-(i+1); j++)
        {
            cout<<" ";
        } 

        //stars
        for (int j = 0; j <= i; j++)
        {
            cout<<"*";
        }

        //stars
        for (int j = 0; j <= i-1; j++)
        {
            cout<<"*";
        }
        
        cout<<endl;
    }

    // 2nd Outer Loop
    for (int i = 0; i < n; i++)
    {
        //spaces
        for (int j = 1; j <= i; j++)
        {
            cout<<" ";
        } 

        //stars
        for (int j = 0; j <= n-(i+1); j++)
        {
            cout<<"*";
        }

        //stars
        for (int j = 1; j <= n-(i+1); j++)
        {
            cout<<"*";
        }
        
        cout<<endl;
    }
    
    return 0;
}