/* TOPIC: Doubly Ended Queue */

// REFERENCE: https://youtu.be/W7uB9-TKfTg

#include <bits/stdc++.h>
using namespace std;

class Deque {

    int* arr;
    int front;
    int rear;
    int size;

    public:
    Deque(int size) {
        this->size = size;
        this->front = -1;
        this->rear = -1;
        this->arr = new int[this->size];
    }

    void push_back(int val) {
        if ((front == 0 and rear == size-1) or (front>0 and rear == (front-1)%(size-1))) {
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
    
    void push_front(int val) {
        if ((front == 0 and rear == size-1) or (front>0 and rear == (front-1)%(size-1))) {
            cout<<"queue is full"<<endl;
            return;
        }
        if (front == -1) {
            front = 0;
            rear = 0;
            arr[front] = val;
            return;
        }
        front--;
        if (front == -1) {
            front = size-1;
        }
        arr[front] = val;
        return;
    }

    void pop_front() {
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

    void pop_back() {
        if (front == -1) {
            cout<<"queue is empty"<<endl;
            return;
        }
        if (front == rear) {
            arr[rear] = -1;
            front = -1;
            rear = -1;
            return;
        }
        arr[rear] = -1;
        rear--;
        if (rear == -1) {
            rear = size-1;
        }
        return;
    }

    int frontVal() {
        if (front == -1) {
            return -1;
        }
        return this->arr[this->front];
    }

    int rearVal() {
        if (front == -1) {
            return -1;
        }
        return this->arr[this->rear];
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

    Deque q(4);

    q.push_front(2);
    q.push_front(1);
    q.push_back(3);
    q.push_back(4);
    // 1 2 3 4
    q.print();

    q.pop_front();
    // 2 3 4
    q.print();

    q.pop_back();
    // 2 3
    q.print();

    return 0;
}