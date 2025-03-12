#include <iostream>
using namespace std;

//Fibonacci Number : Leetcode 509
int fibonoacci(int n) {

    //Base case
    if(n == 0)
        return 0;

    if(n == 1)
        return 1;

    //Recursive Relation
    int ans = fibonoacci(n-1) + fibonoacci(n-2);

    return ans;
}

int main() {

    int n;
    cin>>n;

    cout<< n <<" th Fibonacci is " << fibonoacci(n) <<endl;
}