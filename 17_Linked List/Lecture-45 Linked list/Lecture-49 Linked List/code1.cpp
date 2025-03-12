#include <iostream>
using namespace std;

//Merge 2 sorted list
class Node {
public:
    int val;
    Node* next;

    //constructor
    Node(int data) {
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

    void insertAtTail(int value) {
        Node* new_node = new Node(value);
        if(head == NULL) {
            head = new_node;
            tail = new_node;
        }else {
            tail->next = new_node;
            tail = new_node;
        }
    }

    void print() {
        Node* temp = head;
        while(temp) {
            cout<< temp->val <<" -> ";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }
};


Node* solve(Node* first, Node* second) {

    //if only one element is present in first list
    if(first->next == NULL) {
        first->next = second;
        return first;
    }

    Node* curr1 = first;
    Node* next1 = curr1->next;
    Node* curr2 = second;
    Node* next2 = curr2->next;

    while(next1 != NULL && curr2 != NULL) {

        if(curr1->val >= curr2->val && curr2->val <= next1->val) {
            
            //add nodes between the first list
            curr1->next = curr2;
            next2 = curr2->next;
            curr2->next = next1;

            //update pointers
            curr1 = curr2;
            curr2 = next2;
        }else {
            //moving forward to curr1 and next1
            curr1 = next1;
            next1 = next1->next;

            if(next1 == NULL){
                curr1->next = curr2;
                return first;
            }
        }
    }
    return first;
}

Node* sortTwoList(Node* first, Node* second) {

    if(first == NULL) {
        return second;
    }
    if(second == NULL) {
        return first;
    }

    if(first->val <= second->val) {
        return solve(first, second);
    }else {
        return solve(second, first);
    }
}

int main() {
    cout<<endl;

    LinkedList list1;
    cout<<"First List: ";
    list1.insertAtTail(0);
    list1.insertAtTail(1);
    list1.insertAtTail(5);
    list1.print();

    LinkedList list2;
    cout<<"Second List: ";

    list2.insertAtTail(2);
    list2.insertAtTail(4);

    list2.print();

    sortTwoList(list1.head, list2.head);
    cout<<"Merged List: ";
    list2.print();
    
    return 0;
}