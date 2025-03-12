#include <iostream>
using namespace std;

//Sort 0s, 1s and 2s in Linked List : Sort Linked List of 0s 1s 2s
class Node {
public:
    int val;
    Node* next;

    //constructor
    Node(int data) {
        val = data;
        next = NULL;
    }
};

void insert(Node* &tail, int val) {

    Node* new_node = new Node(val);
    if(tail == NULL) {
        tail = new_node;
    }else {
        tail->next = new_node;
        tail = new_node;
    }
}

void print(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout<< temp->val <<" -> ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}


//usint data replacing
Node* sortList(Node* &head) {
    
    int zeroCount = 0;
    int oneCount = 0;
    int twoCount = 0;

    Node* temp = head;
    while(temp != NULL) {
        if(temp->val == 0) {
            zeroCount++;
        }
        else if(temp->val == 1) {
            oneCount++;
        }
        else if(temp->val == 2){
            twoCount++;
        }
        
        temp = temp->next;
    }

    temp = head;
    while(temp != NULL) {

        if(zeroCount != 0) {
            temp->val = 1;
            zeroCount--;
        }
        else if(oneCount != 0) {
            temp->val = 1;
            oneCount--;
        }
        else if(twoCount != 0){
            temp->val = 2;
            twoCount--;
        }
        
        temp = temp->next;
    }

    return head;
}



//Another Approach to sort list of 0s, 1s and 2s
void insertAtTail(Node* tail, Node* curr) {
    tail->next = curr;
    tail = curr;
}

//using link replacing
Node* sortList1(Node* &head) {

    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;

    Node* curr = head;
    //create separate list 0s, 1s and 2s
    while(curr != NULL) {
        
        int value = curr->val;

        if(value == 0) {
            insertAtTail(zeroTail, curr);
        }
        else if(value == 1) {
            insertAtTail(oneTail, curr);
        }
        else if(value == 2) {
            insertAtTail(twoTail, curr);
        }

        curr = curr->next;
    }

    //merse 3 sublist
    if(oneHead->next != NULL) { //1s list not empty
        zeroTail->next = oneHead->next;
    }else {
        //1s list is empty
        zeroTail->next = twoHead->next;
    }

    oneTail->next = twoHead->next;
    twoTail->next = NULL;

    //setup head
    head = zeroHead->next;

    //delete dummy nodes
    delete(zeroHead);
    delete(oneHead);
    delete(twoHead);

    return head;
}

int main() {
    cout<<endl;

    Node* node1 = new Node(1);
    Node* head = node1;
    Node* tail = node1;

    insert(tail, 0);
    insert(tail, 2);
    insert(tail, 1);
    insert(tail, 2);
    print(head);

    sortList1(head);
    print(head);
    
    return 0;
}