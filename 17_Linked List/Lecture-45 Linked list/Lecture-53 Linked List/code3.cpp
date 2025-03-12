#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;   
    Node* bottom;

    //constructor
    Node(int val) : data(val), next(nullptr), bottom(nullptr) {}
};

// Function to merge two sorted linked lists
Node* mergeTwoLists(Node* a, Node* b) {
    if (!a) return b;
    if (!b) return a;

    Node* result = nullptr;

    if (a->data < b->data) {
        result = a;
        result->bottom = mergeTwoLists(a->bottom, b);
    } else {
        result = b;
        result->bottom = mergeTwoLists(a, b->bottom);
    }
    return result;
}

// Function to flatten the linked list
Node* flatten(Node* root) {
    if (!root || !root->next) return root;

    // Recursively flatten the next linked lists
    root->next = flatten(root->next);

    // Merge the current list with the flattened next list
    root = mergeTwoLists(root, root->next);

    return root;
}

// Utility function to print the flattened linked list
void printFlattenedList(Node* root) {
    while (root) {
        cout << root->data << " ";
        root = root->bottom;
    }
    cout << endl;
}

// Utility function to add a node at the bottom of the list
void pushBottom(Node*& head, int val) {
    Node* newNode = new Node(val);
    newNode->bottom = head;
    head = newNode;
}

int main() {
    // Create linked lists with bottom pointers
    Node* head = new Node(5);
    pushBottom(head->bottom, 7);
    pushBottom(head->bottom, 8);
    pushBottom(head->bottom, 30);

    head->next = new Node(10);
    pushBottom(head->next->bottom, 20);

    head->next->next = new Node(19);
    pushBottom(head->next->next->bottom, 22);
    pushBottom(head->next->next->bottom, 50);

    head->next->next->next = new Node(28);
    pushBottom(head->next->next->next->bottom, 35);
    pushBottom(head->next->next->next->bottom, 40);
    pushBottom(head->next->next->next->bottom, 45);

    // Flatten the linked list
    Node* flattenedList = flatten(head);

    // Print the flattened linked list
    cout << "Flattened List: ";
    printFlattenedList(flattenedList);

    return 0;
}
