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

void insertAtTail(Node* &head, int val) {
    Node* new_node = new Node(val);
    if(head == NULL) {
        head = new_node;
        return ;
    }

    Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

void print(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout<< temp->val <<" -> ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}


Node* reverseList(Node* &head) {

    Node* prev = NULL;
    Node* curr = head;

    while(curr != NULL) {
        Node* next_node = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next_node;
    }
    head = prev;
}

int main() {
    cout<<endl;

    Node* l1 = NULL;
    Node* head = l1;

    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    print(head);

    reverseList(head);
    print(head);

    return 0;
}