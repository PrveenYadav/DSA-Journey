#include <iostream>
#include <queue>
using namespace std;

//Problem: Kth smallest element : For kth largest element we use min heap

int kthSmallest(int arr[], int l, int r, int k) { // l and r is starting and ending index of array

    priority_queue<int> pq;

    //step-1
    for(int i=0; i<k; i++) {
        pq.push(arr[i]);
    }

    //step-2
    for(int i=k; i<=r; i++) {
        if(arr[i] < pq.top()) {
            pq.pop();
            pq.push(arr[i]);
        }
    }

    //step-3
    int ans = pq.top();
    return ans;
}

int main() {
    cout<<endl;

    int arr[] = {5, 4, 7, 3, 8, 9};
    int k = 4;

    int ans = kthSmallest(arr, 0, 5, k);  //0 and 5 are starting and ending index
    cout<<"Kth Smallest element: "<< ans <<endl; //4th smallest element is 7

    return 0;
}