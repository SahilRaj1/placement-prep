/* TOPIC: Circular Singly Linked List */

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

// insert node in linked list
void insertNode(Node* &tail, int value, int data) {
    Node* temp = new Node(data);
    if (tail == NULL) {
        tail = temp;
        temp->next = temp;
        return;
    }

    Node* curr = tail;
    while (curr->data != value) {
        curr = curr->next;
    }

    temp->next = curr->next;
    curr->next = temp;
    return;
}

// traverse through linked list
void print(Node* &tail) {
    if (tail == NULL) {
        cout<<"list is empty"<<endl;
        return;
    }
    Node* temp = tail;
    do {
        cout << temp->data << " ";
        temp = temp->next; 
    } while (temp != tail);
    cout<<endl;
    return;
}

// deleting a node in linked list
void deleteNode(Node* &tail, int value) {
    if (tail == NULL) {
        cout<<"list is empty"<<endl;
        return;
    }

    Node* prev = tail;
    Node* curr = prev->next;
    while (curr->data != value) {
        prev = curr;
        curr = curr->next;
    }

    prev->next = curr->next;
    if (curr == prev) {
        tail = NULL;
    }
    if (curr == tail) {
        tail = prev;
    }
    curr->next = NULL;
    delete curr;
    return;
}

int main() {

    Node* tail = NULL;
    // print(tail);

    insertNode(tail, 1, 1);

    insertNode(tail, 1, 2);
    print(tail);

    insertNode(tail, 2, 3);
    print(tail);

    deleteNode(tail, 1);
    print(tail);

    deleteNode(tail, 2);
    print(tail);

    deleteNode(tail, 3);
    print(tail);

    return 0;
}