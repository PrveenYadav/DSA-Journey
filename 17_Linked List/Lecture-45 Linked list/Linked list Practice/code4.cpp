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

//Insert at head
void insertAtHead(Node* &head, int val) {

    Node* new_node = new Node(val);
    new_node -> next = head;
    head = new_node;
}

//Inserting at tail
void insertAtTail(Node* &head, int val) {
    
    Node* new_node = new Node(val);
    Node* temp = head;

    while(temp->next != NULL) {
        temp = temp->next;
    }
    //when reached at last
    temp->next = new_node;
}

//Inserting at given position
void insertAtPosition(Node* &head, int val, int pos) {

    if(pos == 0) {
        insertAtHead(head, val);
        return ;
    }

    Node* new_node = new Node(val);
    Node* temp = head;
    int cur_pos = 0;

    while(cur_pos != pos-1) {
        temp = temp->next;
        cur_pos++;
    }
    //now temp has reached at pos-1
    new_node->next = temp->next;
    temp->next = new_node;
}
 
//Update value of kth positon
void updateAtPosition(Node* &head, int k, int val) {

    Node* temp = head;
    int cur_pos = 1;

    while(cur_pos != k) {
        temp = temp->next;
        cur_pos++;
    }
    //when temp reached at position k
    temp->val = val;
}

//For printing values
void print(Node* head) {                                 
    
    Node* temp = head;
    while(temp != NULL) {  

        cout<<temp->val<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main() {
    cout<<endl;

    Node* head = new Node(2);
    cout<<"Before Inserting: "<< head->val <<endl;

    cout<<"After Inserting 3 at head"<<endl;
    insertAtHead(head, 3);
    print(head);

    cout<<"Inserting a node at tail"<<endl;
    insertAtTail(head, 4);
    print(head);

    cout<<"Inserting a node at given Position"<<endl;
    insertAtPosition(head, 9, 2);
    print(head);

    cout<<"Updating value at kth Position"<<endl;
    updateAtPosition(head, 2, 7);
    print(head);
    return 0;
}