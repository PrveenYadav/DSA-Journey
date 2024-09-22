#include <iostream>
using namespace std;

//Write a function to swap max & min of an Array 
int swapMaxMin(int arr[], int size)
{
   int minIndex = 0, maxIndex = 0;

    for (int i = 0; i < size; i++)
    { 
        if (arr[i] < arr[minIndex])
        {
            minIndex = i;
        }
        if (arr[i] > arr[maxIndex])
        {
            maxIndex = i;
        }
    }
    int swap = arr[minIndex];
    arr[minIndex] = arr[maxIndex];
    arr[maxIndex] = swap;
}

int main()
{
    int arr[] = {3, 6, 2, 8, 9, 7};
    int size = 6;

    swapMaxMin(arr, size);

    cout << "Array after swapping max and min: ";
    for (int i = 0; i < size; i++)
    {
       cout<<arr[i]<<" ";
    }
    cout<<endl;
       
    return 0;
}