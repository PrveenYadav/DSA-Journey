#include <iostream> 
using namespace std;

//check list is circular or not
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

void insertAtHead(Node* &head, int val) {

    Node* new_node = new Node(val);
    new_node->next = head;
    head = new_node;
}

//checking circular or not
bool checkCircular(Node* &head) {

    //empty list
    if(head == NULL) {
        return true;
    }

    Node* temp = head->next;
    while(temp != NULL && temp != head) {
        temp = temp->next;
    }

    if(temp == head) {
        return true;
    }
    return false;
}

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

    Node* head = NULL;

    insertAtHead(head, 5);
    print(head);
    insertAtHead(head, 4);
    print(head);
    insertAtHead(head, 3);
    print(head);
    insertAtHead(head, 2);
    print(head);
    insertAtHead(head, 1);
    print(head);

    if(checkCircular(head)) {
        cout<<"Linked List is Circular" <<endl;
    }else {
        cout<<"Not Curcular"<<endl;
    }

    return 0;
}