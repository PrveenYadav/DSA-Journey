#include <iostream>
using namespace std;

//Merge 2 sorted linked list: Iterative and recursive approach
struct ListNode {
    int data;
    ListNode* next;
    ListNode(int val) : data(val), next(nullptr) {}
};

// Function to merge two sorted linked lists(Iterative Approach)
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {  

    ListNode dummy(0); // Temporary dummy node
    ListNode* tail = &dummy;

    // Traverse both lists and merge
    while (list1 && list2) {
        if (list1->data < list2->data) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }

    // Attach the remaining nodes (if any)
    if (list1) tail->next = list1;
    if (list2) tail->next = list2;

    return dummy.next;
}

// Function to merge two sorted linked lists (Recursive version)
ListNode* mergeTwoListsRecursive(ListNode* l1, ListNode* l2) {

    if (!l1) return l2;
    if (!l2) return l1;

    if (l1->data < l2->data) {
        l1->next = mergeTwoListsRecursive(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeTwoListsRecursive(l1, l2->next);
        return l2;
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
    ListNode* l1 = nullptr;
    ListNode* l2 = nullptr;

    // Create the first sorted linked list: 1 -> 3 -> 5
    insert(l1, 1);
    insert(l1, 3);
    insert(l1, 5);

    // Create the second sorted linked list: 2 -> 4 -> 6
    insert(l2, 2);
    insert(l2, 4);
    insert(l2, 6);

    cout << "First Linked List: ";
    printList(l1);

    cout << "Second Linked List: ";
    printList(l2);

    ListNode* mergedList = mergeTwoLists(l1, l2);
    cout << "Merged Sorted Linked List: ";
    printList(mergedList);

    // ListNode* mergedList = mergeTwoListsRecursive(l1, l2);
    // cout << "Merged Sorted Linked List Recursivaly: ";
    // printList(mergedList);

    return 0;
}
