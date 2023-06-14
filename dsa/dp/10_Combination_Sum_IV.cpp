/* TOPIC: Combination Sum IV Problem */

// TIME COMPLEXITY: O(target)
// SPACE COMPLEXITY: O(target)

// REFERENCE: https://youtu.be/Wct0mN2SCRQ
// QUESTION: https://leetcode.com/problems/combination-sum-iv/

#include <bits/stdc++.h>
using namespace std;

/* Recursion + Memoization */
class Solution {
public:

    int solve(vector<int>& nums, int target, vector<int> &dp) {
        
        // base cases
        if (target == 0) {
            return 1;
        }

        if (target < 0) {
            return 0;
        }

        if (dp[target] != -1) {
            return dp[target];
        }

        int ans = 0;
        for (int i=0; i<nums.size(); i++) {
            ans += solve(nums, target-nums[i], dp);
        }

        return dp[target] = ans;

    }

    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(1010, -1);
        return solve(nums, target, dp);
    }
};

/* Tabulation */
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {

        int n = nums.size();
        vector<int> dp(target+10, 0);
        dp[0] = 1;

        for (int i=1; i<=target; i++) {
            for (int j=0; j<n; j++) {
                if (i >= nums[j]) {
                    dp[i] += dp[i - nums[j]];
                }
            }
        }

        return dp[target];

    }
};

int main() {

    

    return 0;
}