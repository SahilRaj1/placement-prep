/* TOPIC: Selection Sort */

// TIME COMPLEXITY: O(n^2)
// SPACE COMPLEXITY: O(1)

// REFERENCE: https://youtu.be/UdO2NeHB46c?list=PLDzeHZWIZsTp4pb_WBRahP1tnipLuX9qM

#include <bits/stdc++.h>
using namespace std;

vector<int> selectionSort(vector<int>& arr, int n) {
    for (int i=0; i<n; i++) {
        int minIndex = i;
        for (int j=i+1; j<n; j++) {
            if (arr[j]<arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
    return arr;
}

int main() {

    int n;
    cin>>n;
    vector<int> arr(n);
    for (int i=0; i<n; i++) {
        cin>>arr[i];
    }

    vector<int> sortedArr = selectionSort(arr, n);
    for (int &it: arr) {
        cout<<it<<" ";
    } cout<<endl;

    return 0;
}