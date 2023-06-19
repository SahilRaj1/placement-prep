/* TOPIC: Number of Dice Rolls with Target Sum */

// TIME COMPLEXITY: O()
// SPACE COMPLEXITY: O()

// REFERENCE: https://youtu.be/XY297u8qRDI
// QUESTION: https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/

#include <bits/stdc++.h>
using namespace std;

/* Recursion + Memoization */
class Solution {
public:

    const int M = 1e9+7;

    int solve(int n, int k, int target, vector<vector<int>> &dp) {

        if (target == 0) {
            if (n != 0) {
                return 0;
            }
            return 1;
        }

        if (n == 0) {
            return 0;
        }

        if (dp[n][target] != -1) {
            return dp[n][target];
        }

        int ways = 0;
        for (int num=1; num<=k; num++) {
            if (target >= num) {
                ways = (ways + 0LL + solve(n-1, k, target-num, dp)) % M;
            }
        }

        dp[n][target] = ways;
        return dp[n][target];

    }

    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+10, vector<int>(target+10, -1));
        return solve(n, k, target, dp);
    }
};

/* Tabulation */
class Solution {
public:

    const int M = 1e9+7;

    int numRollsToTarget(int n, int k, int target) {

        vector<vector<int>> dp(n+1, vector<int>(target+1, 0));
        dp[0][0] = 1;

        for (int i=1; i<=n; i++) {
            for (int j=1; j<=target; j++) {

                int ways = 0;
                for (int num=1; num<=k; num++) {
                    if (j >= num) {
                        ways = (ways + 0LL + dp[i-1][j-num]) % M;
                    }
                }

                dp[i][j] = ways;

            }
        }

        return dp[n][target];

    }
};

/* Space Optimization */
class Solution {
public:

    const int M = 1e9+7;

    int numRollsToTarget(int n, int k, int target) {

        vector<int> prev(target+1, 0);
        vector<int> curr(target+1, 0);
        prev[0] = 1;

        for (int i=1; i<=n; i++) {
            for (int j=1; j<=target; j++) {

                int ways = 0;
                for (int num=1; num<=k; num++) {
                    if (j >= num) {
                        ways = (ways + 0LL + prev[j-num]) % M;
                    }
                }

                curr[j] = ways;

            }
            prev = curr;
        }

        return prev[target];

    }
};

int main() {

    

    return 0;
}