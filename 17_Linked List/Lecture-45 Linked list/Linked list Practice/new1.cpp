#include <iostream> 
using namespace std;

//Find Middle of the Linked List: Leetcode 876
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
        head = head->next;
        count++;
    }
    return count;
}

//Find Middle of the Linked List
Node* findtheMiddle(Node* head) {

    int len = getLength(head);
    int ans = len/2;

    Node* temp = head;
    int count = 0;

    while(count < ans) {
        temp = temp->next;
        count++;
    }
    //return temp;
    cout<< "Middle is: "<< temp->val <<endl;
}


//Find Middle of Linked List: Optimized Approach
Node* getMiddle(Node* &head) {

    if(head == NULL || head->next == NULL) {
        return head;
    }

    if(head->next->next == NULL) {
        return head->next;
    }

    //Taking two pointers
    Node* slow = head;
    Node* fast = head->next;

    while(fast != NULL) {
        fast = fast->next;

        if(fast != NULL) { //move forward again
            fast = fast->next;
        }
        slow = slow->next;
    }
    //return slow;
    cout<< "Middle is, Another Approach: " << slow->val <<endl;
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
    insertAtHead(head, 4);
    print(head);
    insertAtHead(head, 3);
    print(head);
    insertAtHead(head, 2);
    print(head);
    insertAtHead(head, 1);
    print(head);

    cout<< "Length is: "<< getLength(head) <<endl;

    findtheMiddle(head);
    getMiddle(head);

    return 0;
}