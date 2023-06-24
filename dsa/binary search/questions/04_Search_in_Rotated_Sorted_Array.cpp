/* Sahil Raj */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int n = nums.size();
        if (n == 1) {
            return nums[0] == target ? 0 : -1;
        }

        int lo = 0, hi = n-1, pivot;
        while (hi-lo > 1) {
            pivot = lo + (hi-lo)/2;
            if (nums[pivot] >= nums[0]) {
                lo = pivot + 1;
            } else {
                hi = pivot;
            }
        }

        if (nums[lo] == target) {
            return lo;
        } else if (nums[hi] == target) {
            return hi;
        }

        if (nums[lo] < nums[hi]) {
            pivot = lo;
        } else {
            pivot = hi;
        }

        int mid;
        if (target < nums[0]) {
            lo = pivot;
            hi = n-1;
        } else {
            lo = 0;
            hi = pivot-1;
        }
        // array is not rotated
        if (nums[n-1] > nums[0]) {
            lo = 0;
            hi = n-1;
        }
        while (hi-lo > 1) {
            mid = lo + (hi-lo)/2;
            if (nums[mid] < target) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }

        if (nums[lo] == target) {
            return lo;
        } else if (nums[hi] == target) {
            return hi;
        } else {
            return -1;
        }

    }
};

int main() {

    

    return 0;
}