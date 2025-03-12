#include <iostream>
#include <map>
using namespace std;

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

void insertAtTail(Node* &tail, int val) {
    Node* new_node = new Node(val);
    tail->next = new_node;
    tail = new_node;
}

//Detect Loop by floyd's algorithm
Node* foydDetectLoop(Node* &head) {
    if(head == NULL) {
        return NULL;
    }

    Node* slow = head;
    Node* fast = head;

    while(slow != NULL || fast != NULL) {

        fast = fast->next;
        if(fast != NULL) {
            fast = fast->next; //moving forward again to fast
        }
        slow =  slow->next;

        if(slow == fast) {
            cout<<"Present at "<< slow->val <<endl;
            return slow;
        }
    }
    return NULL;
}

//starting or bigining node of the loop
Node* getStartingNode(Node* head) {
    if(head == NULL) {
        return NULL;
    }

    Node* intersection  = foydDetectLoop(head);
    if(intersection == NULL) {
        return NULL;
    }
    Node* slow = head;

    while(slow != NULL) {
        slow = slow->next;
        intersection = intersection->next;
    }
    return slow;
}


//Remove the loop from linked list
Node* removeLoop(Node* head) {
    if(head == NULL) {
        return NULL;
    }

    Node* startOfLoop = getStartingNode(head);
    if(startOfLoop == NULL) {
        return head;
    } 
    
    Node* temp = startOfLoop;

    while(temp->next != startOfLoop) {
        temp = temp->next;
    }
    temp->next = NULL;
    return head;
}


void print(Node* head) {
    while(head != NULL) {
        cout<< head->val <<" ";
        head = head->next;
    }
    cout<<endl;
}

int main() {
    cout<<endl;

    Node* node1 = new Node(5);

    Node* head = node1;
    Node* tail = node1;

    insertAtTail(tail, 4);
    insertAtTail(tail, 3);
    insertAtTail(tail, 2);
    insertAtTail(tail, 1);
    print(head);

    tail->next = head->next;

    Node* ans = getStartingNode(head);
    cout<<"Loop starts at "<< ans->val <<endl;

    removeLoop(head);
    print(head);
    return 0;
}