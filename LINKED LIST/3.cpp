#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;
    Node() {
        this->data = 0;
        this->prev = NULL;
        this->next = NULL;
    }
    Node(int data) {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

void print(Node* &head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int getLength(Node* head) {
    int len = 0;
    Node* temp = head;
    while (temp != NULL) {
        temp = temp->next;
        len++;
    }
    return len;
}

void insertathead(Node* &head, Node* &tail, int data) {
    Node* newNode = new Node(data);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void insertattail(Node* &head, Node* &tail, int data) {
    Node* newNode = new Node(data);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void insertatpos(int pos, Node* &head, Node* &tail, int data) {
    if (head == NULL || pos == 1) {
        insertathead(head, tail, data);
        return;
    }

    int len = getLength(head);
    if (pos > len) {
        insertattail(head, tail, data);
        return;
    }

    int i = 1;
    Node* prevNode = head;
    while (i < pos - 1) {
        prevNode = prevNode->next;
        i++;
    }
    Node* curr = prevNode->next;
    Node* newNode = new Node(data);

    prevNode->next = newNode;
    newNode->prev = prevNode;
    newNode->next = curr;
    curr->prev = newNode;
}

void deletefrompos(Node* &head, Node* &tail, int pos) {
    if (head == NULL) {
        cout << "LinkedList is empty" << endl;
        return;
    }
    
    int len = getLength(head);
    if (pos > len) {
        cout << "Please enter a valid position" << endl;
        return;
    }

    if (pos == 1) {
        Node* temp = head;
        head = head->next;
        if (head != NULL) head->prev = NULL;
        temp->next = NULL;
        delete temp;
        if (head == NULL) tail = NULL; // If list becomes empty
        return;
    }

    if (pos == len) {
        Node* temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        temp->prev = NULL;
        delete temp;
        return;
    }

    int i = 1;
    Node* left = head;
    while (i < pos - 1) {
        left = left->next;
        i++;
    }
    Node* curr = left->next;
    Node* right = curr->next;

    left->next = right;
    right->prev = left;
    curr->next = NULL;
    curr->prev = NULL;
    delete curr;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    insertathead(head, tail, 20);
    insertathead(head, tail, 50);
    insertathead(head, tail, 30);
    insertathead(head, tail, 22);
    insertattail(head, tail, 56);

    cout << "Initial List: ";
    print(head);

    insertatpos(1, head, tail, 102); // Insert at head
    cout << "After inserting 102 at head: ";
    print(head);

    insertatpos(3, head, tail, 75); // Insert at position 3
    cout << "After inserting 75 at position 3: ";
    print(head);

    insertatpos(10, head, tail, 88); // Insert at tail if position is out of range
    cout << "After inserting 88 at tail: ";
    print(head);

    deletefrompos(head, tail, 1); // Delete from head
    cout << "After deleting node at position 1: ";
    print(head);

    deletefrompos(head, tail, 4); // Delete from middle
    cout << "After deleting node at position 4: ";
    print(head);

    deletefrompos(head, tail, getLength(head)); // Delete from tail
    cout << "After deleting node from tail: ";
    print(head);

    return 0;
}
