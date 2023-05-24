/* TOPIC: Floyd Cycle Detection in Linked List */

// TIME COMPLEXITY: O()
// SPACE COMPLEXITY: O()

// REFERENCE: https://youtu.be/VxOFflTXlXo

// detect cycle in a linked list
// finding the starting node of the cycle
// delete the cycle

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

void print(Node* &head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    } cout<<endl;
    return;
}

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

// floyd cycle detection
Node* floydCycleDetect(Node* &head) {

    if (head == NULL) {
        return NULL;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast!=NULL and fast->next!=NULL) {
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast) {
            return slow;
        }
    }

    return NULL;
}

// find starting node of the cycle
Node* startOfCycle(Node* &head) {

    Node* intersection = floydCycleDetect(head);
    if (intersection == NULL) {
        return NULL;
    }

    Node* slow = head;
    while (slow != intersection) {
        slow = slow->next;
        intersection = intersection->next;
    }

    return slow;
}

// remove cycle from linked list
void deleteCycle(Node* &head) {

    Node* start = startOfCycle(head);
    if (start == NULL) {
        return;
    }

    Node* temp = head;
    while (temp->next != start) {
        temp = temp->next;
    }

    temp->next = NULL;
    return;
}

int main() {

    Node* head = new Node(2);
    Node* tail = head;
    // print(head);

    insertAtHead(head, tail, 1);
    // print(head);

    insertAtTail(head, tail, 4);
    // print(head);

    insertAtPosition(head, tail, 3, 3);
    print(head);

    // creating a cycle
    tail->next = head->next;

    // checking if loop is present
    Node* detect = floydCycleDetect(head);
    if (detect == NULL) {
        cout<<"no cycle detected"<<endl;
    } else {
        cout<<"cycle detected at ";
        Node* start = startOfCycle(head);
        cout << start->data << endl;
    }

    // deleting the cycle
    deleteCycle(head);
    cout<<"deleting the cycle"<<endl;

    Node* detect1 = floydCycleDetect(head);
    if (detect1 == NULL) {
        cout<<"no cycle detected"<<endl;
    } else {
        cout<<"cycle detected at ";
        Node* start = startOfCycle(head);
        cout << start->data << endl;
    }

    return 0;
}