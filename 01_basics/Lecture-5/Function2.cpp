#include <iostream>
using namespace std;

// factorial of n numbers
int factorial(int n)
{
    int facN = 1;

    for (int i = 1; i <= n; i++)
    {
        facN *= i;
    }
    
    return facN;
}

int nCr(int n, int r)
{
    int fac_n = factorial(n);
    int fac_r = factorial(r);
    int fac_nmr = factorial(n-r);

    return fac_n / (fac_r * fac_nmr);
}

int main()
{
    //int n = 8, r = 2;
    int n;
    cout<<"Enter the number n: ";
    cin>>n;

    int r;
    cout<<"Enter the number r: ";
    cin>>r;

    cout << "Value of nCr is: " << nCr(n, r) << endl;
} 