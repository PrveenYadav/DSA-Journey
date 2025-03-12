#include <iostream>
#include <vector>
using namespace std;

// Single Element in a sorted Array : Leetcode 540
int singleElement(vector<int> arr)
{
    int n = arr.size();
    if(n == 1) return arr[0];

    int start = 0, end = n-1;

    while(start <= end)
    {
        int mid = start + (end-start) / 2;

        if(mid == 0 && arr[0] != arr[1]) return arr[mid];
        if(mid == n-1 && arr[n-1] != arr[n-2]) return arr[mid];

        if(arr[mid-1] != arr[mid] && arr[mid] != arr[mid+1]) return arr[mid];

        if(mid%2 == 0) //Even
        {
            if (arr[mid-1] == arr[mid]) // Left
            {
                end = mid-1;
            }else{ // Right
                start = mid + 1;
            }
            
        }else{ // Odd
            
            if (arr[mid-1] == arr[mid]) // Right
            {
                start = mid + 1;
            }else{ // Left
                end = mid-1;
            }
        }
    }

}

int main()
{
    vector<int> arr = {1, 1, 2, 3, 3, 4, 4, 8, 8};

    cout << singleElement(arr);
}