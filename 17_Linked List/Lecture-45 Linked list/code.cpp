#include <iostream>
using namespace std;

//Reverse a Linked List: Leetcode 206
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

    if(head == 0) {
        Node* newNode = new Node(val);
        head = newNode;
        return;
    }

    Node* new_node = new Node(val);
    new_node->next = head;
    head = new_node;
}

//Reversing Linked List iteratively
Node* revereList(Node* &head) {

    if(head == NULL || head->next == NULL) {
        return head;
    }

    Node* prev = NULL;
    Node* curr_node = head;
    Node* farward = NULL;

    while(curr_node != NULL) {
        
        farward = curr_node->next;
        curr_node->next = prev; //puting prev value in curr_node->next
        prev = curr_node; //and assigning curr_node to prev
        curr_node = farward;
    }
    head = prev;
}


//Recursive Function
void reverse(Node* &head, Node* curr, Node* prev) {
    
    //base case
    if(curr == NULL) {
        head = prev;
        return ;
    }

    //Rrecursive call
    Node* forward = curr->next;
    reverse(head, forward, curr);

    curr->next = prev;
}

//Reversing Linked List Recursivaly
Node* reverseLinkedList(Node* &head) {

    Node* curr = head;
    Node* prev = NULL;
    reverse(head, curr, prev);
    return head;
}


//Another way to reverse by recursion 
Node* reverse1(Node* head) {

    //base case
    if(head == NULL || head->next == NULL) {
        return head;
    }

    Node* small_head = reverse1(head->next);
    head->next->next = head;
    head->next = NULL;

    return small_head;
}

Node* reverseLinkedList1(Node* &head) {
    // reverse1(head);
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
    //Node* head = new Node(6);

    insertAtHead(head, 5);
    print(head);
    insertAtHead(head, 6);
    print(head);
    insertAtHead(head, 7);
    print(head);
    insertAtHead(head, 8);
    print(head);

    cout<<"Reverse Iterativaly: ";
    revereList(head);
    print(head);

    cout<<"Reverse Recursivaly: ";
    reverseLinkedList(head);
    print(head);

    cout<<"Reverse Recursivaly another way: ";
    reverseLinkedList1(head);
    print(head);
    return 0;
}