#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    // Upper half (inverted pyramid)
    for (int i = n; i >= 1; i--) {

        // spaces
        for (int j = 0; j < n - i; j++) {
            cout << " ";
        }

        //stars and spaces
        for (int j = 1; j <= (2 * i - 1); j++) {
            if (j == 1 || j == (2 * i - 1) || i == n) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }

    // Lower half (pyramid)
    for (int i = 1; i <= n; i++) {

        // spaces
        for (int j = 0; j < n - i; j++) {
            cout << " ";
        }

        //stars and spaces
        for (int j = 1; j <= (2 * i - 1); j++) {
            if (j == 1 || j == (2 * i - 1) || i == n) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
