/* TOPIC: Recursion on Subsequences */

// TIME COMPLEXITY: O(n^2)
// SPACE COMPLEXITY: O(n)

// REFERENCE: https://youtu.be/AxNNVECce8c

#include <bits/stdc++.h>
using namespace std;

void sub(vector<int> &arr, vector<int> &temp, int i, vector<vector<int>> &subsequences) {
    
    if (i == arr.size()) {
        subsequences.push_back(temp);
        return;
    }

    // not take
    sub(arr, temp, i+1, subsequences);

    // take
    temp.push_back(arr[i]);
    sub(arr, temp, i+1, subsequences);
    temp.pop_back();

    return;

}

int main() {

    int n;
    cin>>n;
    vector<int> arr(n);
    for (int i=0; i<n; i++) {
        cin>>arr[i];
    }

    vector<vector<int>> subsequences;
    vector<int> temp = {};
    sub(arr, temp, 0, subsequences);

    for (auto &subsequence: subsequences) {
        cout<<"[ ";
        for (int &it: subsequence) {
            cout<<it<<" ";
        } cout<<"]"<<endl;
    }

    return 0;
}