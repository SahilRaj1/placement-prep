/* TOPIC: Insertion Sort */

// TIME COMPLEXITY: O(n^2)
// SPACE COMPLEXITY: O(1)

// REFERENCE: https://youtu.be/7kIVfVY6Axk

#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int>& arr, int n) {
    for (int i=1; i<n; i++) {
        int temp = arr[i], j;
        for (j=i-1; j>=0; j--) {
            if (arr[j] > temp) {
                arr[j+1] = arr[j];
            } else {
                break;
            }
        }
        arr[j+1] = temp;
    }
}

int main() {

    int n;
    cin>>n;
    vector<int> arr(n);
    for (int i=0; i<n; i++) {
        cin>>arr[i];
    }

    insertionSort(arr, n);
    for (int &it: arr) {
        cout<<it<<" ";
    } cout<<endl;

    return 0;
}