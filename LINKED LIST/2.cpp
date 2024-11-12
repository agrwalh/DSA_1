#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node *next;
    Node() {
        this->data = 0;
        this->next = NULL;
    }
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void insertathead(Node* &head, Node* &tail, int data) {
    if (head == NULL) {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

void insertattail(Node* &head, Node* &tail, int data) {
    if (head == NULL) {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    Node* newNode = new Node(data);
    tail->next = newNode;
    tail = newNode;
}

int findLength(Node* &head) {
    int len = 0;
    Node* temp = head;
    while (temp != NULL) {
        temp = temp->next;
        len++;
    }
    return len;
}

void insertatposn(int pos, Node* &head, Node* &tail, int data) {
    if (pos == 0) {
        insertathead(head, tail, data);
        return;
    }
    
    int len = findLength(head);
    if (pos >= len) {
        insertattail(head, tail, data);
        return;
    }
    
    int i = 1;
    Node* prev = head;
    while (i < pos) {
        prev = prev->next;
        i++;
    }
    Node* curr = prev->next;
    Node* newNode = new Node(data);
    newNode->next = curr;
    prev->next = newNode;
}
void deletenode(int pos, Node* &head, Node* &tail) {
    if (head == NULL) {
        cout << "Cannot delete from an empty list." << endl;
        return;
    }

    // Deleting the head node
    if (pos == 1) {
        Node* temp = head;
        head = head->next;
        if (head == NULL) {
            tail = NULL; // List is now empty
        }
        delete temp;
        return;
    }

    int len = findLength(head);
    if (pos > len) {
        cout << "Position out of range." << endl;
        return;
    }

    // Deleting the tail node
    if (pos == len) {
        Node* prev = head;
        while (prev->next != tail) {
            prev = prev->next;
        }
        prev->next = NULL;
        delete tail;
        tail = prev;
        return;
    }
    //middle node
    //step1:find[prev]
    int i=1;
    Node* prev=head;
    while(i<pos-1){
        prev=prev->next;
        i++;
    }
    Node* curr=prev->next;
    prev->next=curr->next;
    curr->next=NULL;
    delete(curr);
}
void print(Node* &head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    insertathead(head, tail, 20);
    insertathead(head, tail, 50);
    insertathead(head, tail, 30);
    insertathead(head, tail, 22);
    insertattail(head, tail, 56);

    print(head);

    // insertatposn(0, head, tail, 101); // Insert at head
    // insertatposn(3, head, tail, 75);  // Insert at position 3
    // insertatposn(10, head, tail, 88); // Insert at tail if position is out of range
    deletenode(6,head,tail);

    print(head);

    return 0;
}
