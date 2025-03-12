#include <iostream>
using namespace std;

// Maximum Sub-Array sum
// Brute force Approach
// Time complexity O(n3)
// Space complexity O(1)
int main()
{
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = 8;

    int maximum = INT8_MIN;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int sum = 0;
            for (int k = i; k < j; k++)
            {
                sum =  sum + arr[k];
                maximum = max(sum, maximum);
            }
        }
    }
    cout << maximum;

    return 0; 
}