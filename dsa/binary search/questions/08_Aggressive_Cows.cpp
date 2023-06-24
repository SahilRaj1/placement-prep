/* Sahil Raj */

#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> &arr, int n, int k, int mid) {

    int cows = 1, last = arr[0];
    for (int i=1; i<n; i++) {
        if (arr[i] - last >= mid) {
            cows++;
            last = arr[i];
            if (cows == k) {
                return true;
            } 
        }
    }
    
    return false;

}

int aggressiveCows(vector<int> &stalls, int k) {

    int n = stalls.size();

    if (k > n) {
        return -1;
    }

    sort(stalls.begin(), stalls.end());

    int lo=0, hi=*max_element(stalls.begin(), stalls.end()), mid;
    while (hi-lo>1) {
        mid = lo + (hi-lo)/2;
        if (check(stalls, n, k, mid)) {
            lo = mid;
        } else {
            hi = mid-1;
        }
    }

    if (check(stalls, n, k, hi)) {
        return hi;
    }

    return lo;

}

int main() {

    

    return 0;
}