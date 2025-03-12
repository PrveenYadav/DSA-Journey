#include <iostream>
using namespace std;

//basic code for factorial
int factorial(int n) {

    if(n==0) return 1; //Base case : Tells, when you have to stop

    //Rcursive relation
    return n * factorial(n-1);
}

int main() {
    int n;
    cin>>n;

    cout<<factorial(n);
    return 0;
}