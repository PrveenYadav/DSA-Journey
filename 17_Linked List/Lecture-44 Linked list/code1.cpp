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

//For inserting node at begining/head
void insertAtHead(Node* &head, int d) {
    //new node create
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}

//For inserting node at end/tail
void insertAtTail(Node* &tail, int d) {
    Node* temp = new Node(d);
    tail -> next = temp;
    tail = temp;
}

void print(Node* &head) {
    Node* temp = head;

    while(temp != NULL) {
        cout<< temp->data <<" ";
        temp = temp->next;
    }
    cout<<endl;
}

//Insert at middle or any position
void insertAtPosition(Node* &head, Node* &tail, int position, int d) {
    
    //For updating head/insert at start
    if(position == 1) {
        insertAtHead(head, d);
        return;
    }

    Node* temp = head;
    int count = 1;

    while(count < position-1) {
        temp = temp -> next;
        count++;
    }

    //updating tail/insert at last position
    if(temp -> next == NULL) {
        insertAtTail(tail, d);
        return ;
    }

    //creating a node for d
    Node* nodeToInsert = new Node(d);
    
    nodeToInsert -> next = temp-> next;
    temp -> next = nodeToInsert;
}

int main() {
    cout<<endl;

    Node* n1 = new Node(10);
    
    Node* head = n1;
    Node* tail = n1;
    print(head);

    insertAtTail(tail, 12);
    print(head);

    insertAtTail(tail, 15);
    print(head);

    //Insert at middle
    insertAtPosition(head, tail, 4, 32);
    print(head);

    cout<<"Head: "<< head-> data <<endl;
    cout<<"Tail: "<< tail-> data <<endl;

    return 0;
}