#include <iostream>
#include <vector>
using namespace std;

// Mazority Element - Brute force Approach
// Time Complexity O(n2)

int majorityElement(vector<int> &arr)
{
    int n = arr.size();

    for (int val : arr)
    {
        int freq = 0;

        for (int el : arr)
        {
            if (el == val)
            {
                freq++;
            }
        }

        if (freq > n / 2)
        {
            return val;
        }
    }
}

int main()
{
    vector<int> arr = {2, 2, 1, 1, 1, 2, 2};
    int n = arr.size();

    cout << majorityElement(arr);
}