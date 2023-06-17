/* TOPIC: Count Derangements */

// TIME COMPLEXITY: O()
// SPACE COMPLEXITY: O()

// REFERENCE: https://youtu.be/NW-BLDQHFXk
// QUESTION: https://www.codingninjas.com/codestudio/problems/count-derangements_873861

#include <bits/stdc++.h>
using namespace std;

/* Recursion + Memoization */
class Solution {

    const int M = 1e9+7;

    long long int solve(int n, vector<long long int> &dp) {

        // base cases
        if (n == 1 or n == 2) {
            return n-1;
        }

        if (dp[n] != -1) {
            return dp[n];
        }

        dp[n] = ((n-1) * (solve(n-1, dp) + solve(n-2, dp)) % M) % M;
        return dp[n];

    }

    long long int countDerangements(int n) {
        
        vector<long long int> dp(n+1, -1);
        return solve(n, dp);

    }

};

/* Tabulation */
class Solution {

    const int M = 1e9+7;

    long long int countDerangements(int n) {
        
        vector<long long int> dp(n+1, -1);
        dp[1] = 0;
        dp[2] = 1;

        for (int i=3; i<=n; i++) {
            dp[i] = ((i-1) * (dp[i-1] + dp[i-2]) % M) % M;
        }

        return dp[n];

    }

};

/* Space Optimization */
class Solution {

    const int M = 1e9+7;

    long long int countDerangements(int n) {

        if (n == 1 or n == 2) {
            return n-1;
        }
        
        long long int prev2 = 0;
        long long int prev1 = 1;
        long long int ans;

        for (int i=3; i<=n; i++) {
            ans = ((i-1) * (prev1 + prev2) % M) % M;
            prev2 = prev1;
            prev1 = ans;
        }

        return ans;

    }

};

int main() {

    

    return 0;
}