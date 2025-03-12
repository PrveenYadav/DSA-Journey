#include <iostream>
#include <vector>
using namespace std;

//Functions in Vector
int main()
{
    vector<int> vec = {5, 16, 4, 3};

    cout<<"size = "<<vec.size()<<endl; //Vector size
    vec.push_back(9);    //Add value in last
    vec.pop_back();     //Remove value of last
    cout<<vec.front()<<endl;  //give first value
    cout<<vec.back()<<endl;  //give last value
    cout<<vec.at(1);  //vec[i] = vec.at(i)

    return 0;
}