#include <iostream>
#include <vector>
using namespace std;

// Moore's Voting Algorithm
// Time Complexity O(n)
int main()
{
    vector<int> arr = {1, 2, 3, 2, 3, 3};
    int n = arr.size();

    int freq = 0, ans = 0;

    for (int i = 0; i < n; i++)
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
    cout << ans;
    return 0;
}