#include <iostream>
using namespace std;

/*
Printing Pattern:
      1
    1 2 1
  1 2 3 2 1
1 2 3 4 3 2 1
*/

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        // Spaces : n-i-1
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " " << " ";
        }

        // nums1 : i+1
        for (int j = 1; j <= i + 1; j++)
        {
            cout << j << " ";
        }

        // nums2 : i to 1
        for (int j = i; j >= 1; j--)
        {
            cout << j << " ";
        }

        cout << endl;
    }

    return 0;
}