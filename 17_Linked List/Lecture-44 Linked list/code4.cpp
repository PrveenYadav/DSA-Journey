#include <iostream>
using namespace std;

//Circular Linked List: Like singly Linked list but its last/Tail Node connected to the first/Head Node
class Node{
public:
    int val;
    Node* next;

    //constructor
    Node (int data) {
        val = data;
        next = NULL;
    }

    ~Node () {
        int data = val;
        if(this->next != NULL) {
            delete next;
            next = NULL;
        }
        cout<< "Memory free for the node " << data <<endl;
    }
};

//Insertion in Circular Linked List
//we don't need head because by tail node we can access full list because it is Circular linked list
void insertNode(Node* &tail, int element, int val) { //after this element we have to insert a node

    //Empty List
    if(tail == NULL) {
        Node* new_node = new Node(val);
        tail = new_node;
        new_node->next = new_node; //making circular
    }
    else{
        //Assuming that the element is present in the list
        //Non-empty List

        Node* curr = tail; //it is the node, after this node we have to insert the new node

        while(curr->val != element) {
            curr = curr->next;
        }

        //Now the element is found and curr_node is pointing to that element
        Node* newNode = new Node(val);
        newNode->next = curr->next;
        curr->next = newNode;

    }
}

//Deletion in Circular Linked List
void deleteNode(Node* &tail, int element) { //it is the "element" which we have to delete

    //empty list
    if(tail == NULL) {
        cout<< "List is Empty" <<endl;
        return;
    }else {
        //Non-empty list
        
        Node* prev = tail;
        Node* curr = prev->next; //curr is the node to be deleted

        while(curr->val != element) {
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;
        
        //1 node Linked list
        if(curr == prev) {
            tail = NULL;
        }

        //2 or greater than 2 nodes linked list
        if(tail == curr) {
            tail = prev;
        }

        curr->next = NULL;
        //free(curr); //we can use this at the place of destructor
        delete(curr);
    }
}

//Traversing or Printing Circular list 
void print(Node* tail) {
    
    Node* temp = tail;
    do {
        cout<< tail->val <<" ";
        tail = tail->next;

    } while(tail != temp);

    cout<<endl;
}

int main() {
    cout<<endl;

    Node* tail = NULL;

    insertNode(tail, 1, 3);
    print(tail);
    insertNode(tail, 3, 6);
    print(tail);
    insertNode(tail, 6, 8);
    print(tail);
    insertNode(tail, 8, 9);
    print(tail);
    insertNode(tail,6, 7);
    print(tail);

    deleteNode(tail, 3); // 3 is the head node and it has to be deleted. Now head node should be the last node because curcular linked list
    print(tail);

    return 0;
}