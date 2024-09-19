#include <iostream>
using namespace std;

// Zig-Zag Pattern
int main()
{
    int n = 3;

    // Outer loop for each row
    for (int i = 1; i <= n; i++)
    {

        // Inner loop for each column
        for (int j = 1; j <= 9; j++)
        {

            // Check if the position should have a '*'
            if (((i + j) % 4 == 0) || (i == 2 && j % 4 == 0))
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
