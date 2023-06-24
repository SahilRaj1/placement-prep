/* TOPIC: Heap */

// REFERENCE: https://youtu.be/NKJnHewiGdc

#include <bits/stdc++.h>
using namespace std;

/* Max Heap */
class Heap {
public:

    int arr[100];
    int size;

    Heap() {
        arr[0] = -1;
        size = 0;
    }

    // print heap
    void print() {
        for (int i=1; i<=size; i++) {
            cout<<arr[i]<<" ";
        } cout<<endl;
    }

    // insert element in heap
    void push(int val) {

        // insert element at end
        size++;
        int index = size;
        arr[index] = val;

        // place element at the correct position
        while (index > 1) {
            int parent = index/2;
            if (arr[parent] < arr[index]) {
                swap(arr[parent], arr[index]);
                index = parent;
            } else {
                return;
            }
        }
        
    }

    // delete from heap
    void pop() {

        if (size == 0) {
            return;
        }

        // replace root with last element
        arr[1] = arr[size];
        size--;

        // take root node to its correct position
        int i = 1;
        while (i < size) {
            int left = 2 * i;
            int right = 2 * i + 1;

            if (left < size and arr[left] > arr[i]) {
                swap(arr[left], arr[i]);
                i = left;
            }
            else if (right < size and arr[right] > arr[i]) {
                swap(arr[right], arr[i]);
                i = right;
            }
            else {
                return;
            }
        }

    }

};

int main() {

    Heap h;

    h.push(50);
    h.push(55);
    h.push(53);
    h.push(52);
    h.push(54);
    h.print();

    h.pop();
    h.print();
    h.pop();
    h.print();


    return 0;
}