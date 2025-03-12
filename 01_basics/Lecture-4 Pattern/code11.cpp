#include <iostream>
using namespace std;

/*
Printing Pattern: Homework by me

*             *
* *         * *
* * *     * * *
* * * * * * * *
* * * * * * * *
* * *     * * *
* *         * *
*             *

*/

int main()
{
    int n;
    cin >> n;

    // Top
    for (int i = 0; i < n; i++)
    {
        // Stars
        for (int j = 0; j <= i; j++)
        {
            cout <<"* ";
        }

        // Spaces
    
        for (int j = 0; j < 2*(n-i)-2; j++)
        {
            cout << " " << " ";
        }

        // Stars
        for (int j = 0; j <= i; j++)
        {
            cout <<"* ";
        }

        cout << endl;
    }

    // Bottom
   for (int i = 0; i < n; i++)
    {
        // Stars
        for (int j = 0; j < n-i; j++)
        {
            cout << "* ";
        }

        // Spaces
        for (int j = 0; j < 2*i; j++)
        { 
           cout << " " << " ";
        }

        // Stars
        for (int j = 0; j < n-i; j++)
        {
            cout << "* ";
        }
        
        cout << endl;
    }

    return 0;
}