#include <iostream>
using namespace std;

// Write a Function to print intersection of Two Array
void printIntersection(int arr1[], int size1, int arr2[], int size2)
{
    cout<<"Intersection of Two Arrays: ";
    for (int i = 0; i < size1; i++)
    {
        for (int j = 0; j < size2; j++)
        {
            if (arr1[i] == arr2[j])
            {
                cout << arr1[i] << " ";
                break;
            }
        }
    }

    cout << endl;
}

int main()
{
    int arr1[] = {3, 6, 9, 15, 7, 11};
    int size1 = 6;
    int arr2[] = {2, 5, 15, 3, 7};
    int size2 = 5;

    printIntersection(arr1, size1, arr2, size2);
    return 0;
}