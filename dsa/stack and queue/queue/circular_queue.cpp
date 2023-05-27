/* TOPIC: Circular Queue */

// REFERENCE: https://youtu.be/W7uB9-TKfTg

#include <bits/stdc++.h>
using namespace std;

class CircularQueue {

    int* arr;
    int front;
    int rear;
    int size;

    public:
    CircularQueue(int size) {
        this->size = size;
        this->front = -1;
        this->rear = -1;
        this->arr = new int[this->size];
    }

    void enqueue(int val) {
        if ((front == 0 and rear == size-1) or (rear == (front-1)%(size-1))) {
            cout<<"queue is full"<<endl;
            return;
        }
        if (front == -1) {
            front = 0;
            rear = 0;
            arr[rear] = val;
            return;
        }
        rear = (rear+1)%size;
        arr[rear] = val;
        return;
    }

    void dequeue() {
        if (front == -1) {
            cout<<"queue is empty"<<endl;
            return;
        }
        if (front == rear) {
            arr[front] = -1;
            front = -1;
            rear = -1;
            return;
        }
        arr[front] = -1;
        front = (front+1)%size;
        return;
    }

    int frontVal() {
        if (front == -1) {
            return -1;
        }
        return this->arr[this->front];
    }

    bool isEmpty() {
        return front == -1;
    }

    void print() {
        for (int i=0; i<size; i++) {
            cout<<arr[i]<<" ";
        } cout<<endl;
    }

};

int main() {

    CircularQueue q(5);

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.print();
    q.dequeue();
    q.print();

    q.enqueue(6);
    q.print();
    q.dequeue();
    q.print();

    cout << q.frontVal() << endl;

    cout << q.isEmpty() << endl;

    return 0;
}