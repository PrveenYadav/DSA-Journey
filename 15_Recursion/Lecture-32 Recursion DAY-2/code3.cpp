#include <iostream>
#include <string>
using namespace std;

//Say Degits
void sayDigits(int n, string arr[]) {

    //base case
    if(n == 0)
        return ;
    
    //Processing
    int digit = n % 10;
    n = n / 10;

    //Recursive call
    sayDigits(n, arr);

    cout<< arr[digit] << " ";

}

int main() {

    string arr[10] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    int n;
    cin>>n;

    sayDigits(n, arr);

}