#include <iostream>
#include <vector>
using namespace std;

// Maximum sub-array sum 
// Brute-force Approach
int main()
{
    int arr[7] = {3, -4, 5, 4, -1, 7, -8};
    int size = 7;
    
    int maxSum = INT8_MIN;

    for (int st = 0; st < size; st++)
    {
        int curSum = 0;
        for (int end = st; end < size; end++)
        {
            curSum += arr[end];
            maxSum = max(curSum, maxSum);
        }
    }
    cout<<"Maximum Sub-Array sum: "<<maxSum;
    return 0;  
}