#include <iostream>
using namespace std;

//Reverse a Linked List in (k groups) : Reverse nodes in k group: Leetcode 25
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

//Reverse in group of k
Node* kReverse(Node* &head, int k) {
    
    //base case
    if(head == NULL) {
        return NULL;
    
    }

    //step-1: reverse first k nodes
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;

    int count = 0;
    while(curr != NULL && count < k) {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count++;
    }

    //step-2: Recursion will take care of it , by Recursive call
    if(forward != NULL) {
        head->next = kReverse(forward, k);
    }

    //step-3: Return head of reversed list
    return prev;
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
    //Node* head = new Node(6);
    
    insertAtHead(head, 5);
    print(head);
    insertAtHead(head, 4);
    print(head);
    insertAtHead(head, 3);
    print(head);
    insertAtHead(head, 2);
    print(head);
    insertAtHead(head, 6);
    print(head);
    insertAtHead(head, 7);
    print(head);

    kReverse(head, 2);
    print(head);
    return 0;
}