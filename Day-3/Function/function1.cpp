#include <iostream>
using namespace std;

// Sum of n numbers
int sumN(int n){
    int sum = 0;

    for (int i = 0; i <= n; i++)
    {
        sum += i;
    }
    
    return sum;
}

// factorial of n numbers
int factorialN(int n)
{
    int fac = 1;

    for (int i = 1; i <= n; i++)
    {
        fac *= i;
    }
    
    return fac;
}

// Calculate the sum of Digits of Number
int sumOfDigits(int num)
{
    int digSum = 0;

    while (num>0)
    {
       int lastdig = num%10;
       num = num / 10;

       digSum = digSum + lastdig;
    }
    return digSum;
     
}

int main()
{
    cout << "Sum of n Numbers: " << sumN(5)<< endl;
    cout<< "Factorial of n Numbers: " << factorialN(5) << endl;

    cout << "sum of Digits of a number: " << sumOfDigits(145) <<endl;
    
    return 0;
}