#include <iostream>
using namespace std;

//printing hello
void printhello(){
    cout<<"Hello\n";
}

//sum of two numbers
int sum(int a, int b){
    int s = a + b;
    return s;
}

//min of two
int minOfTwo(int a, int b){
    if (a<b)
    {
        return a;
    }else{
        return b;
    }
    
}

int main()
{
    // printhello();
    // cout<<sum(10, 5);
    cout << minOfTwo(16, 9)<<endl;
    
    return 0;
}