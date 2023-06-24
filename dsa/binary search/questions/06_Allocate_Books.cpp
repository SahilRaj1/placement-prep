/* Sahil Raj */

#include <bits/stdc++.h>
using namespace std;

bool check(vector<int>& arr, int n, int m, int mid) {

    int students = 1, sum = 0;
    for (int i=0; i<n; i++) {
        if (sum + arr[i] <= mid) {
            sum += arr[i];
        } else {
            if (arr[i] > mid) {
                return false;
            }
            students++;
            sum = arr[i];
        }
    }

    return m >= students;

}

int findPages(vector<int>& arr, int n, int m) {

    if (m > n) {
        return -1;
    }

    int lo=0, hi=accumulate(arr.begin(), arr.end(), 0), mid;
    while (hi-lo>1) {
        // cout<<hi<<" "<<lo<<endl;
        mid = lo + (hi-lo)/2;
        if (check(arr, n, m, mid)) {
            hi = mid;
        } else {
            lo = mid+1;
        }
    }

    if (check(arr, n, m, lo)) {
        return lo;
    }

    return hi;

}

int main() {

    

    return 0;
}