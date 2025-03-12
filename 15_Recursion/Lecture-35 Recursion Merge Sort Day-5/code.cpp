#include <iostream>
using namespace std;

//merge two sorted Array
void merge(int *arr, int st, int end) {

    int mid = st + (end-st)/2;

    int len1 = mid - st + 1;   //left part length
    int len2 = end - mid;       //right part length

    int *first = new int[len1];
    int *second = new int[len2];

    //copy values of left
    int mainArrayIndex = st;
    for(int i=0; i<len1; i++) {
        first[i] = arr[mainArrayIndex++];
    }

    //copy value of right
    mainArrayIndex = mid+1;
    for(int i=0; i<len2; i++) {
        second[i] = arr[mainArrayIndex++];
    }

    //merge two sorted Arrays
    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = st;

    while(index1 < len1 && index2 < len2) {

        if(first[index1] < second[index2]) {
            arr[mainArrayIndex++] = first[index1++];
        }else {
            arr[mainArrayIndex++] = second[index2++];
        }
    }

    //separatelly checking also
    while(index1 < len1) {
        arr[mainArrayIndex++] = first[index1++];
    }

    while(index2 < len2) {
        arr[mainArrayIndex++] = second[index2++];
    }
}

//Merge Sort
void mergeSort(int *arr, int st, int end) {

    //base case
    if(st >= end) {
        return ;
    }

    int mid = st + (end-st)/2;

    //left part sort
    mergeSort(arr, st, mid);

    //Right part sort
    mergeSort(arr, mid+1, end);

    //Merge
    merge(arr, st, end);
}

int main() {
    cout<<endl;
    
    int arr[] = {2, 18, 11, 7, 9};
    int size = 5;

    mergeSort(arr, 0, size-1);
    cout<<"Sorted Array by Merge Sort: ";
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}