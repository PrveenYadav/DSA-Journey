#include <iostream>
using namespace std;

// Optimal - Kadane's Algorithm
// Time complexity O(n)
// Space complexity O(1)

int main()
{
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = 8;

    int maxSum = INT8_MIN;
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
        maxSum = max(maxSum, sum);

        if (sum < 0)
        {
            sum = 0;
        }
    }
    
    cout << maxSum;
}