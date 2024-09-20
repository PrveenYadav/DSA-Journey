#include <iostream>
using namespace std;

// Write a function to print prime numbers from 2 to n
int printPrime(int n)
{
    int i = 2;

    while (i <= n - 1)
    {
        if (n % i != 0)
        {
            i += 1;
            cout<<i<<endl;
        }
        i++;
    }
}

int main()
{
    int n;
    cin >> n;
    printPrime(n);
}