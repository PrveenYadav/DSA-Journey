#include <iostream>
using namespace std;

//Function Defination: function define, Logic write

int sumOfTwo(int a, int b)  // Parameters
{
   int sum = a + b;
   return sum;
}

int main()
{
    int x, y; // Passing the value
    cin>>x;   
    cin>>y;

    // Function call
    cout<<sumOfTwo(x, y); // Arguements
}