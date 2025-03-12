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

//Insert at start or head
void insertAtHead(Node* &head, int val) {
    Node* new_node = new Node(val);
    new_node -> next = head;
    head = new_node;
}

//Insert at last or tail
void insertAtTail(Node* &head, int val) {
    Node* new_node = new Node(val);
    Node* temp = head;

    while(temp->next != NULL) {
        temp = temp->next;
    }
    //when reached at last
    temp->next = new_node;
}

//Function to print values
void print(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout<< temp->val <<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main() {
    cout<<endl;

    Node* head = new Node(2);
    cout<<  head->val <<endl;

    insertAtHead(head, 4);
    print(head);

    insertAtTail(head, 6);
    print(head);
    return 0;
}