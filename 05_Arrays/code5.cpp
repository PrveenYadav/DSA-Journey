#include <iostream>
using namespace std;

//Write a function to calculate sum and product of Array
void sumOfArray(int arr[], int size)
{
    int sum = 0;

    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    cout<<"Sum of Array: "<<sum<<endl;
}

//Product Of Array
int productOfArray(int arr[], int size)
{
    int prod = 1;

    for (int i = 0; i < size; i++)
    {
        prod *= arr[i];
    }
    return prod;
}

int main()
{
    int arr[] = {4, 2, 3, 6, 8};
    int size = 5;

    sumOfArray(arr, size);
    cout<<"Product of Array: "<<productOfArray(arr, size)<<endl;
    return 0;
}