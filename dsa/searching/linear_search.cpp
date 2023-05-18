/* TOPIC: Linear Search */

// TIME COMPLEXITY: O(n)
// SPACE COMPLEXITY: O(1)

// REFERENCE: https://www.geeksforgeeks.org/linear-search/

#include <bits/stdc++.h>
using namespace std;

void linearSearch(vector<int>& arr, int x) {
    for (int &it: arr) {
        if (it==x) {
            cout<<"found"<<endl;
            return;
        }
    }
    cout<<"not found"<<endl;
    return;
}

void recursiveLinearSearch(vector<int>& arr, int x, int i) {
    if (i==arr.size()) {
        cout<<"not found"<<endl;
        return;
    }
    if (arr[i]==x) {
        cout<<"found"<<endl;
        return;
    } else {
        recursiveLinearSearch(arr, x, i+1);
    }
    return;
}

int main() {

    int n, x;
    cin>>n>>x;
    vector<int> arr(n);
    for (int i=0; i<n; i++) {
        cin>>arr[i];
    }

    linearSearch(arr, x);
    recursiveLinearSearch(arr, x, 0);

    return 0;
}