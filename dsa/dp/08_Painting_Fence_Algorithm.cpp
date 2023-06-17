/* TOPIC: Painting Fence Algorithm */

// TIME COMPLEXITY: O()
// SPACE COMPLEXITY: O()

// REFERENCE: https://youtu.be/5eFh5CC-8KY
// QUESTION: https://www.codingninjas.com/codestudio/problems/painting-fences_920549

#include <bits/stdc++.h>
using namespace std;

/* Recursion + Memoization */
class Solution {
public:

    const int M = 1e9+7;

    int solve(int n, int k, vector<int> &dp) {

        if (n == 1) {
            // only one color at a time = k ways
            return k;
        }

        if (n == 2) {
            // same color = k ways
            // diff color = k * (k-1) ways
            return (k + (k * (k-1)) % M) % M;
        }

        if (dp[n] != -1) {
            return dp[n];
        }

        dp[n] = ((solve(n-2, k, dp) * (k-1)) % M + (solve(n-1, k, dp) * (k-1)) % M) % M;
        return dp[n];

    }

    int numberOfWays(int n, int k) {
        vector<int> dp(n+1, -1);
        return solve(n, k, dp);
    }

};

/* Tabulation */
class Solution {
public:

    const int M = 1e9+7;

    int numberOfWays(int n, int k) {

        vector<int> dp(n+1, -1);
        dp[1] = k;
        dp[2] = (k + (k * (k-1)) % M) % M;

        for (int i=3; i<=n; i++) {
            dp[i] = ((dp[i-2] * 1LL * (k-1)) % M + 0LL + (dp[i-1] * 1LL * (k-1)) % M) % M;
        }

        return dp[n];

    }

};

/* Space Optimization */
class Solution {
public:

    const int M = 1e9+7;

    int numberOfWays(int n, int k) {

        int prev2 = k;
        int prev1 = (k + (k * (k-1)) % M) % M;

        if (n == 1) {
            return prev2;
        }

        if (n == 2) {
            return prev1;
        }

        int ans;
        for (int i=3; i<=n; i++) {
            ans = ((prev1 * 1LL * (k-1)) % M + 0LL + (prev2 * 1LL * (k-1)) % M) % M;
            prev2 = prev1;
            prev1 = ans;
        }

        return ans;

    }

};

int main() {

    

    return 0;
}