#include <iostream>
using namespace std;

/*
Printing Pattern:

      *
    *   *
  *       *
*           *
  *       *
    *   *
      *
*/

int main()
{
    int n;
    cin >> n;


    //Top
    for (int i = 0; i < n; i++)   // 1st Outer loop
    {
        // Spaces : n-i-1
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " " << " ";
        }
        cout << "* ";

        if (i != 0)
        {   //spaces
            for (int j = 0; j < 2 * i - 1; j++)
            {
                cout << " " << " ";
            }
            cout << "* ";
        }

        cout << endl;
    }

    // Bottom
    for (int i = 0; i < n-1; i++)     // 2nd Outer loop
    {
        // Spaces
        for (int j = 0; j < i + 1; j++)
        {
            cout << " " <<" ";
        }
        cout << "* ";

        if (i != n-2)
        {   //spaces
            for (int j = 0; j < 2*(n-i)-5; j++)
            { 
                cout << " " << " ";
            }
            cout << "* ";
        }

        cout << endl;
    }

    return 0;
}