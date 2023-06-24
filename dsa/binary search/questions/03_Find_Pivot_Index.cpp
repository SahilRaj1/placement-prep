/* Sahil Raj */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int rsum = accumulate(nums.begin(), nums.end(), 0);
        int lsum = 0;
        for (int i=0; i<n; i++) {
            rsum -= nums[i];
            if (lsum==rsum) {
                return i;
            }
            lsum += nums[i];
        }
        return -1;
    }
};

int main() {

    

    return 0;
}