#include <iostream>
using namespace std;

//Linked list: linked list not a build in data types so, we define it by yourself in the class
class Node {
public:
    //Node has two parts: 1-Value, 2-Pointer/Address of next Node
    int val;
    Node* next;

    //Constructor
    Node (int data) {
        //if i am passing any data then it will store in val and assign null to next
        val = data;
        next = NULL;
    }
};

int main() {
    cout<<endl;

    //Creating an object and making a node and passed val. it will be val = 1, and next = null
    Node* n1 = new Node(1); 

    cout<<"Val: "<< n1->val <<endl;
    cout<<"Next: "<< n1->next <<endl;
    return 0;
}