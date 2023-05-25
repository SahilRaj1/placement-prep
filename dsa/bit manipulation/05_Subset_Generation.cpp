/* TOPIC: Subset Generation Using Bits (Power Set) */

// TIME COMPLEXITY: O(n*2^n)
// SPACE COMPLEXITY: O(2^n)

// REFERENCE: https://www.youtube.com/watch?v=b7AYbpM5YrE

#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin>>n;
    vector<int> arr(n);
    for (int i=0; i<n; i++) {
        cin>>arr[i];
    }

    vector<vector<int>> powSet;
    for (int num=0; num<(1<<n); num++) {
        vector<int> subset;
        for (int i=0; i<n; i++) {
            if (num & (1<<i)) {
                subset.push_back(arr[i]);
            }
        }
        powSet.push_back(subset);
    }

    for (auto &subset: powSet) {
        cout<<"[ ";
        for (int &it: subset) {
            cout<<it<<" ";
        } cout<<"]"<<endl;
    }
    
    return 0;
}