#include <iostream>
using namespace std;

/* 
Printing Pattern:
123 or  ABC
456     DEF
789     GHI
*/

int main()
{
    int n;
    cin>>n;
    //int count = 1; 
    char ch = 'A';

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<ch; // count or ch
            ch++;
        }
        cout <<endl;    
    }

    return 0;
}