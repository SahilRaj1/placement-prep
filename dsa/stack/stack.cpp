/* TOPIC: Stack Implementation */

// REFERENCE: https://youtu.be/_6COl6V6mng

#include <bits/stdc++.h>
using namespace std;

class Stack {

    public:
        int *arr;
        int top;
        int size;

    // constructor
    Stack(int size) {
        this->size = size;
        this->arr = new int[size];
        this->top = -1;
    }

    // TIME COMPLEXITY: O(1)
    void push(int val) {
        if (this->top == this->size-1) {
            cout<<"stack overflow"<<endl;
            return;
        }
        this->top++;
        this->arr[top] = val;
        return;
    }

    // TIME COMPLEXITY: O(1)
    void pop() {
        if (this->top == -1) {
            cout<<"stack is empty"<<endl;
            return;
        }
        int temp = this->arr[this->top];
        this->top--;
        return;
    }

    // TIME COMPLEXITY: O(1)
    int peek() {
        if (this->top == -1) {
            cout<<"stack is empty"<<endl;
            return -1;
        }
        int temp = this->arr[this->top];
        return temp;
    }

    // TIME COMPLEXITY: O(1)
    bool isEmpty() {
        return this->top == -1;
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