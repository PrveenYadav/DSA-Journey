#include <iostream>
using namespace std;

//Doubly Linked List: List which connected with prev node and next node
class Node {
public:
    int val;
    Node* prev;
    Node* next;

    //consturctor
    Node (int val) {
        this->val = val;
        this->prev = NULL;
        this->next = NULL;
    }

    //destructor
    ~Node () {
        int val = this->val;
        if(next != NULL) {
            delete next;
            next = NULL;
        }
        cout<< "Memory Free for Node " << val <<endl;
    }
};

//Function to print values
void print(Node* head) {
    Node* temp = head;

    while(temp != NULL) {
        cout<< temp->val <<" ";
        temp = temp->next;
    }
    cout<<endl;
}

//Functin to get length
int getLength(Node* head) {
    
    Node* temp = head;
    int length = 0;

    while(temp != NULL) {
        length++;
        temp = temp->next;
    }
    return length;
}

//Inserting at head in Doubly Linked List
void insertAtHead(Node* &head, int val) {
    
    Node* new_node = new Node(val);
    new_node -> next = head;
    head -> prev = new_node;
    head = new_node;
}

//Inserting at tail in Doubly Linked List
void insertAtTail(Node* &tail, int val) {
    
    Node* new_node = new Node(val);
    tail->next = new_node;
    new_node->prev = tail;
    tail = new_node;
}

void insertAtPosition(Node* &head ,Node* &tail, int val, int pos) {

    if(pos == 1) {
        insertAtHead(head, val);
        return ;
    }

    Node* temp = head;
    int count = 1;

    while(count != pos-1) {
        temp = temp->next;
        count++;
    }

    if(temp->next == NULL) {
        insertAtTail(tail, val);
        return;
    }

    Node* new_node = new Node(val); //new node to insert at given position
    new_node->next = temp->next;
    temp->next->prev = new_node;
    temp->next = new_node;
    new_node->prev = temp;
}

//Deletion in Doubly Linked List
void deleteNode(int position, Node* &head) {

    //deleting first/start node
    if(position == 1) {
        Node* temp = head;
        temp->next->prev = NULL;
        head = head->next;
        head = temp->next;
        temp->next = NULL;

        //free(temp); //built in function to free
        delete(temp); //destructor made for this
    }else{
        //deleting any middle node or last node
        Node* curr = head;
        Node* prev = NULL;

        int count = 1;
        while(count < position) {
            prev = curr;
            curr = curr->next;
            count++;
        }

        curr->prev = NULL;
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

int main() {
    cout<<endl;

    Node* node1 = new Node(4);
    Node* head = node1;
    Node* tail = node1;

    print(head);
    cout<<"Length: "<< getLength(head) <<endl;

    insertAtHead(head, 3);
    print(head);
    insertAtHead(head, 2);
    print(head);
    insertAtHead(head, 1);
    print(head);

    insertAtTail(tail, 5);
    print(head);

    insertAtPosition(head, tail, 6, 4);
    print(head);

    deleteNode(4, head);
    print(head);
    return 0;
}