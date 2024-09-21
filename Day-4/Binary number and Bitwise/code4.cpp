#include <iostream>
using namespace std;

int reverseInteger(int n) {
    int reversed = 0;

    while (n != 0) {
        int lastDigit = n % 10;  
        n /= 10;                 
        reversed = reversed * 10 + lastDigit; 
    }

    return reversed;
}

int main() {
    int num;
    cout << "Enter an integer: ";
    cin >> num;

    cout << "Reversed integer: " << reverseInteger(num) << endl;

    return 0;
}