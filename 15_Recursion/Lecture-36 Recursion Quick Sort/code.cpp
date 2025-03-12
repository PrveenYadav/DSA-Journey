#include <iostream>
using namespace std;

int partition(int arr[], int start, int end) {

    int pivot = arr[start];

    int count = 0;
    for(int i=start+1; i<=end; i++) {
        if(arr[i] <= pivot) {
            count++;
        }
    }

    //Place pivot at right position
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);

    int i = start, j = end;
    while(i < pivotIndex && j > pivotIndex) {

        while(arr[i] <= pivot) {
            i++;
        }

        while(arr[j] >= pivot) {
            j--;
        }

        if(i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;
}

//Quick Sort
void quickSort(int *arr, int st, int end) {

    //base case
    if(st >= end) {
        return ;
    }

    //Partition
    int p = partition(arr, st, end);

    //Recursive call
    quickSort(arr, st, p-1);
    quickSort(arr, p+1, end);
}

int main() {
    cout<<endl;

    int arr[] = {9, 2, 11, 6, 13, 7};
    int size = 6;

    quickSort(arr, 0, size-1);
    cout<<"Sorted Array is: ";
    for(int i=0; i<size; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}