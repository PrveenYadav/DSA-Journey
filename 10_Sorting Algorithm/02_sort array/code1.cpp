#include <iostream>
#include <vector>
using namespace std;

// Dutch National Flag Algorithm : Time Complexity O(n)
// Sort Array with 0s 1s & 2s

int arraySort(vector<int> &arr, int n) 
{
    int low = 0, mid = 0, high = n-1;

    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[low], arr[mid]);
            mid++; low++;
        }else if(arr[mid] == 1){
            mid++;
        }else{
            swap(arr[high], arr[mid]);
            high--;
        }
    }
}

void printArray(vector<int> &arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    vector<int> arr = {2, 0, 2, 1, 1, 0};
    int n = 6;

    arraySort(arr, n);
    printArray(arr, n);
    return 0;
}