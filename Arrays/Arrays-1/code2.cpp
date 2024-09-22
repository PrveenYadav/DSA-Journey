#include <iostream>
using namespace std;

//Find the Smallest and Largest number in array and Those Index
int main()
{
    int nums[] = {5, 15, 8, -12, 24, -5};
    int size = 6;

    int smallest = INT8_MAX; //INT8_MAX = +infinitive
    int largest = INT8_MIN;

    int smallestIndex = 0; // Initializing index to 0
    int largestIndex = 0;

    for (int i = 0; i < size; i++)
    {
        if (nums[i] < smallest)
        {
            smallest = nums[i];
            smallestIndex = i;
        }
        if (nums[i] > largest)
        {
            largest = nums[i];
            largestIndex = i;
        }
    }

    cout<<"Largest number is: "<<largest<<endl;
    cout<<"Largest Index is: "<<largestIndex<<endl;

    cout<<"Smallest number is: "<<smallest<<endl;
    cout<<"Smallest Index is: "<<smallestIndex<<endl;
    
    return 0;
}