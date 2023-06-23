/* TOPIC: Wildcard Pattern Matching */

// TIME COMPLEXITY: O()
// SPACE COMPLEXITY: O()

// REFERENCE: https://youtu.be/OgovJ9CB0hI?list=PLDzeHZWIZsTomOPnCiU3J95WufjE36wsb
// QUESTION: https://leetcode.com/problems/wildcard-matching/

#include <bits/stdc++.h>
using namespace std;

/* Recursion + Memoization */
class Solution {
public:

    bool solve(string &s, string &p, int i, int j, vector<vector<int>> &dp) {
        
        // base cases
        if (i<0 and j<0) {
            // string and pattern both exhausted
            return true;
        }

        if (j<0) {
            // pattern exhausted before string
            return false;
        }

        if (i<0) {
            // string exhausted before pattern
            for (int k=0; k<=j; k++) {
                // leftover pattern does not contain '*' 
                if (p[k] != '*') {
                    return false;
                }
            }
            // leftover pattern contains stars
            return true;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        // match
        if (s[i] == p[j] or p[j] == '?') {
            return dp[i][j] = solve(s, p, i-1, j-1, dp);
        }

        // star
        else if (p[j] == '*') {
            return dp[i][j] = (solve(s, p, i-1, j, dp) or solve(s, p, i, j-1, dp));
        }

        // not match
        return dp[i][j] = false;

    }

    bool isMatch(string s, string p) {
        int n = s.length(), m = p.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return solve(s, p, n-1, m-1, dp);
    }
};

/* Tabulation */
class Solution {
public:
    bool isMatch(string s, string p) {

        int n = s.length(), m = p.length();
        vector<vector<int>> dp(n+2, vector<int>(m+2, 0));

        // base cases
        dp[0][0] = true;
        for (int j=1; j<=m; j++) {
            bool flag = true;
            for (int k=1; k<=j; k++) {
                // leftover pattern does not contain '*' 
                if (p[k-1] != '*') {
                    flag = false;
                    break;
                }
            }
            dp[0][j] = flag;
        }

        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {

                // match
                if (s[i-1] == p[j-1] or p[j-1] == '?') {
                    dp[i][j] = dp[i-1][j-1];
                }

                // star
                else if (p[j-1] == '*') {
                    dp[i][j] = (dp[i-1][j] or dp[i][j-1]);
                }

                // not match
                else {
                    dp[i][j] = false;
                }

            }
        }

        return dp[n][m];
    }
};

/* Space Optimization */
class Solution {
public:
    bool isMatch(string s, string p) {

        int n = s.length(), m = p.length();

        vector<int> prev(m+1, 0);
        vector<int> curr(m+1, 0);

        // base cases
        prev[0] = true;
        for (int j=1; j<=m; j++) {
            bool flag = true;
            for (int k=1; k<=j; k++) {
                // leftover pattern does not contain '*' 
                if (p[k-1] != '*') {
                    flag = false;
                    break;
                }
            }
            prev[j] = flag;
        }

        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {

                // match
                if (s[i-1] == p[j-1] or p[j-1] == '?') {
                    curr[j] = prev[j-1];
                }

                // star
                else if (p[j-1] == '*') {
                    curr[j] = (prev[j] or curr[j-1]);
                }

                // not match
                else {
                    curr[j] = false;
                }

            }
            prev = curr;
        }

        return curr[m];
    }
};

int main() {

    

    return 0;
}