#include <iostream>
#include <vector>
using namespace std;

void changeA(int* ptr) // Pass by reference using pointers = change in main function
{
    *ptr = 20;
}

void changeB(int &b) // Pass by reference using Alias
{
    b = 20;
}

int main()
{
   int a = 10;

    changeA(&a);
    changeB(a);

    cout <<"inside main function: "<< a <<endl;
    cout <<"inside main function: "<< a <<endl;
}

