#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

//kth largest subarray sum

//Brute force approach : O(n^2logn) and space O(n^2)
int getKthLargest(vector<int> &arr, int k) {
    
    //Array to store all sums
    vector<int> sumStore;
    int n = arr.size();

    for(int i=0; i<n; i++) {
        int sum = 0;

        for(int j=i; j<n; j++) {
            sum = sum + arr[j];
            sumStore.push_back(sum);
        }
    }
    sort(sumStore.begin(), sumStore.end());

    return sumStore[sumStore.size() - k];
}

int kthLargest(vector<int> &arr, int k) {

    priority_queue<int, vector<int>, greater<int>> minHeap;

    int n = arr.size();
    for(int i=0; i<n; i++) {
        int sum = 0;
        for(int j=i; j<n; j++) {
            sum += arr[j];
            
            if(minHeap.size() < k) {
                minHeap.push(sum);
            }else {
                if(sum > minHeap.top()) {
                    minHeap.pop();
                    minHeap.push(sum);
                }
            }
        }
    }
    return minHeap.top();
    
}

int main() {
    cout<<endl;

    vector<int> arr = {4, 5, 6, 2, 1, 3};
    int n = arr.size();

    cout<<"Kth Largest Sub Array Sum: ";
    cout<< getKthLargest(arr, 3) <<endl;
    cout<<"Kth Largest Sub Array Sum Optimized: ";
    cout<< kthLargest(arr, 3) <<endl;

    return 0;
}