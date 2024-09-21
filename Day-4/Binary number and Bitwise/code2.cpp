#include <iostream>
using namespace std;

int binToDecimal(int binNum)
{
    int ans = 0, pow = 1;

    while (binNum > 0)
    {
        int rem = binNum % 2;
        ans += rem * pow;

        binNum /= 10;
        pow *= 2;
    }

    return ans; // Decimal Number
}

int main()
{
    int binNum = 110010;

    cout <<binToDecimal(binNum) << endl;

    return 0;
}