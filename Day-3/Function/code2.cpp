#include <iostream>
using namespace std;

//Function Defination: function define, Logic write

void changeX(int x)  // Parameters
{
   x = 2*x;
   cout<<"value x = "<<x<<endl;
}

int main()
{
    int x = 5; // Passing the value
    changeX(x); // Function call, Arguements

    cout<<"x = "<<x; 

    return 0;
}