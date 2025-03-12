#include <iostream>
using namespace std;

//How the Recursion works
void print(int arr[], int start, int end) {

    for(int i=start; i<=end-1; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

//Finding key in Recursion by Binary Search
bool binarySearch(int *arr, int start, int end, int key) {

    cout<<endl;
    print(arr, start, end);

    if(start > end) {
        return false;
    }

    int mid = start + (end-start)/2;
    cout<<"Value of Mid is "<< mid <<endl;

    if(arr[mid] == key) {
        return true;
    }

    if(arr[mid] < key) {
        return binarySearch(arr, mid+1, end, key);
    } else {
        return binarySearch(arr, start, mid-1, key);
    }
}

int main() {

    int arr[] = {2, 4, 6, 8, 9};
    int size = 5;
    int key = 9;

    int ans = binarySearch(arr, 0, 5, key);

    if(ans) {
        cout<<"Present"<<endl;
    }else {
        cout<<"Not Present"<<endl;
    }
    return 0;
}