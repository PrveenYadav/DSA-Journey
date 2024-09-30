#include <iostream>
#include <vector>
using namespace std;

// Mazority Element for sorted array - Optimal Approach
// Time Complexity O(n log n)

int majorityElement(vector<int> &arr)
{
    int n = arr.size();

    int freq = 1;
    int ans = arr[0];

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == arr[i - 1])
        {
            freq++;
        }
        else
        {
            freq = 1;
            ans = arr[i];
        }

        if (freq > n / 2)
        {
            return ans;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {2, 2, 1, 1, 1};
    int n = arr.size();

    cout << majorityElement(arr);
}