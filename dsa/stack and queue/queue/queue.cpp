/* TOPIC: Queue Inplementation */

// REFERENCE: https://youtu.be/W7uB9-TKfTg

#include <bits/stdc++.h>
using namespace std;

class Queue {

    int* arr;
    int front;
    int rear;
    int size;

    public:
    Queue(int size) {
        this->size = size;
        this->front = 0;
        this->rear = 0;
        arr = new int[this->size];
    }

    void enqueue(int val) {
        if (this->rear == this->size) {
            cout<<"queue is full"<<endl;
            return;
        }
        this->arr[this->rear] = val;
        this->rear++;
        cout<<val<<" inserted in queue"<<endl;
        return;
    }

    void dequeue() {
        if (this->front == this->rear) {
            cout<<"queue is empty"<<endl;
            return;
        }
        cout<<arr[this->front]<<" removed from queue"<<endl;
        this->arr[this->front] = -1;
        this->front++;
        if (this->front == this->rear) {
            this->rear = 0;
            this->front = 0;
        }
        return;
    }

    int frontVal() {
        if (this->front == this->rear) {
            return -1;
        }
        return this->arr[this->front];
    }

    bool isEmpty() {
        return this->front == this->rear;
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