#include <iostream>
#include <queue>
using namespace std;

//Problem: Merge Two BSTs : check and Review this code
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* insert(Node* root, int val) {
    if (root == NULL) {
        return new Node(val);
    }

    if (val < root->data) {
        root->left = insert(root->left, val);
    }
    else {
        root->right = insert(root->right, val);
    }

    return root;
}

void inorder(Node* root) {
    if (root == NULL) {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void levelOrder(Node* root) {
    if (root == NULL) {
        return;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        cout << temp->data << " ";

        if (temp->left) {
            q.push(temp->left);
        }
        if (temp->right) {
            q.push(temp->right);
        }
    }
}


//Let's see the space optimized Approach
//Problem: Merge Two BST : Time O(m+n) and space O(h1+h2)


//Convert BST into sorted Doubly Linked List
void convertIntoSortedDLL(Node* root, Node* &head) {
    //base case
    if(root == NULL) return ;

    convertIntoSortedDLL(root->right, head);

    root->right = head;
    if(head != NULL) {
        head->left = root;
    }
    head = root;

    convertIntoSortedDLL(root->left, head);

}

//Merge 2 sorted Linked List
Node* mergeLinkedList(Node* head1, Node* head2) {
    Node* head = NULL;
    Node* tail = NULL;

    while(head1 != NULL && head2 != NULL) {
        
        if(head1->data < head2->data) {

            if(head == NULL) {
                head = head1;
                tail = head1;
                head1 = head1->right;
            }else {
                tail->right = head1;
                head1->left = tail;
                tail =  head1;
                head1 = head1->right;
            }

        }else {

            if(head == NULL) {
                head = head2;
                tail = head2;
                head2 = head2->right;
            }else {
                tail->right = head2;
                head2->left = tail;
                tail =  head2;
                head2 = head2->right;
            }
        }
    }

    while(head1 != NULL) {
        tail->right = head1;
        head1->left = tail;
        tail =  head1;
        head1 = head1->right;
    }

    while(head1 != NULL) {
        tail->right = head2;
        head2->left = tail;
        tail =  head2;
        head2 = head2->right;
    }

    return head;
}

//count nodes
int countNodes(Node* head) {
    int count = 0;
    Node* temp = head;
    while(temp != NULL) {
        count++;
        temp = temp->right;
    }

    return count;
}

//Sorted Linked List to BST
Node* sortedToBST(Node* &head, int n) { //n = number of nodes in LL
    //base case
    if(n <= 0 || head == NULL) return NULL;

    Node* left = sortedToBST(head, n/2);
    Node* root = head;
    root->left = left;
    head = head->right;

    Node* right = sortedToBST(head, n - n/2 - 1); //or n - (n/2 + 1)
    return right;
}


Node* mergeTwoBST(Node* root1, Node* root2) {
    //step-1: convert BST into sorted DLL in-place
    Node* head1 = NULL;
    convertIntoSortedDLL(root1, head1);
    head1->left = NULL;

    Node* head2 = NULL;
    convertIntoSortedDLL(root2, head2);
    head2->left = NULL;

    //step-2: Merge Sorted Linked List
    Node* head = mergeLinkedList(head1, head2);

    //step-3: Convert Sorted Linked List into BST
    int n = countNodes(head);
    return sortedToBST(head, n);
}

int main() {
    cout<<endl;
    
    Node* root1 = NULL;
    Node* root2 = NULL;
    root1 = insert(root1, 50);
    root1 = insert(root1, 30);
    root1 = insert(root1, 20);
    root1 = insert(root1, 40);

    root2 = insert(root2, 3);
    root2 = insert(root2, 7);
    root2 = insert(root2, 6);
    root2 = insert(root2, 9);

    cout << "Inorder Traversal First BST: ";
    inorder(root1);
    cout<<endl<< "Inorder Traversal Second BST: ";
    inorder(root2);

    cout<<endl<< "Level Order Traversal 1st BST: ";
    levelOrder(root1);
    cout<<endl<< "Level Order Traversal 2nd BST: ";
    levelOrder(root2);
    cout<<endl;

    Node* root3 = mergeTwoBST(root1, root2);
    cout<<endl<<"Merged BST, level order: ";
    levelOrder(root3);
    cout<<endl<<"Merged BST, Inorder: ";
    inorder(root3);
    cout<<endl;
    return 0;
}