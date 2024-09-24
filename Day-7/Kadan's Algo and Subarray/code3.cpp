#include <iostream>
#include <vector>
using namespace std;

// Maximum sub-array sum
// Kadane's Algorithm
int main()
{
    int arr[7] = {3, -4, 5, 4, -1, 7, -8};
    int n = 7;

    int curSum = 0;
    int maxSum = INT8_MIN;

    for(int val : arr)
    {
        curSum += val;
        maxSum = max(curSum, maxSum);
        if (curSum < 0)
        {
            curSum = 0;
        }
    }
    cout << "Maximum Sub-Array sum: " << maxSum;
    return 0;
}