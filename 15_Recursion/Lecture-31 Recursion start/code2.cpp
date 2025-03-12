#include <iostream>
using namespace std;

//Printing n to 1
int print(int n) {

    //base case
    if(n==0) return 1; //Base case : Tells, when you have to stop

    cout<< n <<endl;

    //Recursive relation
    print(n-1);
}

//Printing 1 to n
int print1(int n) {
    
    if(n==0) return 1; 

    print1(n-1);

    cout<< n <<endl;
}

int main() {
    int n;
    cin>>n;

    cout<<"printing n to 1: "<<endl;
    print(n);

    cout<<"Printing 1 to n: "<<endl;
    print1(n);
    return 0;
}