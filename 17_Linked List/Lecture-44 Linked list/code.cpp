#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    
    //constructor
    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }
};

int main() {
    cout<<endl;

    Node* n1 = new Node(45);
    cout<< n1->data <<endl;
    cout<< n1->next <<endl;
}