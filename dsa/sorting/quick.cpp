/* TOPIC: Quick Sort */

// TIME COMPLEXITY: O(nlogn) -> O(n^2)
// SPACE COMPLEXITY: O(log n)

// REFERENCE: https://youtu.be/sNaHN4tZmRk

#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& arr, int lo, int hi) {
    
    int pivotIndex = lo;
    for (int i=lo; i<=hi; i++) {
        if (arr[i] < arr[lo]) {
            pivotIndex++;
        }
    }
    swap(arr[lo], arr[pivotIndex]);

    int i = lo, j = hi;
    while (i < pivotIndex and j > pivotIndex) {
        if (arr[i] >= arr[pivotIndex] and arr[j] < arr[pivotIndex]) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
        else if (arr[i] < arr[pivotIndex]) {
            i++;
        }
        else if (arr[j] >= arr[pivotIndex]) {
            j--;
        }
    }

    return pivotIndex;

}

void quickSort(vector<int>& arr, int lo, int hi) {
    if (lo >= hi) {
        return;
    }
    // finding pivot index
    int pivotIndex = partition(arr, lo, hi);
    // going left
    quickSort(arr, lo, pivotIndex-1);
    // going right
    quickSort(arr, pivotIndex+1, hi);
}

int main() {

    int n;
    cin>>n;
    vector<int> arr(n);
    for (int i=0; i<n; i++) {
        cin>>arr[i];
    }

    quickSort(arr, 0, n-1);
    for (int &it: arr) {
        cout<<it<<" ";
    } cout<<endl;

    return 0;
}