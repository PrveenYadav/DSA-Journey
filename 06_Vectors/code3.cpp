#include <iostream>
#include <vector>
using namespace std;

//Print Unique Value 
int main()
{
    vector<int> nums = {4, 1, 2, 1, 2};

    int ans = 0;

    for(int val : nums)
    {
        ans = ans^val;
    }
    cout<<ans;

    return 0;
}