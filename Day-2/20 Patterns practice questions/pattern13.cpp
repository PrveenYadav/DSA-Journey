#include <iostream>
using namespace std;

//  Hollow Pyramid
int main()
{
    int n;
    cin>>n;

    for (int i = 1; i <= n; i++)
    {
        //spaces
        for (int j = i; j < n; j++)
        {
            cout<<" ";
        } 

        //stars
        for (int j = 1; j <= (2*i-1); j++)
        {
            
            if (i == n || j == 1 || j == 2*i-1)
            {
                cout<<"*";
            } else{
                cout<<" ";
            }    
        }

        cout<<endl;
    }
    
    return 0;
}