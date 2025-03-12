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
void insertAtHead(Node* &head, int val) { 

    Node* new_node = new Node(val);
    new_node ->next = head; 
    head = new_node; 
}

//Inserting a node at tail or last
void insertAtTail(Node* &head, int val) {
    Node* new_node = new Node(val); //creating a new node
    Node* temp = head; //temp will start from head

    while(temp->next != NULL) {
        temp = temp->next;
    }
    //temp has reached last node
    temp->next = new_node;
}

//Inserting a node at given position
void insertAtPosition(Node* &head, int val, int position) {

    //if poss is 0 then we'll call insertAtHead function
    if(position == 0) {
        insertAtHead(head, val);
        return ;
    }

    Node* new_node = new Node(val);
    Node* temp = head;
    int curr_poss = 0;

    while(curr_poss != position - 1) {
        temp = temp->next;
        curr_poss++;
    }
    //Now temp is pointing to node at position-1
    new_node->next = temp->next;
    temp->next = new_node;
}

//Updating value at position k
void updateValAtPos(Node* &head, int k, int val) {

    Node* temp = head;
    int cur_pos = 1;

    while(cur_pos != k) {
        temp = temp->next;
        cur_pos++;
    }
    //now temp reached at kth position
    temp->val = val;
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

    cout<<"Inserting at given position"<<endl;
    insertAtPosition(head, 4, 2);
    print(head);

    cout<<"Updating value of kth position"<<endl;
    updateValAtPos(head, 4, 1);
    print(head);
    return 0;
}