/* TOPIC: Merge Sort */

// TIME COMPLEXITY: O(nlogn)
// SPACE COMPLEXITY: O(n)

// REFERENCE: https://www.programiz.com/dsa/merge-sort

// while merging the array don't take main array pointer starting from 0. :)

#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& arr, int s, int e) {

    int mid = (s+e)/2;
    int len1 = mid - s + 1;
    int len2 = e - mid;
    vector<int> leftArray(len1), rightArray(len2);

    for (int i=0; i<len1; i++) {
        leftArray[i] = arr[s+i];
    }
    for (int j=0; j<len2; j++) {
        rightArray[j] = arr[j+mid+1];
    }

    int i = 0, j = 0, k = s;
    while (i<len1 and j<len2) {
        if (leftArray[i]<rightArray[j]) {
            arr[k] = leftArray[i];
            i++;
        } else {
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i<len1) {
        arr[k] = leftArray[i];
        i++;
        k++;
    }
    while (j<len2) {
        arr[k] = rightArray[j];
        j++;
        k++;
    }
    
}

void mergeSort(vector<int>& arr, int s, int e) {
    if (s >= e) {
        return;
    }
    int mid = (s+e)/2;
    // sort left half
    mergeSort(arr, s, mid);
    // sort right half
    mergeSort(arr, mid+1, e); 
    // do the actual sorting and merge
    merge(arr, s, e);
}

int main() {

    int n;
    cin>>n;
    vector<int> arr(n);
    for (int i=0; i<n; i++) {
        cin>>arr[i];
    }

    mergeSort(arr, 0, n-1);
    for (int &it: arr) {
        cout<<it<<" ";
    } cout<<endl;

    return 0;
}