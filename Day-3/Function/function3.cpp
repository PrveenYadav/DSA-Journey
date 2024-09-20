#include <iostream>
using namespace std;

// Write a function to check number is Prime or not
int checkPrime(int n)
{
    int i = 2;
    while (i <= n - 1)
    {
        if (n % i == 0)
        {
            cout << "Non-Prime";
            break;
        }else
        {
            i += 1;
            cout<<"Prime";
            break;
        }
    }

}

int main()
{
    int n;
    cin>>n;
    checkPrime(n);
}