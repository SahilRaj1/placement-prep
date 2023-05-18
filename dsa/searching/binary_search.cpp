/* TOPIC: Binary Search */

// TIME COMPLEXITY: O(log n)
// SPACE COMPLEXITY: O(1)

// REFERENCE: https://www.youtube.com/watch?v=egRrgj8JOdY

#include <bits/stdc++.h>
using namespace std;

void binarySearch(vector<int>& arr, int target) {
    int lo = 0, hi = arr.size()-1;
    int mid;
    while (hi-lo > 1) {
        mid = lo+(hi-lo)/2; // avoids integer overflow in mid
        if (target > arr[mid]) {
            lo = mid+1;
        } else if (target < arr[mid]) {
            hi = mid-1;
        } else {
            cout<<"found"<<endl;
            return;
        }
    }
    if (arr[hi]==target or arr[lo]==target) {
        cout<<"found"<<endl;
    } else {
        cout<<"not found"<<endl;
    }
    return;
}

void recursiveBinarySearch(vector<int>& arr, int lo, int hi, int target) {
    if (hi-lo <= 1) {
        if (arr[hi]==target or arr[lo]==target) {
            cout<<"found"<<endl;
        } else {
            cout<<"not found"<<endl;
        }
        return;
    }
    int mid = lo+(hi-lo)/2;
    if (target > arr[mid]) {
        recursiveBinarySearch(arr, mid+1, hi, target);
    } else if (target < arr[mid]) {
        recursiveBinarySearch(arr, lo, mid-1, target);
    } else {
        cout<<"found"<<endl;
        return;
    }
}

int main() {

    int n, x;
    cin>>n>>x;
    vector<int> arr(n);
    for (int i=0; i<n; i++) {
        cin>>arr[i];
    }

    binarySearch(arr, x);
    recursiveBinarySearch(arr, 0, n-1, x);

    return 0;
}