#include <iostream>
using namespace std;

// Create a program to calculate the sum of all even numbers between 1 and 100 using a `while` loop.
int main()
{
    int number = 2;
    int sum = 0;

    while (number <= 100)
    {
        sum += number;
        number += 2;
    }
    cout<<"Sum of 1 to 100 Even numbers: " << sum;

    return 0;
}