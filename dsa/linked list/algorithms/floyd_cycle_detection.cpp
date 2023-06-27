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

    

    return 0;
}