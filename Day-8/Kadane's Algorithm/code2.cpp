#include <iostream>
using namespace std;

// Brute force Better Approach
// Time complexity O(n2)
// Space complexity O(1)
int main ()
{
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = 8;

    int maximum = INT8_MIN;

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum = sum + arr[j];
            maximum = max(maximum, sum);
        }
    }
    cout<<maximum;
    return 0;
}