#include <iostream>
using namespace std;

// Inverted Pyramid Pattern(stars)
int main()
{
    int n;
    cin>>n;

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