/* TOPIC: Longest Increasing Subsequence */

// TIME COMPLEXITY: O()
// SPACE COMPLEXITY: O()

// REFERENCE: https://youtu.be/MYHajVcnXSA
// QUESTION: https://leetcode.com/problems/longest-increasing-subsequence/

#include <bits/stdc++.h>
using namespace std;

/* Recursion + Memoization */
class Solution {
public:

    int solve(vector<int> &nums, int curr, int prev, vector<vector<int>> &dp) {

        // base cases
        if (curr == nums.size()) {
            return 0;
        }

        if (dp[curr][prev+1] != -1) {
            return dp[curr][prev+1];
        }

        int take = 0;
        if (prev == -1 or nums[curr] > nums[prev]) {
            take = 1 + solve(nums, curr+1, curr, dp);
        }
        int ntake = 0 + solve(nums, curr+1, prev, dp);

        dp[curr][prev+1] = max(take, ntake);
        return dp[curr][prev+1];

    }

    int lengthOfLIS(vector<int>& nums) {
            int n = nums.size();
            vector<vector<int>> dp(n+1, vector<int>(n+2, -1));
            return solve(nums, 0, -1, dp);
    }
};

/* Tabulation */
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+2, 0));

        for (int curr = n-1; curr>=0; curr--) {
            for (int prev = curr-1; prev>=-1; prev--) {

                int take = 0;
                if (prev == -1 or nums[curr] > nums[prev]) {
                    take = 1 + dp[curr+1][curr + 1];
                }
                int ntake = 0 + dp[curr+1][prev+1];

                dp[curr][prev+1] = max(take, ntake);

            }
        }

        return dp[0][0];

    }
};

/* Space Optimization */
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();
        
        vector<int> currRow(n+2, 0);
        vector<int> nextRow(n+2, 0);

        for (int curr = n-1; curr>=0; curr--) {
            for (int prev = curr-1; prev>=-1; prev--) {

                int take = 0;
                if (prev == -1 or nums[curr] > nums[prev]) {
                    take = 1 + nextRow[curr + 1];
                }
                int ntake = 0 + nextRow[prev+1];

                currRow[prev+1] = max(take, ntake);

            }
            nextRow = currRow;
        }

        return nextRow[0];

    }
};

int main() {

    

    return 0;
}