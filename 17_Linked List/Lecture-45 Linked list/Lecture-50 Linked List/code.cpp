#include <iostream> 
#include <vector>
using namespace std;

//check if the linked list is palindrome or not
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

class LinkedList {
public:
    Node* head;
    Node* tail;

    //constructor
    LinkedList () {
        head = NULL;
        tail = NULL;
    }

    //Function to insert at tail using tail pointer
    void insert(int value) {

        Node* new_node = new Node(value);
        if(head == NULL) {
            head = new_node;
            tail = new_node;
        }else {
            tail->next = new_node;
            tail = new_node;
        }
    }

    //Function to inserting elements in linked list using loop by traversing till tail 
    void insertAtTail(int value) {
        
        Node* new_node = new Node(value);
        if(head == NULL) { //list is empty
            head = new_node;
            return ; //Exit the function after assigning the head
        }

        Node* temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }

    //function to print
    void print() { //we are under this class so no need to pass parameter like head or tail
        Node* temp = head;
        while(temp != NULL) {
            cout<< temp->val <<" -> ";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }
};


//Helper function to do operation of array for checking palindrome
bool check(vector<int> arr) {
    int n = arr.size();
    int start = 0;
    int end = n-1;

    while(start <= end) {
        if(arr[start] != arr[end]) {
            return 0;
        }
        start++;
        end--;
    }
    return 1;
}

//check the list palindrome or not using array method : Time and Space both Complexity is O(n)
bool checkPalindrome(Node* head) {
    vector<int> arr;
    Node* temp = head;
    while(temp != NULL) {
        arr.push_back(temp->val);
        temp = temp->next;
    }
    return check(arr);
}


//Optimized Approach:  Time and Space Complexity is O(n) and O(1)
Node* getMiddle(Node* head) {
    Node* slow = head;
    Node* fast = head->next;

    while(fast != NULL && fast->next != NULL) {
        fast = fast->next->next; //moving two step forward to fast
        slow = slow->next;  //moving one step forward to slow
    }
    return slow;
}

Node* reverse(Node* head) {
    Node* curr = head;
    Node* prev = NULL;
    Node* forward = NULL;

    while(curr != NULL) {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

bool isPalindrome(Node* head) {
    if(head->next == NULL) { //only single element in linked list
        return true;
    }

    //step-1 find middle
    Node* middle = getMiddle(head);

    //step-2 reverse list after middle
    Node* temp = middle->next;
    middle->next = reverse(temp);

    //step-3 Compare both halfs
    Node* head1 = head;
    Node* head2 = middle->next;

    while(head2 != NULL) {

        if(head1->val != head2->val) {
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    //step-4 repeat step-2 
    temp = middle->next;
    middle->next = reverse(temp);

    return true;
}

int main() {
    cout<<endl;

    LinkedList list1;
    cout<<"Linked List: ";
    list1.insertAtTail(1);
    list1.insertAtTail(2);
    list1.insertAtTail(1);
    list1.print();

    if(isPalindrome(list1.head)) {
        cout<<"Palindrome"<<endl;
    }else {
        cout<<"Not Palindrome"<<endl;
    }
    return 0;
}