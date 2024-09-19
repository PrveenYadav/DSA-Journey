#include <iostream>
using namespace std;

// Que - Pascal’s Triangle

int binomialCof(int n, int k) {
    int result = 1;
    if (k > n - k) {
        k = n - k; 
    }
    for (int i = 0; i < k; ++i) {
        result *= (n - i);
        result /= (i + 1);
    }
    return result;
}

int main() {
    int n;
    cout << "Enter the number of rows: ";
    cin >> n;

    // Loop for each row
    for (int i = 0; i < n; i++) {
        // spaces
        for (int j = 0; j < n - i - 1; j++) {
            cout << " ";
        }

        // Printing numbers
        for (int j = 0; j <= i; j++) {
            cout << binomialCof(i, j) << " ";
        }
        cout << endl;
    }

    return 0;
}
