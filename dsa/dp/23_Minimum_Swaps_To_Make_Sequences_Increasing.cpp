/* TOPIC: Minimum Swaps To Make Sequences Increasing */

// TIME COMPLEXITY: O()
// SPACE COMPLEXITY: O()

// REFERENCE: https://youtu.be/IeT9Qz_vqHo
// QUESTION: https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/

#include <bits/stdc++.h>
using namespace std;

/* Recursion + Memoization */
class Solution {
public:

    int solve(vector<int>& nums1, vector<int>& nums2, int i, bool swapped, vector<vector<int>> &dp) {

        if (i == nums1.size()) {
            return 0;
        }

        if (dp[i][swapped] != -1) {
            return dp[i][swapped];
        }

        int prev1 = nums1[i-1];
        int prev2 = nums2[i-1];
        int ans = INT_MAX;

        if (swapped) {
            swap(prev1, prev2);
        }

        // no swap
        if (nums1[i] > prev1 and nums2[i] > prev2) {
            ans = solve(nums1, nums2, i+1, 0, dp);
        }

        // swap
        if (nums1[i] > prev2 and nums2[i] > prev1) {
            ans = min(ans, 1 + solve(nums1, nums2, i+1, 1, dp));
        }

        return dp[i][swapped] = ans;

    }

    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);
        vector<vector<int>> dp(n+1, vector<int>(2, -1));
        return solve(nums1, nums2, 1, false, dp);
    }
};

/* Tabulation */
class Solution {
public:

    int solve(vector<int>& nums1, vector<int>& nums2, int i, bool swapped, vector<vector<int>> &dp) {

        if (i == nums1.size()) {
            return 0;
        }

        if (dp[i][swapped] != -1) {
            return dp[i][swapped];
        }

        int prev1 = nums1[i-1];
        int prev2 = nums2[i-1];
        int ans = INT_MAX;

        if (swapped) {
            swap(prev1, prev2);
        }

        // no swap
        if (nums1[i] > prev1 and nums2[i] > prev2) {
            ans = solve(nums1, nums2, i+1, 0, dp);
        }

        // swap
        if (nums1[i] > prev2 and nums2[i] > prev1) {
            ans = min(ans, 1 + solve(nums1, nums2, i+1, 1, dp));
        }

        return dp[i][swapped] = ans;

    }

    int minSwap(vector<int>& nums1, vector<int>& nums2) {

        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);
        int n = nums1.size();

        vector<vector<int>> dp(n+1, vector<int>(2, 0));

        for (int i=n-1; i>0; i--) {
            for (int swapped=1; swapped>=0; swapped--) {

                int prev1 = nums1[i-1];
                int prev2 = nums2[i-1];
                int ans = INT_MAX;

                if (swapped) {
                    swap(prev1, prev2);
                }

                // no swap
                if (nums1[i] > prev1 and nums2[i] > prev2) {
                    ans = dp[i+1][0];
                }

                // swap
                if (nums1[i] > prev2 and nums2[i] > prev1) {
                    ans = min(ans, 1 + dp[i+1][1]);
                }

                dp[i][swapped] = ans;

            }
        }

        return dp[1][0];

    }
};

/* Space Optimization */
class Solution {
public:

    int solve(vector<int>& nums1, vector<int>& nums2, int i, bool swapped, vector<vector<int>> &dp) {

        if (i == nums1.size()) {
            return 0;
        }

        if (dp[i][swapped] != -1) {
            return dp[i][swapped];
        }

        int prev1 = nums1[i-1];
        int prev2 = nums2[i-1];
        int ans = INT_MAX;

        if (swapped) {
            swap(prev1, prev2);
        }

        // no swap
        if (nums1[i] > prev1 and nums2[i] > prev2) {
            ans = solve(nums1, nums2, i+1, 0, dp);
        }

        // swap
        if (nums1[i] > prev2 and nums2[i] > prev1) {
            ans = min(ans, 1 + solve(nums1, nums2, i+1, 1, dp));
        }

        return dp[i][swapped] = ans;

    }

    int minSwap(vector<int>& nums1, vector<int>& nums2) {

        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);
        int n = nums1.size();

        int swap = 0;
        int nswap = 0;
        int currSwap = 0;
        int currnSwap = 0;

        for (int i=n-1; i>0; i--) {
            for (int swapped=1; swapped>=0; swapped--) {

                int prev1 = nums1[i-1];
                int prev2 = nums2[i-1];
                int ans = INT_MAX;

                if (swapped) {
                    prev1 = prev1 + prev2;
                    prev2 = prev1 - prev2;
                    prev1 = prev1 - prev2;
                }

                // no swap
                if (nums1[i] > prev1 and nums2[i] > prev2) {
                    ans = nswap;
                }

                // swap
                if (nums1[i] > prev2 and nums2[i] > prev1) {
                    ans = min(ans, 1 + swap);
                }

                if (swapped) {
                    currSwap = ans;
                } else {
                    currnSwap = ans;
                }

            }
            swap = currSwap;
            nswap = currnSwap;
        }

        return min(swap, nswap);

    }
};

int main() {

    

    return 0;
}