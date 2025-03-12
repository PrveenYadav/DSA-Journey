#include <iostream>
using namespace std;

//Recursion
//basic code for factorial
int factorial(int n) {

    //base case
    if(n==0) return 1; //Base case : Tells, when you have to stop

    int small = factorial(n-1);
    int big = n * small;

    return big;
}

int main() {
    int n;
    cin>>n;

    cout<<factorial(n);
    return 0;
}