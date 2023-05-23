/* TOPIC:  */

// REFERENCE: https://youtu.be/q8gdBn9RPeI

#include <bits/stdc++.h>
using namespace std;

class Node {

    public:
    int data;
    Node* next;
    Node* prev;

    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }

};

// insert at beginning of linked list
void insertAtHead(Node* &head, Node* &tail, int value) {
    Node* temp = new Node(value);
    if (head == NULL) {
        head = temp;
        tail = temp;
        return;
    }
    head->prev = temp;
    temp->next = head;
    head = temp;
    return;
}

// insert at end of linked list
void insertAtTail(Node* &head, Node* &tail, int value) {
    Node* temp = new Node(value);
    if (head == NULL) {
        head = temp;
        tail = temp;
        return;
    }
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
    return;
}

// insert node at a given position in linked list
void insertAtPosition(Node* &head, Node* &tail, int value, int position) {
    // insert at beginning
    if (position == 1) {
        insertAtHead(head, tail, value);
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
        insertAtTail(head, tail, value);
        return;
    }

    Node* newNode = new Node(value);
    newNode->next = temp->next;
    temp->next->prev = newNode;
    newNode->prev = temp;
    temp->next = newNode;
    return;
}

// traverse linked list
void print(Node* &head) {
    Node* temp = head;
    while(temp) {
        cout << temp->data << " ";
        temp = temp->next;
    } cout<<endl;
    return;

}

// deleting node by position
void deleteByPosition(Node* &head, Node* &tail, int position) {
    if (head == NULL) {
        cout<<"linked list is empty"<<endl;
        return;    
    }

    // delete at beginning
    if (position == 1) {
        Node* temp = head;
        head = head->next;
        if (head == NULL) {
            tail = NULL;
        } else {
            head->prev = NULL;
        }
        temp->next = NULL;
        delete temp;
        return;
    }

    Node* curr = head;
    Node* prevNode;
    int ct = 1;
    while (ct < position) {
        prevNode = curr;
        curr = curr->next;
        ct++;
    }

    prevNode->next = curr->next;
    curr->prev = NULL;
    curr->next = NULL;
    if (prevNode->next != NULL) {
        prevNode->next->prev = prevNode;
    } else {
        tail = prevNode;
    }
    delete curr;
    return;
}

// deleting node by value
void deleteByValue(Node* &head, Node* &tail, int value) {
    if (head == NULL) {
        cout<<"linked list is empty"<<endl;
        return;
    }

    // deleting beginning node
    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        if (head == NULL) {
            tail = NULL;
        } else {
            head->prev = NULL;
        }
        temp->next = NULL;
        delete temp;
        return;
    }

    Node* curr = head;
    Node* prevNode;
    while (curr) {
        if (curr->data == value) {
            prevNode->next = curr->next;
            curr->prev = NULL;
            if (curr->next != NULL) {
                prevNode->next->prev = prevNode;
            } else {
                tail = prevNode;
            }
            curr->next = NULL;
            delete curr;
            return;
        }
        prevNode = curr;
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

    deleteByPosition(head, tail, 4);
    print(head);

    deleteByValue(head, tail, 2);
    print(head);
    cout<< head->data << " " << tail->data <<endl;

    return 0;
}