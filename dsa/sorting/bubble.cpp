/* TOPIC: Bubble Sort */

// TIME COMPLEXITY: O(n^2)
// SPACE COMPLEXITY: O(1)

// REFERENCE: https://youtu.be/zOhUavxlzw4

#include <bits/stdc++.h>
using namespace std;

vector<int> bubbleSort(vector<int>& arr, int n) {
    for (int i=1; i<n; i++) {
        for (int j=0; j<n-i; j++) {
            if (arr[j]>arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
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

    vector<int> sortedArr = bubbleSort(arr, n);
    for (int &it: arr) {
        cout<<it<<" ";
    } cout<<endl;

    return 0;
}