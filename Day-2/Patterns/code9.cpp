#include <iostream>
using namespace std;

/*

Printing Pattern: This is my way to solve this Pattern

      1
    1 2 1
  1 2 3 2 1
1 2 3 4 3 2 1

*/

int main()
{
    int n;
    cin>>n;

    for (int i = 1; i <= n; i++)
    {
        //Spaces
        for (int j = 1; j <= n-i; j++)
        {
            cout<<" "<< " ";
        }

        // 1st Triangle
        for (int j = 1; j <= i; j++)
        {
            cout<<j<<" ";
        }

        // 2nd Triangle
        for (int j = i-1; j >= 1; j--)
        {
            cout<<j<<" ";
        }

        cout<<endl;
        
    }

    return 0;
        
}