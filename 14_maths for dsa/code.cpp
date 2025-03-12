#include <iostream>
using namespace std;

//Prime Number
bool isPrime(int n) {

    if(n<=1) return false;

    for (int i = 2; i < n; i++)
    {
        if (n%i == 0)
        {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin>>n;

    if(isPrime(n)) {
        cout<<"Prime number"<<endl;
    }else {
        cout<<"Not a prime number"<<endl;
    }
    return 0;
}