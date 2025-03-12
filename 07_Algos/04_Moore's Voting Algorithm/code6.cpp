#include <iostream>
#include <vector>
using namespace std;

// Majority Element

int findMajorityElement(vector<int> &arr)
{
    int freq = 0;
    int ans = 0;

    // Step 1: Find a potential candidate for the majority element
    for (int i = 0; i < arr.size(); i++)
    {
        if (freq == 0)
        {
            ans = arr[i];
        }

        if (ans == arr[i])
        {
            freq++;
        }
        else
        {
            freq--;
        }
    }

    // Step 2: Verify if the candidate is actually a majority element
    freq = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == ans)
        {
            freq++;
        }
    }

    if (freq > arr.size() / 2)
    {
        return ans;
    }
    else
    {
        return -1; // Return -1 if no majority element exists
    }

    return ans;
}

int main()
{
    vector<int> arr = {2, 2, 1, 1, 1};
    int n = arr.size();

    cout << findMajorityElement(arr);
}
