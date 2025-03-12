#include <iostream>
using namespace std;

// binomial coficient formula nCr = n! / r! (n-r)!
int fac(int n)
{
    int fac = 1;

    for (int i = 1; i <= n; i++)
    {
        fac = fac*i;
    }
    return fac;
}

int binFac(int n , int r){

    int factorialN = fac(n);
    int factorialR = fac(r);
    int factorialNmr = fac(n-r);

    return factorialN / (factorialR*factorialNmr);

}

int main()
{
    int n = 8;
    int r = 2;
    cout<<"fac = "<<binFac(n, r);
    return 0;
}