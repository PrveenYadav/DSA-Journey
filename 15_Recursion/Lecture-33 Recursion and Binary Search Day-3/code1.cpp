#include <iostream>
using namespace std;

//Calculating sum in Recursion
int getSum(int *arr, int n) {

    if(n == 0) {
        return 0;
    }
    if(n == 1) {
        return arr[0];
    }

    int remaningPart = getSum(arr+1, n-1);
    int sum = arr[0] + remaningPart;
    return sum;
}

int main() {

    int arr[] = {2, 4, 6, 8, 9};
    int size = 5;

    int sum = getSum(arr, size);

    cout<<"Sum is: "<< sum <<endl;
    return 0;
}