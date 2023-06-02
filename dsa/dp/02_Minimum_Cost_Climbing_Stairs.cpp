/* TOPIC: Minimum Cost Climbing Stairs */

// TIME COMPLEXITY: O(n)
// SPACE COMPLEXITY: O(n)

// REFERENCE: https://youtu.be/S31W3kohFDk
// QUESTION: https://leetcode.com/problems/min-cost-climbing-stairs/

#include <bits/stdc++.h>
using namespace std;

/* Memoization */
class Solution {
public:

    int solve(vector<int>& cost, int n, vector<int>& dp) {
        if (n == 0 or n == 1) {
            return cost[n];
        }
        if (dp[n] != -1) {
            return dp[n];
        }
        int left = solve(cost, n-1, dp);
        int right = solve(cost, n-2, dp);
        dp[n] = cost[n] + min(left, right);
        return dp[n];
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+2, -1);
        int ans = min(solve(cost, n-1, dp), solve(cost, n-2, dp));
        return ans;
    }
};

/* Tabulation */
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+2);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i=2; i<n; i++) {
            int left = dp[i-1];
            int right = dp[i-2];
            dp[i] = cost[i] + min(left, right);
        }
        return min(dp[n-1], dp[n-2]);
    }
};

/* Space Optimization */
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int prev1 = cost[0], prev2 = cost[1], temp;
        for (int i=2; i<n; i++) {
            temp = cost[i] + min(prev1, prev2);
            prev1 = prev2;
            prev2 = temp;
        }
        int ans = min(prev1, prev2);
        return ans;
    }
};

int main() {

    

    return 0;
}