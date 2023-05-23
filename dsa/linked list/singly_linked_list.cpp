/* TOPIC: Singly Linked List */

// REFERENCE: https://youtu.be/q8gdBn9RPeI

#include <bits/stdc++.h>
using namespace std;

class Node {

    public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }

    ~Node() {
        int value = this->data;
        if (this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout<<"memory is free for node with value "<<value<<endl;
    }
    
};

// insert a node at the beginning of linked list
// TIME COMPLEXITY: O(1)
// SPACE COMPLEXITY: O(1)
void insertAtHead(Node* &head, Node* &tail, int data) {
    Node* temp = new Node(data);
    if (head == NULL) {
        head = temp;
        tail = temp;
        return;
    }
    temp->next = head;
    head = temp;
    return;
}

// insert a node at the end of linked list
// TIME COMPLEXITY: O(1) if tail given, else O(n)
// SPACE COMPLEXITY: O(1)
void insertAtTail(Node* &head, Node* &tail, int data) {
    Node* temp = new Node(data);
    if (head == NULL) {
        head = temp;
        tail = temp;
        return;
    }
    tail->next = temp;
    tail = temp;
    return;
}

// insert a node at a given position in the linked list
// TIME COMPLEXITY: O(n)
// SPACE COMPLEXITY: O(1)
void insertAtPosition(Node* &head, Node* &tail, int data, int position) {
    // insert at beginnning
    if (position == 1) {
        insertAtHead(head, tail, data);
        return;
    }

    Node* temp = head;
    int ct = 1;
    while(ct < position-1) {
        temp = temp->next;
        ct++;
    }

    // insert at end
    if (temp->next == NULL) {
        insertAtTail(head, tail, data);
        return;
    }

    Node* newNode = new Node(data);
    newNode->next = temp->next;
    temp->next = newNode;
    return;
}

// traversing a linked list
// TIME COMPLEXITY: O(n)
// SPACE COMPLEXITY: O(1)
void print(Node* &head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    } cout<<endl;
    return;
}

// deleting node by position
// TIME COMPLEXITY: O(1) if deleting head, else O(n)
// SPACE COMPLEXITY: O(1)
void deleteByPosition(Node* &head, Node* &tail, int position) {
    if (head == NULL) {
        cout<<"linked list is empty"<<endl;
        return;
    }

    // delete at beginning
    if (position == 1) {
        Node* temp = head;
        if (head == tail) {
            tail = NULL;
        }
        head = temp->next;
        temp->next = NULL;
        delete temp;
        return;
    }

    Node* curr = head;
    Node* prev;
    int ct=1;
    while(ct<position) {
        prev = curr;
        curr = curr->next;
        ct++;
    }

    if (curr == tail) {
        tail = prev;
    }
    prev->next = curr->next;
    curr->next = NULL;
    delete curr;
    return;
}

// deleting node by value
// TIME COMPLEXITY: O(n)
// SPACE COMPLEXITY: O(1)
void deleteByValue(Node* &head, Node* &tail, int value) {
    if (head == NULL) {
        cout<<"linked list is empty"<<endl;
        return;
    }

    // delete at beginning
    if (head->data == value) {
        Node* temp = head;
        if (head == tail) {
            tail = NULL;
        }
        head = head->next;
        temp->next = NULL;
        delete temp;
        return;
    }

    Node* curr = head;
    Node* prev;
    while(curr) {
        if (curr->data == value) {
            if (curr == tail) {
                tail = prev;
            }
            prev->next = curr->next;
            curr->next = NULL;
            delete curr;
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    
    cout<<"node with value "<<value<<" not found"<<endl;
    return;
}

int main() {

    Node* head = new Node(2);
    Node* tail = head;
    print(head);

    insertAtHead(head, tail, 1);
    print(head);

    insertAtTail(head, tail, 4);
    print(head);

    insertAtPosition(head, tail, 3, 3);
    print(head);

    deleteByPosition(head, tail, 3);
    print(head);

    deleteByValue(head, tail, 4);
    print(head);

    deleteByPosition(head, tail, 2);
    print(head);

    return 0;
}