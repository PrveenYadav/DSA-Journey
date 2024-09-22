#include <iostream>
using namespace std;

int main()
{
   // int marks[5] = {97, 100, 95, 98, 99};
    int marks[5];
    int size = 5;

     
    for (int i = 0; i < size; i++)
    {
        cin>>marks[i];
    }

    for (int i = 0; i < size; i++)
    {
        cout<<marks[i]<<endl;
    }

    return 0;
    
}