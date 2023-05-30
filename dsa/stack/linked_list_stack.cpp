/* TOPIC: Stack Implementation using Linked List */

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
        int value = this->data;
        if (this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout<<"memory is free for node with value "<<value<<endl;
    }
    
};

class Stack {

    private:
        int ct;

    public:
        Node* head;
        Node* tail;
        int size;

    Stack(int size) {
        this->head = NULL;
        this->tail = NULL;
        this->size = size;
        this->ct = 0;
    }

    void push(int val) {
        if (this->ct == this->size) {
            cout<<"stack overflow"<<endl;
            return;
        }
        Node* temp = new Node(val);
        if (ct == 0) {
            this->head = temp;
            this->tail = temp;
            this->ct++;
            return;
        }
        this->tail->next = temp;
        this->tail = temp;
        this->ct++;
        return;
    }

    void pop() {
        if (this->ct == 0) {
            cout<<"stack is empty"<<endl;
            return;
        }
        if (ct == 1) {
            this->head = NULL;
            this->tail = NULL;
            this->ct = 0;
            return;
        }
        Node* temp = this->head;
        while(temp->next != this->tail) {
            temp = temp->next;
        }
        temp->next = NULL;
        this->tail = temp;
        this->ct--;
        return;
    }

    int peek() {
        if (this->ct == 0) {
            cout<<"stack is empty"<<endl;
            return -1;
        }
        return this->tail->data;
    }

    bool isEmpty() {
        return this->ct==0;
    }

};

int main() {

    Stack st(5);

    // st.push(1);
    // st.push(2);
    // st.push(3);
    // st.push(4);
    // st.push(5);
    // st.push(6);

    st.pop();

    cout << st.peek() << endl;

    cout << st.isEmpty() << endl;

    return 0;
}