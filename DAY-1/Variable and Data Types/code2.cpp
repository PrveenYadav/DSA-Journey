#include <iostream> 
using namespace std;

//Create a program that converts a temperature from Celsius to Fahrenheit and vice versa.
int main()
{
    float n;
    cout << "Enter Celsius Value: ";
    cin>>n;

    float farh = (n * 9/5) + 32;

    cout << "Fahrenheit value of "<<n<< " degree celsius is: "<< farh;
}