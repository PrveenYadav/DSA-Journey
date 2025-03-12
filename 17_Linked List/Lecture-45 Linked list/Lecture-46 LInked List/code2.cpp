#include <iostream>
using namespace std;

//It is the Totally Correct output given answer for this que: Reverse nodes in k group

// Define the structure of a linked list node
struct ListNode {
    int data;
    ListNode* next;
    ListNode(int val) : data(val), next(nullptr) {}
};

// Function to reverse k nodes in the linked list
ListNode* reverseKGroup(ListNode* head, int k) {
    if (!head || k == 1) return head;

    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* prev = dummy;
    ListNode* curr = dummy;
    ListNode* next = dummy;
    
    int count = 0;
    // Count the length of the linked list
    while (curr->next) {
        curr = curr->next;
        count++;
    }
    
    // Loop to reverse every k-group
    while (count >= k) {
        curr = prev->next;
        next = curr->next;
        for (int i = 1; i < k; ++i) {
            curr->next = next->next;
            next->next = prev->next;
            prev->next = next;
            next = curr->next;
        }
        prev = curr;
        count -= k;
    }
    return dummy->next;
}

// Utility function to print a linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Utility function to insert a new node at the end of the linked list
void insert(ListNode*& head, int val) {
    ListNode* newNode = new ListNode(val);
    if (!head) {
        head = newNode;
    } else {
        ListNode* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

int main() {
    cout<<endl;

    ListNode* head = nullptr;
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    insert(head, 5);
    insert(head, 6);
    insert(head, 7);
    insert(head, 8);

    cout << "Original Linked List: ";
    printList(head);

    int k = 3;
    head = reverseKGroup(head, k);

    cout << "Linked List after reversing in groups of " << k << ": ";
    printList(head);

    return 0;
}