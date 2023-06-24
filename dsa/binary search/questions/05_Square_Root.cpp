/* Sahil Raj */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {

        if (x==0) {
            return 0;
        }

        int lo=1, hi=x, mid;
        while (hi-lo>1) {
            mid = lo+(hi-lo)/2;
            if (mid < x/mid) {
                lo = mid;
            } else if (mid > x/mid) {
                hi = mid;
            } else {
                return mid;
            }
        }

        if (hi == x/hi) {
            return hi;
        } else {
            return lo;
        }

    }
};

int main() {

    

    return 0;
}