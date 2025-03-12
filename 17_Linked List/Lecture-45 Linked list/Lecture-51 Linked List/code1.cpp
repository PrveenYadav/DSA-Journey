#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;

    // Constructor
    Node(int data) {
        val = data;
        next = NULL;
    }
};

void insertAtTail(Node*& head, int value) {
    Node* new_node = new Node(value);

    if (head == NULL) {
        head = new_node;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

void printList(Node* head) {
    while (head != NULL) {
        cout << head->val;
        if (head->next != NULL) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}


//Function to reverse a linked list
Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* curr = head;

    while (curr != NULL) {
        Node* next_node = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next_node;
    }

    return prev;
}

//Add two numbers represented by linked lists
Node* addTwoNumbers(Node* l1, Node* l2) {

    // Reverse both lists to simplify addition
    l1 = reverseList(l1);
    l2 = reverseList(l2);

    Node* dummyHead = new Node(0);
    Node* current = dummyHead;
    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry != 0) {
        int sum = carry;
        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }

        carry = sum / 10;
        current->next = new Node(sum % 10);
        current = current->next;
    }

    // Reverse the result list to restore the original order
    return reverseList(dummyHead->next);
}


int main() {
    Node* l1 = NULL;
    Node* l2 = NULL;

    insertAtTail(l1, 3);
    insertAtTail(l1, 4);
    insertAtTail(l1, 2);

    insertAtTail(l2, 4);
    insertAtTail(l2, 6);
    insertAtTail(l2, 5);

    cout << "First Number: ";
    printList(l1);
    cout << "Second Number: ";
    printList(l2);

    Node* result = addTwoNumbers(l1, l2);
    cout << "Result: ";
    printList(result);

    return 0;
}