#include <iostream>
using namespace std;

//How the Recursion works
void print(int *arr, int n) {

    cout<<"Size of Array is: "<< n <<endl;

    for(int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

//Finding key in Recursion by Linear Search
bool findKey(int *arr, int n, int key) {
    
    print(arr, n);

    if(n == 0) {
        return false;
    }

    if(arr[0] == key) {
        return true;
    } else {
        bool rest = findKey(arr+1, n-1, key);
        return rest;
    }
}

int main() {

    int arr[] = {2, 4, 6, 8, 9};
    int size = 5;
    int key = 8;

    int ans = findKey(arr, size, key);

    if(ans) {
        cout<<"Present"<<endl;
    }else {
        cout<<"Not Present"<<endl;
    }
    return 0;
}