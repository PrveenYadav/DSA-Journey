#include <iostream>
#include <queue>
using namespace std;

//Problem: Circular tour 
class petrolPump {
public:
    int petrol;
    int distance;

    //constructor
    petrolPump() {
        petrol = 0;
        distance = 0;
    }
};

int tour(petrolPump p[], int n) {

    int deficit = 0;
    int balance = 0;
    int start = 0;

    for(int i=0; i<n; i++) {

        balance = balance + p[i].petrol - p[i].distance;

        if(balance < 0) {
            deficit += balance;
            start = i+1;
            balance = 0;
        }
    }

    if(deficit + balance >= 0) {
        return start;
    }else {
        return -1;
    }
}

int main() {

    petrolPump p;
    int petrol[] = {4, 7, 5, 4};
    int distance[] = {6, 5, 3, 5};

}