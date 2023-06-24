/* Sahil Raj */

#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> &arr, int n, int k, int mid) {

    int painters = 1, sum = 0;
    for (int i=0; i<n; i++) {
        if (sum + arr[i] <= mid) {
            sum += arr[i];
        } else {
            if (arr[i] > mid) {
                return false;
            }
            painters++;
            sum = arr[i];
        }
    }

    return k >= painters;

}

int findLargestMinDistance(vector<int> &boards, int k) {

    int n = boards.size();
    int lo=0, hi=accumulate(boards.begin(), boards.end(), 0), mid;
    while(hi-lo>1) {
        mid = lo+(hi-lo)/2;
        if (check(boards, n, k, mid)) {
            hi = mid;
        } else {
            lo = mid+1;
        }
    }
    
    if (check(boards, n, k, lo)) {
        return lo;
    }

    return hi;
    
}

int main() {

    

    return 0;
}