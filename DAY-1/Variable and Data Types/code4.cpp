#include <iostream>
using namespace std;

//Implement a program to calculate the area and circumference of a circle given the radius.
int main()
{
    int r;
    cout<<"Enter the Radius of Circle: ";
    cin>>r;

    float areaOfCircle = 3.14 * (r*r);
    float circumOfCircle = 2*3.14*r; 

    cout<<"Circumference of Circle is: "<<circumOfCircle<<endl;
    cout<<"Area of Circle is: "<<areaOfCircle<<endl;

    return 0;

}