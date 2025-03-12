#include <iostream> 
#include <vector>
using namespace std;

//Add two numbers represented by Linked List: means sum of two linked list
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

//Que: Add two numbers represented by linked list
//step-1 reverse linked lists to do sum from left side, after reversing we can sum from right side
//step-2 sum both list
//step-3 reverse the sum list

Node* reverse(Node* head) {
    Node* curr = head;
    Node* prev = NULL;
    Node* forward = NULL;

    while(curr != NULL) {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

void insertAtTail(Node* &head, Node* &tail, int data) {
    Node* new_node = new Node(data);
    if(head == NULL) {
        head = new_node;
        tail = new_node;
        return ;
    }else {
        tail->next = new_node;
        tail = new_node;
    }
}


Node* add(Node* first, Node* second) {
    //step-1 carry = 0
    //step-2 find sum
    //step-3 find digit: digit = sum % 10
    //step-4 create node for digit
    //step-5 find carry : carry = sum/10

    int carry = 0;

    Node* ansHead = NULL;
    Node* ansTail = NULL;

    while(first != NULL && second != NULL) {

        int sum = carry + first->val + second->val;
        int digit = sum%10;

        //create node and add in answer linked list
        insertAtTail(ansHead, ansTail, digit);
        carry = sum/10;
        first = first->next;
        second = second->next;
    }


    while(first != NULL) {
        int sum = carry + first->val;
        int digit = sum % 10;
        insertAtTail(ansHead, ansTail, digit);
        carry = sum/10;
        first = first->next;
    }

    while(second != NULL) {
        int sum = carry + second->val;
        int digit = sum % 10;
        insertAtTail(ansHead, ansTail, digit);
        carry = sum/10;
        second = second->next;
    }

    while(carry != 0) {
        int sum = carry;
        int digit = sum % 10;
        insertAtTail(ansHead, ansTail, digit);
        carry = sum/10;
    }

    return ansHead;
}

Node* addTwoList(Node* first, Node* second) {

    //step-1 reverse input list
    first = reverse(first);
    second = reverse(second);

    //step-2 add two linked list
    Node* ans = add(first, second);

    //step-3 reverse the sum list
    ans = reverse(ans);

    return ans;
}


void printList(Node* head) {
    while (head != NULL) {
        cout << head->val;
        if (head->next != NULL) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    cout<<endl;

    Node* l1 = NULL;
    Node* l2 = NULL;

    // First number: 342 (represented as 2 -> 4 -> 3)
    insertAtTail(l1, l1, 3);
    insertAtTail(l1, l1, 4);
    insertAtTail(l1, l1, 2);


    // Second number: 465 (represented as 5 -> 6 -> 4)
    insertAtTail(l2, l2, 4);
    insertAtTail(l2, l2, 6);
    insertAtTail(l2, l2, 5);

    cout << "First Number: ";
    printList(l1);
    cout << "Second Number: ";
    printList(l2);

    Node* result = addTwoList(l1, l2);
    cout << "Result: ";
    printList(result);

    return 0;
}