#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;

    //constructor
    Node (int data) {
        val = data;
        next = NULL;
    }
};

//Inserting a node at head or start
//Time complexity: O(1)
void insertAtHead(Node* &head, int val) { 

    Node* new_node = new Node(val);
    new_node ->next = head; 
    head = new_node; 
}

//Inserting a node at tail or last
//Time complexity: O(n) , when tail pointer given then O(1)
//we are traversing because we've to reach at the last pointer to insert a Node. So, For inserting at head we did'nt traverse
void insertAtTail(Node* &head, int val) {

    Node* new_node = new Node(val); //creating a new node
    Node* temp = head; //temp will start from head

    while(temp->next != NULL) {
        temp = temp->next;
    }
    //temp has reached last node
    temp->next = new_node;
}

void print(Node* head) {
    
    Node* temp = head;
    while(temp != NULL) { //we have to traverse till NULL

        cout<< temp->val <<" ";
        temp = temp->next; //For moving farward
    }
    cout<<endl;
}

int main() {
    cout<<endl;

    Node* head = new Node(8);
    cout<<head->val<<endl;

    cout<<"Inserting 2 at head"<<endl;
    insertAtHead(head, 2);
    print(head);

    cout<<"Inserting 5 at head"<<endl;
    insertAtHead(head, 5);
    print(head);

    cout<<"Inserting 9 at tail"<<endl;
    insertAtTail(head, 9);
    print(head);

    return 0;
}