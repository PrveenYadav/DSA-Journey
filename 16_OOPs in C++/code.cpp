#include <iostream>
using namespace std;

//Object oriented programming in C++

class Hero { //class creation 
    
//Properties
private:
    int score;

public:
    int health;
    char level;

    void print() {
        cout<< level << endl;
    }

    //To access private properties outside from class, we use Getter & Setter

    //Getter for get the property 
    int getScore() {
        return score;
    }
    
    //Setter for set the value
    void setScore(int s) { //we can also use conditions in Setter 
        score = s;
    }
};

int main() {
    cout<<endl;

    //creatation of object
    Hero ramesh;

    //Accessing the properties from class and assigning values to them
    ramesh.health = 70;
    ramesh.level = 'A';


    //Assigning value using Setter
    ramesh.setScore(97);
    //getting private properties using Getter and printing value
    cout<<"Ramesh score is: "<< ramesh.getScore() <<endl;


    //Printing the value
    cout<<"Health is: "<< ramesh.health <<endl;
    cout<<"Level is: "<< ramesh.level <<endl;
    cout<< "Size is: "<< sizeof(ramesh) <<endl;
    return 0;
}