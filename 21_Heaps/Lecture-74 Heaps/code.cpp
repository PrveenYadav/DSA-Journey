#include <iostream>
#include <vector>
using namespace std;

/* Heap introduction
Complete Binary Tree : Every level is completly filled except the last level. And Nodes always added from the left
Heap : Heap is a complete binary tree that comes with a heap order property. 
Max Heap : Every child node val is smaller than parent node val
Min Heap : Every child node val is Bigger than parent node val
*/

//Home Work: build heap take O(n) how
//Heap Implementation(we implements in Array) and Insertion : Deletion : Heap Sort
class Heap {
public: 
    int arr[100];
    int size;

    //constructor
    Heap() {
        arr[0] = -1;
        size = 0;
    }

    //Time Complexity O(log n)
    void insert(int val) {

        size = size + 1; //increase size
        int i = size; //creating index of Array size
        arr[i] = val; //insert val at the end of array

        while(i > 1) { //while tree has more than one node
            int parent = i/2;
            
            //swaping if val is greater than parent(because in max heap every child node becomes smaller than parent)
            if(arr[parent] < arr[i]) {
                swap(arr[parent], arr[i]);  
                i = parent; //i updating
            }else {
                return;
            }
        }
    }

    //Time Complexity O(log n)
    void deletion() {
        if(size == 0) {
            cout<<"Nothing to delete"<<endl;
            return ;
        }

        //step-1: swap/put first node with last node : //putting last node in the first node
        arr[1] = arr[size]; 

        //step-2: Remove last node : //size decreament because delete
        size--; 

        //step-3: Propogate root node to its correct possition
        int i = 1;
        while(i < size) {
            int leftIndex = 2*i;
            int rightIndex = 2*i+1;

            if(leftIndex < size && arr[i] < arr[leftIndex]) {
                swap(arr[i], arr[leftIndex]); 
                i = leftIndex;
            }
            else if(rightIndex < size && arr[i] < arr[rightIndex]) {
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            }else {
                return ;
            }
        }
    }

    void printHeap() {
        for(int i=1; i<=size; i++) {
            cout<< arr[i] <<" ";
        }cout<<endl;
    }
};

//Heapify Algo : To check heap and make valid heap : Time Complexity O(n)
void heapify(int arr[], int n, int i) {

    int largest = i; //largest element is on i
    int left = 2*i; //its left child
    int right = 2*i+1; //its right child

    if(left <= n && arr[largest] < arr[left]) {
        largest = left;
    }
    if(right <= n && arr[largest] < arr[right]) {
        largest = right;
    }

    if(largest != i) {
        swap(arr[largest], arr[i]);
        heapify(arr, n, i);
    }
}

//Heap Sort : Time Complexity O(nlogn)
void heapSort(int arr[], int n) {
    int size = n; 

    while(size > 1) {
        swap(arr[1], arr[size]);
        size--;

        heapify(arr, size, 1);
    }
}

int main() {
    cout<<endl;

    Heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    cout<<"Printing Heap: ";
    h.printHeap();

    cout<<"After Deletion of root node: ";
    h.deletion();
    h.printHeap();

    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;

    //heap creation
    for(int i=n/2; i>0; i--) {
        heapify(arr, n, i);
    }
    cout<<"Printing After Heapifying: ";
    for(int i=1; i<=n; i++) {
        cout<< arr[i] <<" ";
    }cout<<endl;

    //Heap Sort
    heapSort(arr, n);
    cout<<"Printing Heap Sort: ";
    for(int i=1; i<=n; i++) {
        cout<< arr[i] <<" ";
    }cout<<endl;

    return 0;
}