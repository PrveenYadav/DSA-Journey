#include <iostream>
using namespace std;

//Search the Index of target value
int lenearSearch(int arr[], int size, int target)
{
    for (int i = 0; i < size; i++)
    {
       if (arr[i] == target)
       {
        return i;
       }
    }
    return -1;
}

int main()
{
    int arr[] = {4, 2, 7, 8, 15, 9, 11};
    int size = 7;
    int target = 8;

    cout<<lenearSearch(arr, size, target)<<endl;
    return 0;
}