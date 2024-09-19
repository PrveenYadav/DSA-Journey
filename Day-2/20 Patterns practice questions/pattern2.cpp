#include <iostream>
using namespace std;

// Right-Angled Triangle (Stars)
int main()
{
    int n;
    cin>>n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout<<"*";
        } 
        cout<<endl;
    }
    
    return 0;
}