#include <iostream> 
using namespace std;

//Merge two sorted linked list
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

class LinkedList {
public:
    Node* head;
    Node* tail;

    //constructor
    LinkedList () {
        head = NULL;
        tail = NULL;
    }

    //Function to insert at tail using tail pointer
    void insert(int value) {

        Node* new_node = new Node(value);
        if(head == NULL) {
            head = new_node;
            tail = new_node;
        }else {
            tail->next = new_node;
            tail = new_node;
        }
    }

    //Function to inserting elements in linked list using loop by traversing till tail 
    void insertAtTail(int value) {
        
        Node* new_node = new Node(value);
        if(head == NULL) { //list is empty
            head = new_node;
            return ; //Exit the function after assigning the head
        }

        Node* temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }

    //function to print
    void print() { //we are under this class so no need to pass parameter like head or tail
        Node* temp = head;
        while(temp != NULL) {
            cout<< temp->val <<" -> ";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }
};


//merge two sorted linked list: Time complexity O(n+n)
Node* mergeTwoList(Node* &head1, Node* &head2) {

    Node* dummyNode = new Node(-1);  //In this node we'll insert merge list, its next node will give the head of merge list

    Node* ptr1 = head1; //To track first list
    Node* ptr2 = head2; //To track first list
    Node* ptr3 = dummyNode; //To track merged list

    while(ptr1 && ptr2) {   //Loop runs till, when ptr1 and ptr2 not to be null

        if(ptr1->val < ptr2->val) { //if ptr1 is less than ptr2 then insert ptr1 in ptr3
            ptr3->next = ptr1;
            ptr1 = ptr1->next; // moving forward to ptr1
        }else {
            ptr3->next = ptr2;
            ptr2 = ptr2->next;
        }
        ptr3 = ptr3->next;
    }

    //after ending this loop, we'll check if there is any node left/present
    if(ptr1) { //means if, ptr1 != NULL
        ptr3->next = ptr1;
    }else {
        ptr3->next = ptr2;
    }

    //Return the head of merged linked list
    return dummyNode->next;
}

int main() {
    cout<<endl;

    LinkedList list1;
    cout<<"First Linked List: ";
    list1.insertAtTail(1);
    list1.insertAtTail(4);
    list1.insertAtTail(5);
    list1.print();

    LinkedList list2;
    cout<<"Second Linked List: ";
    list2.insert(2);
    list2.insert(3);
    list2.print();

    LinkedList ll3;
    cout<<"Merged Linked List: ";
    ll3.head = mergeTwoList(list1.head, list2.head);
    ll3.print();
    
    return 0;
}