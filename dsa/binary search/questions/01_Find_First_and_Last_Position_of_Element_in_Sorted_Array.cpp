/* Sahil Raj */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int lo=0, hi=n-1, mid;

        vector<int> ans = {-1, -1};

        if (n==1 and nums[0]==target) {
            ans[0]=0;
            ans[1]=0;
            return ans;
        }    

        while(hi-lo>=0) {
            mid = lo+(hi-lo)/2;
            if (nums[mid]==target) {
                ans[0] = mid;
                hi=mid-1;
            } else if (nums[mid]>target) {
                hi=mid-1;
            } else {
                lo=mid+1;
            }
        }

        lo=0, hi=n-1;
        while(hi-lo>=0) {
            mid = lo+(hi-lo)/2;
            if (nums[mid]==target) {
                ans[1] = mid;
                lo=mid+1;
            } else if (nums[mid]>target) {
                hi=mid-1;
            } else {
                lo=mid+1;
            }
        }
        
        return ans;
    }
};

int main() {

    

    return 0;
}