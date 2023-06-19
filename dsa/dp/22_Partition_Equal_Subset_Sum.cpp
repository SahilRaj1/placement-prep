/* TOPIC: Partition Equal Subset Sum */

// TIME COMPLEXITY: O()
// SPACE COMPLEXITY: O()

// REFERENCE: https://youtu.be/UGY7FMHt-M8
// QUESTION: https://leetcode.com/problems/partition-equal-subset-sum/

#include <bits/stdc++.h>
using namespace std;

/* Recursion + Memoization */
class Solution {
public:

    int solve(int i, int target, vector<int> &nums, vector<vector<int>> &dp) {
        
        if (target == 0) {
            return 1;
        }

        if (i == nums.size()) {
            return 0;
        }

        if (dp[i][target] != -1) {
            return dp[i][target];
        }

        bool ntake = solve(i+1, target, nums, dp);
        bool take = 0;
        if (target >= nums[i]) {
            take = solve(i+1, target-nums[i], nums, dp);
        }

        dp[i][target] = take + ntake;
        return dp[i][target];

    }

    bool canPartition(vector<int>& nums) {
        
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum & 1) {
            return false;
        }

        vector<vector<int>> dp(n+1, vector<int>(sum/2+1, -1));

        if(solve(0, sum/2, nums, dp) >= 2) {
            return true;
        }

        return false;

    }
};

/* Tabulation */
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum & 1) {
            return false;
        }

        vector<vector<int>> dp(n+1, vector<int>(sum/2+1, 0));
        
        for (int i=0; i<=n; i++) {
            dp[i][0] = 1;
        }

        for (int i=n-1; i>=0; i--) {
            for (int target=0; target<=sum/2; target++) {

                bool ntake = dp[i+1][target];
                bool take = 0;
                if (target >= nums[i]) {
                    take = dp[i+1][target-nums[i]];
                }
                dp[i][target] = take + ntake;

            }
        }

        if(dp[0][sum/2] >= 2) {
            return true;
        }

        return false;

    }
};

/* Space Optimization */
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum & 1) {
            return false;
        }

        vector<int> curr(sum/2+1, 0);
        vector<int> next(sum/2+1, 0);

        curr[0] = 1;
        next[0] = 1;

        for (int i=n-1; i>=0; i--) {
            for (int target=0; target<=sum/2; target++) {

                bool ntake = next[target];
                bool take = 0;
                if (target >= nums[i]) {
                    take = next[target-nums[i]];
                }
                curr[target] = take + ntake;

            }
            next = curr;
        }

        if(curr[sum/2] >= 2) {
            return true;
        }

        return false;

    }
};

int main() {

    

    return 0;
}