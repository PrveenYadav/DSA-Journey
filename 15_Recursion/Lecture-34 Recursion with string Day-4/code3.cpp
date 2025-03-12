#include <iostream>
using namespace std;

//Bubble sort by Recursion
void bubbleSort(int *arr, int n) {

    //base case
    if(n == 0 || n == 1) {
        return ;
    }

    //1 case has solved - further recursion will take care
    for (int i = 0; i < n-1; i++) {
        if(arr[i] > arr[i+1]) {
            swap(arr[i], arr[i+1]);
        }
    }

    //Recursive call
    bubbleSort(arr, n-1);
}

int main() {
    cout<<endl;
    int arr[] = {2, 11, 8, 7, 9};
    int n = 5;

    bubbleSort(arr, n);
    cout<<"Sorted Array"<<endl;
    for (int i = 0; i < n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}