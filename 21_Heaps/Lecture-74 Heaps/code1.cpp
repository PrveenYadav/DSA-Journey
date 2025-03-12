#include <iostream>
#include <vector>
using namespace std;

//Heapify Algo : Min Heap and Max Heap

//Heapify Algo : To check heap and make valid heap : Time Complexity O(n)
void heapify(vector<int> &arr, int n, int i) {

    int largest = i; //largest element is on i
    int left = 2*i; //its left child
    int right = 2*i+1; //its right child

    if(left < n && arr[largest] < arr[left]) {
        largest = left;
    }
    if(right < n && arr[largest] < arr[right]) {
        largest = right;
    }

    if(largest != i) {
        swap(arr[largest], arr[i]);
        heapify(arr, n, i);
    }
}

vector<int> buildMaxHeap(vector<int> &arr) {
    int n = arr.size();
    for(int i=n/2; i>=0; i--) {
        heapify(arr, n, i);
    }

    return arr;
}


//For min heap and Array starts from 0
void heapifyMin(vector<int> &arr, int n, int i) {

    int smallest = i; //largest element is on i
    int left = 2*i + 1; //its left child
    int right = 2*i + 2; //its right child

    if(left < n && arr[smallest] > arr[left]) {
        smallest = left;
    }
    if(right < n && arr[smallest] > arr[right]) {
        smallest = right;
    }

    if(smallest != i) {
        swap(arr[smallest], arr[i]);
        heapifyMin(arr, n, i);
    }
}

vector<int> buildMinHeap(vector<int> &arr) {
    int n = arr.size();
    for(int i=n/2-1; i>=0; i--) {
        heapifyMin(arr, n, i);
    }
    return arr;
}


void printHeap(vector<int> arr) {
    int n = arr.size();
    for(int i=0; i<n; i++) {
        cout<< arr[i] <<" ";
    }cout<<endl;
}

int main() {
    cout<<endl;

    vector<int> arr = {54, 53, 55, 52, 50};
    int n = 5;
    
    cout<<"Array is: ";
    printHeap(arr);

    cout<<"Max Heap After Heapifying: ";
    buildMaxHeap(arr);
    printHeap(arr);

    cout<<"Min Heap After Heapifying: ";
    buildMinHeap(arr);
    printHeap(arr);
    return 0;
}