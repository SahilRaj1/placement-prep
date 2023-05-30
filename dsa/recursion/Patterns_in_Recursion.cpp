/* TOPIC: Patterns in Recursion on Subsequences */

// TIME COMPLEXITY: O(n^2)
// SPACE COMPLEXITY: O(n)

// REFERENCE: https://youtu.be/eQCS_v3bw0Q

#include <bits/stdc++.h>
using namespace std;

// print all subsequences
void sub(vector<int> &arr, vector<int> &temp, int i, vector<vector<int>> &subsequences, int s, int sum) {
    
    if (i == arr.size()) {
        if (s == sum) {
            subsequences.push_back(temp);
        }
        return;
    }

    // take
    temp.push_back(arr[i]);
    s += arr[i];
    sub(arr, temp, i+1, subsequences, s, sum);
    s -= arr[i];
    temp.pop_back();

    // not take
    sub(arr, temp, i+1, subsequences, s, sum);

    return;

}

// print one subsequence
bool anySub(vector<int> &arr, vector<int> &temp, int i, vector<vector<int>> &subsequences, int s, int sum) {
    
    if (i == arr.size()) {
        if (s == sum) {
            cout<<"[ ";
            for (int &it: temp) {
                cout<<it<<" ";
            } cout<<"]"<<endl;
            return true;
        }
        return false;
    }

    // take
    temp.push_back(arr[i]);
    s += arr[i];
    if (anySub(arr, temp, i+1, subsequences, s, sum) == true) {
        return true;
    }
    s -= arr[i];
    temp.pop_back();

    // not take
    if (anySub(arr, temp, i+1, subsequences, s, sum) == true) {
        return true;
    }

    return false;

}

// count number of subsequences
int countSub(vector<int> &arr, vector<int> &temp, int i, vector<vector<int>> &subsequences, int s, int sum) {
    
    if (i == arr.size()) {
        if (s == sum) {
            return 1;
        }
        return 0;
    }

    // take
    temp.push_back(arr[i]);
    s += arr[i];
    int left = countSub(arr, temp, i+1, subsequences, s, sum);
    s -= arr[i];
    temp.pop_back();

    // not take
    int right = countSub(arr, temp, i+1, subsequences, s, sum);

    return left + right;

}

int main() {

    int n, sum;
    cin>>n;
    vector<int> arr(n);
    for (int i=0; i<n; i++) {
        cin>>arr[i];
    }
    cin>>sum;

    vector<vector<int>> subsequences;
    vector<int> temp = {};

    // sub(arr, temp, 0, subsequences, 0, sum);
    // for (auto &subsequence: subsequences) {
    //     cout<<"[ ";
    //     for (int &it: subsequence) {
    //         cout<<it<<" ";
    //     } cout<<"]"<<endl;
    // }

    // anySub(arr, temp, 0, subsequences, 0, sum);

    int ans = countSub(arr, temp, 0, subsequences, 0, sum);
    cout<<ans<<endl;

    return 0;
}