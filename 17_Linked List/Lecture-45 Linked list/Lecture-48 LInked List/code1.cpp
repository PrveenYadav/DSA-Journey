#include <iostream> 
#include <map>
using namespace std;

//Remove Duplicates from sorted List and Unsorted List

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

//Remove duplicates from sorted list : Leetcode 83(easy)
Node* removeFromSorted(Node* &head) { //we'll check if curr != curr->next then move further, if not then delete next element 
    //empty list
    if(head == NULL) {
        return NULL;
    }

    //Non-empty list
    Node* curr = head;

    while(curr != NULL) {
        
        if((curr->next != NULL) && curr->val == curr->next -> val) { //curr->next != NULL , we can use it in while loop instead of using here
            //then delete duplicates
            Node* next_next  = curr->next->next;
            Node* nodeToDelete = curr->next;
            delete(nodeToDelete);
            curr->next = next_next;

        }else {
            //not equal, then
            curr = curr->next;
        }
    }
    return head;
}

//Remove duplicates from unsorted list: 
//Solutions: 1-using two loops O(n^2), O(1), 2-first sort then use previous O(n*log n), O(1), 3-using map O(n), O(1)
Node* removeFromUnsorted(Node* &head) {  // it is not true , solve it correctly
    
    Node* curr = head;
    Node* prev = head;
    
    map<Node*, bool>visited;

    while(curr->next != NULL) {

        if(visited[curr] == true) { //then delete

            Node* next_next  = prev->next->next;
            Node* nodeToDelete = prev->next;
            delete(nodeToDelete);
            prev->next = next_next;

        }else {
            //if not visited 
            curr = curr->next;
        }
    }
    return head;

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

    removeFromUnsorted(head);
    print(head);
    return 0;
}