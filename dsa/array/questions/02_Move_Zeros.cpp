/* Sahil Raj */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        if (n==1) {
            return;
        }

        int i=0, j=1;
        while (j<n) {
            if (nums[i]==0 and nums[j]!=0) {
                swap(nums[i], nums[j]);
                i++;
                j++;
            } else if (nums[i]==0 and nums[j]==0) {
                j++;
            } else {
                i++;
                j++;
            }
        }
    }
};

int main() {

    

    return 0;
}