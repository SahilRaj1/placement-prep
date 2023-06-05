/* TOPIC: Heapify Algorithm */

// TIME COMPLEXITY: O(log n)
// SPACE COMPLEXITY: O(1)

// REFERENCE: https://youtu.be/NKJnHewiGdc?t=1860

#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> &arr, int n, int i) {

    // left and right index of element
    int largest = i;
    int left = i * 2 + 1;
    int right = i * 2 + 2;

    // check whether element is in it's correct position
    if (left < arr.size() and left <= n and arr[largest] < arr[left]) {
        largest = left;
    }
    if (right < arr.size() and right <= n and arr[largest] < arr[right]) {
        largest = right;
    }

    // if position changes then call heapify recursively
    if (largest != i) {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }

}

int main() {

    int n = 5;
    vector<int> arr = {54, 53, 55, 52, 50};

    // before heapify
    for (int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    } cout<<endl;

    for (int i=n/2-1; i>=0; i--) {
        // heapify 'i'th element
        heapify(arr, n, i);
    }

    // after heapify
    for (int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    } cout<<endl;

    return 0;
}