#include <iostream>
using namespace std;

int main() 
{
    char ch;
    cin >> ch;

    if (ch >= 65 && ch <= 90)
    {
        cout << "Upper case" << endl;
    }
    else if (ch >= 97 && ch <= 123)
    {
        cout << "Lower case" << endl;
    }
    else
    {
        cout << "Not valid character";
    }
}