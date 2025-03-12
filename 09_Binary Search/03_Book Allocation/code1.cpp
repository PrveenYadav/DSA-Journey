#include <iostream>
#include <vector>
using namespace std;

// function to check if it is possible to allocate books with a maximum page limit.
bool isPossible(int arr[], int n, int m, long long maxPages)
{
    int studentCount = 1; // At least one student is required
    long long currentPages = 0;

    for (int i = 0; i < n; i++)
    {
        // If adding this book's pages exceeds maxPages, allocate to next student
        if (currentPages + arr[i] > maxPages)
        {
            studentCount++;
            currentPages = arr[i]; // Start new allocation with this book
            if (studentCount > m)
            {
                return false; // More students needed than available
            }
        }
        else
        {
            currentPages += arr[i]; // Add book's pages to current student
        }
    }
    return true;
}

// Function to find minimum number of pages.
long long findPages(int n, int arr[], int m)
{
    // Edge case: If number of students is greater than books
    if (m > n) return -1;

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    int result = -1;
    int low = 0, high = sum;

    // Perform binary search on the answer
    while (low <= high)
    {
        long long mid = low + (high - low) / 2;

        // Check if it's possible to allocate with mid as the maximum pages
        if (isPossible(arr, n, m, mid))
        {
            result = mid;   // If possible, this could be a potential answer
            high = mid - 1; // Try for a better (smaller) answer
        }
        else
        {
            low = mid + 1; // Otherwise, increase the mid value
        }
    }

    return result;
}

int main()
{
    int arr[] = {2, 1, 3, 4};
    int n = 4, m = 2;

    cout<< findPages(n, arr, m);
    return 0;
}
