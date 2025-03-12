#include <iostream>
using namespace std;

/* 
Printing Pattern:
1 1 1 1
  2 2 2
    3 3
      4
*/

int main()
{
    int n;
    cin>>n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout<<" "<<" ";
        }
        for (int j = 1; j <= n-i; j++)
        {
            cout<<i+1<<" ";
        }
        
        cout <<endl;    
    }

    return 0;
}