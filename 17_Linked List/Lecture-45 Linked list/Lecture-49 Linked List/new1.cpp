#include <iostream>
using namespace std;

struct ListNode {
    int data;
    ListNode* next;
    ListNode(int val) : data(val), next(nullptr) {}
};

// Function to sort a linked list of 0s, 1s, and 2s
void sortList(ListNode* head) {
    if (!head) return;

    // Counters for 0s, 1s, and 2s
    int count[3] = {0, 0, 0};

    // Traverse the linked list and count occurrences of 0, 1, and 2
    ListNode* temp = head;
    while (temp) {
        count[temp->data]++;
        temp = temp->next;
    }

    // Overwrite the list with the sorted values
    temp = head;
    for (int i = 0; i < 3; i++) {
        while (count[i]--) {
            temp->data = i;
            temp = temp->next;
        }
    }
}

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


void printList(ListNode* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    ListNode* head = nullptr;

    // Create a linked list with 0s, 1s, and 2s: 2 -> 1 -> 0 -> 2 -> 1 -> 0
    insert(head, 2);
    insert(head, 1);
    insert(head, 0);
    insert(head, 2);
    insert(head, 1);
    insert(head, 0);

    cout << "Original Linked List: ";
    printList(head);

    sortList(head);

    cout << "Sorted Linked List: ";
    printList(head);

    return 0;
}
