#include <iostream> 
using namespace std;

//Reverse nodes in k group: Leetcode 25
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

//Reverse Linked List iteratavaly
Node* reverseInKgroup(Node* &head, int k) {

    if(head == NULL) {
        return NULL;
    }

    //step-1: Reverse first k nodes
    Node* prev = NULL;
    Node* curr = head;
    Node* nextNode = NULL;
    
    int count = 0;
    while(curr != NULL && count < k) {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
        count++;
    }
    
    //step-2: Recursion will take care of it
    if(nextNode != NULL) {
        head->next = reverseInKgroup(nextNode, k);
    }

    //step-3: Return the head of reversed list
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

    cout<<"Reverse in k grops: ";
    reverseInKgroup(head, 3);
    print(head);

    return 0;
}