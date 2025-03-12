#include <iostream>
#include <map>
using namespace std;

//Detect and Remove a loop in a linked list: Leetcode
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

//Linked List Cycle: Leetcode 141
bool detectLoop(Node* &head) {

    if(head == NULL) {
        return false;
    }

    map<Node* , bool>visited;

    Node* temp = head;
    while(temp != NULL) {

        //cycle is present
        if(visited[temp] == true) {
            cout<<"Present on element "<< temp->val <<" "<<endl;
            return true;
        }

        visited[temp] = true;
        temp = temp->next;
    }
    return false;
} 


//Detect loop by floyd's Algorithm
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
    print(head);
    insertAtTail(tail, 3);
    print(head);
    insertAtTail(tail, 2);
    print(head);
    insertAtTail(tail, 1);
    print(head);

    tail->next = head->next;

    // if(detectLoop(head)) {
    //     cout<<"Cycle is present"<<endl;
    // }else{
    //     cout<<"Not present"<<endl;
    // }

    if(foydDetectLoop(head) != NULL) {
        cout<<"Cycle is present"<<endl;
    }else{
        cout<<"Not present"<<endl;
    }

    return 0;
}