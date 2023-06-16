/* TOPIC: Cut Rod into Segments of X, Y, Z */

// TIME COMPLEXITY: O(n)
// SPACE COMPLEXITY: O(n)

// REFERENCE: https://youtu.be/MFAAZW2znv8
// QUESTION: https://www.codingninjas.com/codestudio/problems/cut-into-segments_1214651

#include <bits/stdc++.h>
using namespace std;

/* Recursion + Memoization */
class Solution {
public:

    int solve(int n, int x, int y, int z, vector<int> &dp) {

        // base case
        if (n < 0) {
            return INT_MIN;
        }

        if (n == 0) {
            return 0;
        }

        if (dp[n] != -1) {
            return dp[n];
        }

        // recursion calls
        int forX = 1 + solve(n-x, x, y, z, dp);
        int forY = 1 + solve(n-y, x, y, z, dp);
        int forZ = 1 + solve(n-z, x, y, z, dp);

        // return answer
        dp[n] = max(forX, max(forY, forZ));
        return dp[n];

    }

    int cutSegments(int n, int x, int y, int z) {
        vector<int> dp(n+10, -1);
        int ans = solve(n, x, y, z, dp);
        return ans < 0 ? 0 : ans;
    }

};

/* Tabulation */
class Solution {
public:

    int cutSegments(int n, int x, int y, int z) {

        vector<int> dp(n+10, INT_MIN);
        dp[0] = 0;

        for (int i=1; i<=n; i++) {
            if (i-x >= 0) {
                dp[i] = max(dp[i], 1 + dp[i-x]);
            }
            if (i-y >= 0) {
                dp[i] = max(dp[i], 1 + dp[i-y]);
            }
            if (i-z >= 0) {
                dp[i] = max(dp[i], 1 + dp[i-z]);
            }
        }

        return dp[n] < 0 ? 0 : dp[n];
        
    }

};

int main() {

    

    return 0;
}