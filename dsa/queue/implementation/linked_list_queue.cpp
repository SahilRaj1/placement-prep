/* TOPIC: Queue Implementation using Linked List */

// REFERENCE: None

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
        if (this->next != NULL) {
            delete next;
            this->next = NULL;
        }
    }
    
};

class Queue {

    private:
        int ct;

    public:
        int size;
        Node* head;
        Node* tail;

    Queue(int size) {
        this->size = size;
        this->head = NULL;
        this->tail = NULL;
        this->ct = 0;
    }

    void enqueue(int val) {
        if (this->ct == this->size) {
            cout<<"queue is full"<<endl;
            return;
        }
        Node* temp = new Node(val);
        if (ct == 0) {
            this->head = temp;
            this->tail = temp;
            this->ct++;
            cout<<val<<" inserted in queue"<<endl;
            return;
        }
        this->tail->next = temp;
        this->tail = temp;
        this->ct++;
        cout<<val<<" inserted in queue"<<endl;
        return;
    }

    void dequeue() {
        if (this->ct == 0) {
            cout<<"queue is empty"<<endl;
            return;
        }
        if (this->ct == 1) {
            Node* temp = this->head;
            this->head == NULL;
            this->tail == NULL;
            cout<< temp->data <<" removed from queue"<<endl;
            delete temp;
            ct--;
            return;
        }
        Node* temp = this->head;
        this->head = this->head->next;
        temp->next = NULL;
        cout<< temp->data <<" removed from queue"<<endl;
        delete temp;
        ct--;
        return;
    }

    int frontVal() {
        if (this->ct == 0) {
            return -1;
        }
        return this->head->data;
    }

    bool isEmpty() {
        return ct==0;
    }

};

int main() {

    Queue q(5);

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    // q.enqueue(6);

    q.dequeue();
    q.dequeue();

    cout << q.frontVal() << endl;

    cout << q.isEmpty() << endl;

    return 0;
}