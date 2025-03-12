#include <iostream>
using namespace std;

// Write a program to check if a number is positive, negative, or zero using conditional statements.
int main()
{
    int n;
    cin >> n;

    if (n >= 1)
    {
        cout << "Possitive";
    }
    else if (n < 0)
    {
        cout << "Negative";
    }
    else
    {
        cout << "Zero";
    }

    return 0;
}