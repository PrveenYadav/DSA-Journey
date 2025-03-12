#include <iostream>
using namespace std;

//Implement a program to determine whether a year is a leap year or not
int main()
{
    int year;
    cin>>year;

    if (year%4 == 0)
    {
        cout<<"Leap Year";
    }else{
        cout<<"Not a Leap Year";
    }
    
    return 0;
    
}