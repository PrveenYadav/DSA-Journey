#include <iostream>
using namespace std;

//Object oriented programming in C++

class Hero { //class creation 

    //Properties
private:
    int health;

public:
    char level;

    //Getter 
    int getHealth() {
        return health;
    }
    
    //Setter 
    void setHealth(int h) { 
        health = h;
    }
 
    char getLevel() {
        return level;
    }

    void setLevel(int ch) { 
        level = ch;
    }
};

int main() {
    cout<<endl;

    //Statically
    Hero a;
    a.setHealth(70);
    a.setLevel('A');
    cout<<"Level is: "<< a.level <<endl;
    cout<<"Health is: "<< a.getHealth() <<endl;

    cout<<endl;

    //Dynamically
    Hero *b = new Hero;
    b->setHealth(80);
    b->setLevel('B');
    cout<<"Level is: "<< (*b).level <<endl;
    cout<<"Health is: "<< (*b).getHealth() <<endl;

    cout<<endl;

    //or print as like this
    cout<<"Health is: "<< b->getHealth() <<endl;
    cout<<"Level is: "<< b->level <<endl;
    cout<< "Size is: "<< sizeof(b) <<endl;
    return 0;
}