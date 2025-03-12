#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int> &arr, int n, int i) {
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if(left < n && arr[largest] < arr[left]) {
        largest = left;
    }
    if(right < n && arr[largest] < arr[right]) {
        largest = right;
    }

    if(arr[largest] != arr[i]) {
        swap(arr[largest], arr[i]);
        heapify(arr, n, i);
    }
}

//Problem: Merge two Binary Max-Heap
vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
    //step-1: Merge both arrays in one
    vector<int> ans;

    for(auto i: a)
        ans.push_back(i);
    for(auto i: b)
        ans.push_back(i);

    //step-2: Build heap using merged array
    int size = ans.size();
    for(int i=size/2-1; i>=0; i--) {
        heapify(ans, size, i);
    }

    //Printing heaps
    for(int i=0; i<size; i++){
        cout<< ans[i] <<" ";
    }cout<<endl;

    return ans;
}

int main() {
    cout<<endl;

    vector<int> a = {1, 2, 3, 4, 5};
    vector<int> b = {6, 7, 8, 9, 10};
    int n = a.size();
    int m = b.size();

    cout<<"Merge two Binary Heap: ";
    mergeHeaps(a, b, n, m);

    return 0;
}