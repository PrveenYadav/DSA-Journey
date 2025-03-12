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

    //destructor
    ~Node () {
        int value = this->data;
        //memory free
        if(this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout<<"Memory is free for node with data "<< value <<endl;
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

//function to print data
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

//Deletion
void deleteNode(int position, Node* &head) {
    //deleting first/start node
    if(position == 1) {
        Node* temp = head;
        head = head->next;
        //memory free start node
        temp->next = NULL;
        delete temp;
        
    }else{
        //deleting any middle node or last node
        Node* curr = head;
        Node* prev = NULL;

        int count = 1;
        while(count < position) {
            prev = curr;
            curr = curr->next;
            count++;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
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

    //Deletion
    deleteNode(4, head);
    print(head);

    return 0;
}