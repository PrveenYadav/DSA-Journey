#include <iostream>
#include <unordered_set>
using namespace std;

//Time and Space Complexity both is O(n)

// Define the structure of a linked list node
struct ListNode {
    int data;
    ListNode* next;
    ListNode(int val) : data(val), next(nullptr) {}
};

// Function to remove duplicates from an unsorted linked list
void removeDuplicates(ListNode* head) {
    if (!head) return;

    unordered_set<int> seen;
    ListNode* current = head;
    ListNode* prev = nullptr;

    // Traverse the linked list
    while (current) {
        // If current node's data is already in the set, it's a duplicate
        if (seen.find(current->data) != seen.end()) {
            prev->next = current->next;  // Remove the duplicate node
            delete current;              // Free memory
        } else {
            seen.insert(current->data);  // Add data to the set
            prev = current;              // Move prev to current
        }
        current = prev->next;            // Move to the next node
    }
}

void printList(ListNode* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
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

int main() {
    ListNode* head = nullptr;
    insert(head, 10);
    insert(head, 12);
    insert(head, 11);
    insert(head, 11);
    insert(head, 12);
    insert(head, 11);
    insert(head, 10);

    cout << "Original Linked List: ";
    printList(head);

    removeDuplicates(head);

    cout << "Linked List after removing duplicates: ";
    printList(head);

    return 0;
}