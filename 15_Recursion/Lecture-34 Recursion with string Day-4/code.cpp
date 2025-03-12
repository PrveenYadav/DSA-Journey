#include <iostream>
#include <string>
using namespace std;

//Reversing the string
void reverse(string &str, int i, int j) {
    
    //checking how recursion works
    cout<<"Recursive Call for "<< str <<endl;

    //base case
    if(i > j) {
        return ;
    }

    swap(str[i], str[j]);
    i++;
    j--;

    //Recursive call
    reverse(str, i, j);
}

int main() {
    cout<<endl;
    string name = "Hello World";
    int n = name.length();

    reverse(name, 0, n-1);
    cout<<endl;
    cout<<"Reversed name is: "<<name<<endl;
    return 0;
}