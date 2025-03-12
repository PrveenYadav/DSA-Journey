#include <iostream> 
using namespace std;

//check target exist
bool isPresent(int arr[][4], int target, int row, int col) {

    for ( int row = 0; row < 3; row++) {
        for (int col = 0; col < 4; col++) {

            if (arr[row][col] == target) {
                return 1;
            }
        }
    }
    return 0;
}

//Printing the sum
void printSum(int arr[][4], int row, int col) {

    cout<<"Sum of rows is: ";
    for ( int row = 0; row < 3; row++) {
        int sum = 0;
        for (int col = 0; col < 4; col++) {
            sum += arr[row][col];
        }
        cout<<sum<<" ";
    }
    cout<<endl;
}

//Largest sum and rows index
int maxSum(int arr[][4], int row, int col) {

    int maxi = INT8_MIN;
    int rowIndex = -1;

    for ( int row = 0; row < 3; row++) {
        int sum = 0;
        for (int col = 0; col < 4; col++) {
            sum += arr[row][col];
        }

        if (sum > maxi)
        {
            maxi = sum;
            rowIndex = row;
        }
        
    }
    cout<<"Maximum Sum is: "<<maxi<<endl;
    return rowIndex;
}


int main() {
    int arr[3][4];

    //Input 
    for ( int row = 0; row < 3; row++) {
        for (int col = 0; col < 4; col++) {
            cin>>arr[row][col];
        }
    }

    //printing 2D Arrays
    for ( int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    //code for check element found in Array or Not
    cout<<"Enter the target: ";
    int target;
    cin>>target;

    if (isPresent(arr, target, 3, 4)) {
        cout<<target<<" Element found in Array"<<endl;
    }else {
        cout<<target<<" Not found in Array"<<endl;
    }

    //function call to print sum of rows
    printSum(arr, 3, 4);

    //Maximum sum
    int ans = maxSum(arr, 3, 4);
    cout<<"Row Index is: "<<ans<<endl;
    
    return 0;
}