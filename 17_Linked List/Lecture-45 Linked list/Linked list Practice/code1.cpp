#include <iostream>
using namespace std;

//Singly linked list : A node links with only his Further node
//Doobly Linked lis : A node links with by its previous node & Next node
//Circular Linked lis : Like Singly linked list But its last/Tail Node links with Head node

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

//Insert at head or start
void insertAtHead(Node* &head, int val) { //we pass head because by this it can acess the full list

    //We'll make a node: This is the new node which we'll Insert/add at the start
    Node* new_node = new Node(val);
    new_node ->next = head; //for adding at the start/head, So, new_node 's next will be the head
    head = new_node; //Now head will be the new_node So, we will update head node to new_node
}

//Printing the values of Linked list: we will traverse linked list to print
void print(Node* head) {
    
    //we'll make a temp pointer for traverse and it will start from head
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

    return 0;
}