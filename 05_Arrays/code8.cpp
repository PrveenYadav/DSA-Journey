
#include <iostream>
using namespace std;

void printUniqueValues(int arr[], int size) 
{
    cout << "Unique values in the array: ";

    for (int i = 0; i < size; i++) {
        bool isUnique = true;

        for (int j = 0; j < size; j++) {
            if (i != j && arr[i] == arr[j]) {
                isUnique = false; 
                break;
            }
        }

        // If no duplicates are found, print the element
        if (isUnique) {
            cout << arr[i] << " ";
        }
    }

    cout << endl;
}

int main() {
    int arr[] = {4, 5, 9, 4, 9, 8, 7, 10, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    printUniqueValues(arr, size);

    return 0;
}
