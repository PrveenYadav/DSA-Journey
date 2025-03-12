#include <iostream>
using namespace std;

// Calculate Pow(x^n)
// Time Complexity O(n)
int power1(int a, int n)
{
    int result = 1;
    for (int i = 0; i < n; i++)
    {
        result *= a;
    }
    return result;
}

// Time Complexity O(log n)
int power(int a, int n)
{
    if (n == 0)
        return 1;
    int temp = power(a, n / 2);
    temp = temp * temp;
    if (n % 2 == 1)
    {
        return temp * a;
    }
    else
    {
        return temp;
    }
}

int main()
{
    int a = 2.00000;
    int n = 10;

    cout << power1(a, n) << endl;
    cout << power(a, n);
}