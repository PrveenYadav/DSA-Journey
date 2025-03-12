#include <iostream>
using namespace std;

//flatten a linked list
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

//Flatten a linked list
Node* flattenLinkeList(Node* head) {
    //base case
    if(head == NULL && head->next == NULL) {
        return head;
    }

    Node* firstDown = head;
    firstDown->next = NULL;

    Node* right = flattenLinkeList(head->next);

    Node* result = merge(firstDown, right);
    return result;
}

int main() {
    cout<<endl;

    Node* head = NULL;

    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    print(head);

    return 0;
}