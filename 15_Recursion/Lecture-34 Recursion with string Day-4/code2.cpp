#include <iostream>
using namespace std;

//Power of a^b by Recursion
int powerIs(int a, int b) {

    //base case
    if(b == 0) {
        return 1;
    }
    if(b == 1) {
        return a;
    }

    //Recursive call
    int ans = powerIs(a, b/2);

    //if b is even
    if(b%2 == 0) {
        return ans * ans;
    } else {
        //if b is odd
        return a * ans * ans;
    }
}

int main() {
    int a, b;
    cin>>a>>b;

    int value = powerIs(a, b);
    cout<< a <<" to the Power "<< b <<" is: "<< value <<endl;
    return 0;
}