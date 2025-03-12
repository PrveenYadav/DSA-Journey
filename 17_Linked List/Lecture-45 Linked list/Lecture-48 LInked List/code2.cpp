//Home work: 
//Remove duplicates from unsorted list: Que-1 Solve in all ways: 1-using two loops O(n^2), O(1), 2-first sort then use previous O(n*log n), O(1), 3-using map O(n), O(1)
//Que-2 Break a circular linked list in two circular linked list

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

void insert(Node* &tail, int val) {

    Node* new_node = new Node(val);
    tail->next = new_node;
    tail = new_node;
}

void print(Node* head) {
    while(head) {
        cout<< head->val <<" -> ";
        head = head->next;
    }
    cout<<"NULL"<<endl;
}

//Function to remove duplicates from unsorted list O(n^2), O(1)
void removeDuplicates(Node* head) {
    Node* current = head;
    
    // Traverse each node in the list
    while (current != nullptr) {
        Node* runner = current;
        
        // Check all subsequent nodes for duplicates
        while (runner->next != nullptr) {
            if (runner->next->val == current->val) {
                // Remove the duplicate node
                Node* duplicate = runner->next;
                runner->next = runner->next->next;
                delete duplicate;  // Free memory
            } else {
                runner = runner->next;
            }
        }
        current = current->next;
    }
}

int main() {
    cout<<endl;

    Node* node1 = new Node(4);
    Node* head = node1;
    Node* tail = node1;

    insert(tail, 2);
    insert(tail, 5);
    insert(tail, 4);
    insert(tail, 2);
    insert(tail, 2);
    print(head);

    removeDuplicates(head);
    print(head);
    return 0;
}