#include <iostream>
#include <vector>
using namespace std;

// Peak Index in Mountain Array : Leetcode 852
int peakIndex(vector<int> arr)
{
    int start = 1;
    int end = arr.size() - 2;

    while(start <= end)
    {
        int mid = start + (end-start) / 2;

        if(arr[mid-1] < arr[mid] && arr[mid] > arr[mid+1])
        {
            return mid;
        }else if(arr[mid-1] < arr[mid])
        {
            start = mid + 1;
        }else{
            end = mid - 1;
        }
    }
    
}

int main()
{
    vector<int> arr = {0,1,0};

    cout << peakIndex(arr);
}