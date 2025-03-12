#include <iostream>
using namespace std;

//  Write a program that accepts a user's age and checks if they are eligible to vote (age ≥ 18)
int main()
{
    int age;
    cin>>age;

    if (age >= 18)
    {
        cout<<"You are Eligible to Vote";
    }else{
        cout<<"You are not Eligible to Vote";
    }
    
    return 0;
    
}