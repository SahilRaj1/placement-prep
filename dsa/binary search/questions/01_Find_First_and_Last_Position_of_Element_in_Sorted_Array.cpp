/* Sahil Raj */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {

        int n = arr.size();
        int lo=0, hi=n-1, mid;

        while (hi-lo>1) {
            mid = lo+(hi-lo)/2;
            if (arr[mid]>arr[mid+1] and arr[mid]<arr[mid-1]) {
                hi = mid;
            } else if (arr[mid]<arr[mid+1] and arr[mid]>arr[mid-1]) {
                lo = mid;
            } else {
                return mid;
            }
        }

        if (arr[hi]>arr[lo]) {
            return hi;
        } else {
            return lo;
        }

    }
};

int main() {

    

    return 0;
}