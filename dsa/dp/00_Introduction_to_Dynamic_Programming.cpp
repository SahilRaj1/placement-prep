/* TOPIC: Introduction to Dynamic Programming - Fibonacci */

// TIME COMPLEXITY: O(n)
// SPACE COMPLEXITY: O(n)

// REFERENCE: https://youtu.be/tyB0ztf0DNY
// QUESTION: https://leetcode.com/problems/fibonacci-number/

#include <bits/stdc++.h>
using namespace std;

/* Recursion + Memoization */
class Solution {
public:
    int solve(int n, vector<int>& dp) {
        if (n == 0 or n == 1) {
            return n;
        }
        if (dp[n] != -1) {
            return dp[n];
        }
        dp[n] = solve(n-1, dp) + solve(n-2, dp);
        return dp[n];
    }

    int fib(int n) {
        vector<int> dp(n+5, -1);
        dp[0] = 0;
        dp[1] = 1;
        return solve(n, dp);
    }
};

/* Tabulation */
class Solution {
public:
    int fib(int n) {
        vector<int> dp(n+5);
        dp[0] = 0;
        dp[1] = 1;
        for (int i=2; i<=n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};


/* Space Optimization */
class Solution {
public:
    int fib(int n) {
        if (n == 0 or n == 1) {
            return n;
        }
        int prev1 = 0, prev2 = 1, temp;
        for (int i=2; i<=n; i++) {
            temp = prev1 + prev2;
            prev1 = prev2;
            prev2 = temp;
        }
        return temp;
    }
};


int main() {

    

    return 0;
}