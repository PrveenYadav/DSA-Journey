#include <iostream>
using namespace std;


int sumOfDig(int num)
{
    int sum = 0;

    while (num>0)
    {
        int lastDig = num%10;
        num = num/10;

        sum = sum + lastDig;
    }

    return sum;   
}


int main()
{
    cout<<"sum = "<<sumOfDig(1845);
    return 0;
}