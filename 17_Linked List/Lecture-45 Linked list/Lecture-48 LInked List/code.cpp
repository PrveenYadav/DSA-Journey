#include <iostream> 
#include <map>
using namespace std;

//Previous day revision: Detect a loop and floyd algo, start of loop, remove loop

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


bool detectLoop(Node* head) {
    if(head == NULL) {
        return false;
    }

    map<Node*, bool>visited;
    
    Node* temp = head;
    while(temp != NULL) {

        if(visited[temp] == true) {
            return true;
        }

        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}

Node* floydsAlgo(Node* head) {

    if(head == NULL) {
        return NULL;
    }

    Node* slow = head;
    Node* fast = head;

    while(slow != NULL || fast != NULL) {

        fast = fast->next;
        if(fast != NULL) {
            fast = fast->next;
        }
        slow = slow->next;

        if(slow == fast) {
            return slow;
        }
    }
    return NULL;
}

Node* startingNode(Node* head) {
    if(head == NULL) {
        return NULL;
    }

    Node* intersection = floydsAlgo(head);
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

Node* removeLoop(Node* &head) {
    if(head == NULL) {
        return NULL;
    }

    Node* startOfLoop = startingNode(head);
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
int main() {
    cout<<endl;

    Node* node1 = new Node(1);
    Node* head = node1;
    Node* tail = node1;

    insert(tail, 2);
    insert(tail, 3);
    insert(tail, 4);
    insert(tail, 5);
    print(head);

    tail->next = head->next;

    if(detectLoop(head)) {
        cout<<"Present";
    }else {
        cout<<"Not";
    }
    removeLoop(head);
    print(head);
    // Node* ans = startingNode(head);
    // cout<< "start node of loop is "<< ans->val <<endl;
    return 0;
}