#include <iostream>
#include <unordered_map>
using namespace std;

//Clone a linked list with next and random pointer
class Node {
public:
    int val;
    Node* next;
    Node* random;

    // Constructor
    Node(int data) {
        val = data;
        next = NULL;
        random = NULL;
    }
};

void printList(Node* head) {
    while (head != NULL) {
        cout << head->val;
        if (head->next != NULL) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

void insertAtTail(Node* &head, Node* &tail, int value) {

    Node* new_node = new Node(value);
    if(head == NULL) {
        head = new_node;
        tail = new_node;
        return ;
    }else {
        tail->next = new_node;
        tail = new_node;
    }
}

//clone a linked list with next and random pointer: Time & Space both Complexity = O(n)
Node* copyList(Node* head) {
    
    //create a clone list
    Node* cloneHead = NULL;
    Node* cloneTail = NULL;

    Node* temp = head;
    while(temp != NULL) {
        insertAtTail(cloneHead, cloneTail, temp->val);
        temp = temp->next;
    }

    //step-2 create a map
    unordered_map<Node* , Node*> oldToNewNode;

    Node* originalNode = head;
    Node* cloneNode = cloneHead;

    while(originalNode != NULL && cloneNode != NULL) {
        oldToNewNode[originalNode] = cloneNode;
        originalNode = originalNode->next;
        cloneNode = cloneNode->next;
    }

    //step-3 copying/setting random poiner
    originalNode = head;
    cloneNode = cloneHead;

    while(originalNode != NULL) {
        cloneNode->random = oldToNewNode[originalNode->random];
        originalNode = originalNode->next;
        cloneNode = cloneNode->next;
    }
    return cloneHead;
}


//clone a linked list with next and random pointer: Optimized Approach O(n) and O(1)
Node* cloneLinkedList(Node* head) {

    //step-1: create a clone list
    Node* cloneHead = NULL;
    Node* cloneTail = NULL;

    Node* temp = head;
    while(temp != NULL) {
        insertAtTail(cloneHead, cloneTail, temp->val);
        temp = temp->next;
    }

    //step-2: add clone nodes in-between original list
    Node* originalNode = head;
    Node* cloneNode = cloneHead;

    while(originalNode != NULL && cloneNode != NULL) {
        Node* org_next = originalNode->next;
        originalNode->next = cloneNode;
        originalNode = org_next;

        org_next = cloneNode->next;
        cloneNode->next = originalNode;
        cloneNode = org_next;
    }

    //step-3: set/copy random pointer
    temp = head;

    while(temp != NULL) {
        if(temp->next != NULL) {
            if(temp->random != NULL) {
                temp->next->random = temp->random->next;
            }else {
                temp->next = temp->random;
            }
        }
        temp = temp->next->next;
    }

    //step-4: revert changes done in step-2
    originalNode = head;
    cloneNode = cloneHead;

    while(originalNode != NULL && cloneNode != NULL) {
        originalNode->next = cloneNode->next;
        originalNode = originalNode->next;

        if(originalNode != NULL) {
            cloneNode->next = originalNode->next;
        }
        cloneNode = cloneNode->next;
    }

    //step-5: return ans
    return cloneHead;
}

int main() {
    Node* l1 = NULL;
    Node* l2 = NULL;
    Node* head = l1;
    Node* tail = l2;

    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 3);
    insertAtTail(head, tail, 4);
    insertAtTail(head, tail, 5);
    cout<<"Original List: ";
    printList(head);

    cout<<"Cloned list: ";
    copyList(head);
    printList(head);

    return 0;
}