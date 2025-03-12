#include <iostream>
using namespace std;

//Middle of the Linked List: if even then middle will be right one : Leetcode 876
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


int getLength(Node* head) {
    
    int count = 0;
    while(head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

//Find Middle of Linked list
Node* findMiddle(Node* &head) {

    int len = getLength(head);
    int ans = (len/2);

    Node* temp = head;
    int count = 0;

    while(count < ans) {
        temp = temp->next;
        count++;
    }
    //return temp;
    cout<< "Middle is: "<< temp->val <<endl;
}


//Find Middle of Linked list Optimized Approach
Node* getMiddle(Node* &head) {

    if(head == NULL || head->next == NULL) {
        return head;
    }

    if(head->next->next == NULL) {
        return head->next;
    }

    //Taking 2 Pointers
    Node* slow = head;
    Node* fast = head->next;

    while(fast != NULL) {
        fast = fast->next;
        if(fast != NULL) {
            fast = fast->next;
        }
        
        slow = slow->next;
    }
    //return slow;
    cout<< "Optimized Approach, Middle is: "<< slow->val <<endl;
}

void print(Node* head) {

    Node* temp = head;
    while(temp != NULL) {
        cout<< temp->val <<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main() {
    cout<<endl;

    Node* head = NULL;

    insertAtHead(head, 5);
    print(head);
    insertAtHead(head, 6);
    print(head);
    insertAtHead(head, 7);
    print(head);
    insertAtHead(head, 8);
    print(head);

    cout<< "length is: "<< getLength(head) <<endl;
    
    findMiddle(head);
    getMiddle(head);
    return 0;
}