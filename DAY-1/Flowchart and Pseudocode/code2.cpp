#include <iostream>
using namespace std;

//sum of the first 10 natural numbers
int main()
{
    int n = 10;
    int sum = 1;

    for (int i = 1; i <= n; i++)
    {
        sum += i;
    }
    cout<<sum;
    
}