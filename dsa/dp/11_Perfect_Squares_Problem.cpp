/* TOPIC: Perfect Squares Problem */

// TIME COMPLEXITY: O()
// SPACE COMPLEXITY: O()

// REFERENCE: https://youtu.be/aJTCcyPrPOA
// QUESTION: https://leetcode.com/problems/perfect-squares/

#include <bits/stdc++.h>
using namespace std;

/* Recursion + Memoization */
class Solution {
public:

    int solve(int n, vector<int> &dp) {

        // base cases
        if (n == 0) {
            return 0;
        }
        
        if (dp[n] != -1) {
            return dp[n];
        }

        int ans = n;
        for (int i=1; i*i<=n; i++) {
            int temp = i*i;
            ans = min(ans, 1 + solve(n - temp, dp));
        }

        dp[n] = ans;
        return dp[n];

    }

    int numSquares(int n) {
        vector<int> dp(n+10, -1);
        return solve(n, dp);
    }
};

/* Tabulation */
class Solution {
public:
    int numSquares(int n) {

        vector<int> dp(n+1, n+1);
        dp[0] = 0;
        for (int i=1; i<=n; i++) {
            for (int j=1; j*j<=i; j++) {
                int temp = j*j;
                dp[i] = min(dp[i], 1 + dp[i-temp]);
            }
        }

        return dp[n];

    }
};


int main() {

    

    return 0;
}