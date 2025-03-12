#include <iostream>
#include <vector>
using namespace std;

//Count Primes : Leetcode 204 (midium)
//Time complexity: O(n*log(log n))
int countPrimes(int n) {

    int count = 0;
    vector<bool> prime(n+1, true); //initiallizing prime no.

    prime[0] = prime[1] = false; // 0 & 1 is not prime no.

    for(int i=2; i<n; i++) {    //traverse 2 to n

        if(prime[i]) {          //if prime then increase the count
            count++;

            for(int j=2*i; j<n; j=j+i) { //cancelout the table of that no.   //How much numbers are in the Table of that number then cancelout them or 0
                prime[j] = 0;
            }
        }
    }
    return count;
}

int main() {
    int n;

    cout<<"Enter the number: ";
    cin>>n;

    cout<<countPrimes(n)<<" Prime numbers"<<endl;
    return 0;
}