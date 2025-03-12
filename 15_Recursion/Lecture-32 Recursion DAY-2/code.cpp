#include <iostream>
using namespace std;

//Tells Reached at home or not: two variables: step and dest
void reachHome(int src, int dest) {
    
    cout<<"Source/Step "<< src <<" Destination "<< dest <<endl;

    //base case
    if(src == dest) {
        cout<<"Reached at Home"<<endl;
        return ;
    }

    //processing: for 1 step move farword
    src++;

    //Recursive call
    reachHome(src, dest);
}

int main() {
    int source;
    int dest;
    cin>>source>>dest;

    reachHome(source, dest);
    return 0;
}