#include <iostream>
using namespace std;

// Inverted Right-Angled Triangle (Stars)
int main()
{
    int n;
    cin>>n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= n-i; j++)
        {
            cout<<"*";
        } 
        cout<<endl;
    }
    
    return 0;
}