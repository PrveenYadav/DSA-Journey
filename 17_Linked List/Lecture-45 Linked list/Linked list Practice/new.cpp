#include <iostream> 
using namespace std;

//Reverse Linked List: Leetcode 206
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
Node* reverseList(Node* &head) {

    if(head == NULL || head->next == NULL) {
        return head;
    }

    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;

    while(curr != NULL) {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    head = prev;
}


void reverse(Node* &head, Node* prev, Node* curr) {

    //base case
    if(curr == NULL) {
        head = prev;
        return ;
    }

    Node* forward = curr->next;
    reverse(head, curr, forward);

    curr->next = prev;

}
//Reverse Linked List Recursivaly
Node* reverseLinkedList(Node* &head) {
    Node* prev = NULL;
    Node* curr = head;
    reverse(head, prev, curr);
    return head;
}


Node* reverse1(Node* head) {

    if(head == NULL || head->next == NULL) {
        return head;
    }

    Node* small_head = reverse1(head->next);

    head->next->next = head;
    head->next = NULL;

    return small_head;
}
//Reverse Linked List : Another Approach
Node* reverseIs(Node* &head) {
    //return reverse1;
    head = reverse1(head);
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

    cout<<"Reverse Iterativaly: ";
    reverseList(head);
    print(head);

    cout<<"Reverse Recursivaly: ";
    reverseLinkedList(head);
    print(head);

    cout<<"Reverse Recursivaly Another Approach: ";
    reverseIs(head);
    print(head);

    return 0;
}