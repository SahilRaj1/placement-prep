/* TOPIC: Heap Sort */

// TIME COMPLEXITY: O(nlogn)
// SPACE COMPLEXITY: O(1)

// REFERENCE: https://youtu.be/NKJnHewiGdc?t=2935

#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> &arr, int n, int i) {

    // left and right index of element
    int largest = i;
    int left = i * 2 + 1;
    int right = i * 2 + 2;

    // check whether element is in it's correct position
    if (left < n and arr[largest] < arr[left]) {
        largest = left;
    }
    if (right < n and arr[largest] < arr[right]) {
        largest = right;
    }

    // if position changes then call heapify recursively
    if (largest != i) {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }

}

void heapSort(vector<int> &arr, int n) {

    int size = n;
    while (size > 0) {
        swap(arr[0], arr[size]);
        cout<<"after swapping: ";
        for (int i=0; i<arr.size(); i++) {
            cout<<arr[i]<<" ";
        } cout<<endl;
        size--;
        heapify(arr, size, 0);
        cout<<"after heapify: ";
        for (int i=0; i<arr.size(); i++) {
            cout<<arr[i]<<" ";
        } cout<<endl<<endl;
    }

}

int main() {

    vector<int> arr = {5, 2, 3, 1};
    int n = arr.size();

    cout<<" array: ";
    for (int i=0; i<arr.size(); i++) {
        cout<<arr[i]<<" ";
    } cout<<endl<<endl;

    for (int i=n/2-1; i>=0; i--) {
        // heapify 'i'th element
        heapify(arr, n, i);
    }

    cout<<"heapify array: ";
    for (int i=0; i<arr.size(); i++) {
        cout<<arr[i]<<" ";
    } cout<<endl<<endl;

    heapSort(arr, n-1);
    cout<<"sorted array: ";
    for (int i=0; i<arr.size(); i++) {
        cout<<arr[i]<<" ";
    } cout<<endl<<endl;

    return 0;
}