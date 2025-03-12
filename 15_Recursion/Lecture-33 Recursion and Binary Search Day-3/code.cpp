#include <iostream>
using namespace std;

//Check sorted or not in Recursion
bool isSorted(int arr[], int n) { //we can use *arr or arr[]

    if(n == 0 || n == 1) {
        return true;
    }

    if(arr[0] > arr[1]) {
        return false;
    } else {
        bool ans = isSorted(arr+1, n-1);
        return ans;
    }
}

int main() {

    int arr[] = {2, 4, 6, 8, 9};
    int size = 5;

    int ans = isSorted(arr, size);

    if(ans) {
        cout<<"Array is Sorted"<<endl;
    }else {
        cout<<"Array is Not Sorted"<<endl;
    }
    return 0;
}