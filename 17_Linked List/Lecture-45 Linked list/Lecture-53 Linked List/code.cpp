#include <iostream>
using namespace std;

//merge sort linked list, using links, without data/val replacement
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

void insertAtTail(Node* &head, int val) {
    Node* new_node = new Node(val);
    if(head == NULL) {
        head = new_node;
        return ;
    }

    Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

void print(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout<< temp->val <<" -> ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}


//finding mid
Node* findMid(Node* head) {
    Node* slow = head;
    Node* fast = head->next;

    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

//merge 2 sorted linked list
Node* merge(Node* left, Node* right) {

    if(left == NULL) {
        return right;
    }
    if(right == NULL) {
        return left;
    }

    Node* ans = new Node(-1);
    Node* temp = ans;

    while(left != NULL && right != NULL) {
        if(left->val < right->val) {
            temp->next = left;
            temp = left;
            left = left->next;
        }else {
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }

    while(left != NULL) {
        temp->next = left;
        temp = left;
        left = left->next;
    }

    while(right != NULL) {
        temp->next = right;
        temp = right;
        right = right->next;
    }

    ans = ans->next;
    return ans;
}

//Merge sort in Linked List
Node* mergeSort(Node* &head) {
    //base case
    if(head == NULL && head->next == NULL) {
        return head;
    }

    //finding mid and breaking in two parts
    Node* mid = findMid(head);

    Node* left = head;
    Node* right = mid->next;
    mid->next = NULL;

    //sorting both part by recursive calls
    left = mergeSort(left);
    right = mergeSort(right);

    //merge both right and left parts
    Node* result = merge(left, right);

    return result;
}

int main() {
    cout<<endl;

    Node* l1 = NULL;
    Node* head = l1;

    insertAtTail(head, 3);
    insertAtTail(head, 7);
    insertAtTail(head, 2);
    insertAtTail(head, 5);
    insertAtTail(head, 1);
    print(head);

    mergeSort(head);
    print(head);
    return 0;
}