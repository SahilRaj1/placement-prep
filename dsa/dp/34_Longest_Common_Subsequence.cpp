/* TOPIC: Longest Common Subsequence */

// TIME COMPLEXITY: O()
// SPACE COMPLEXITY: O()

// REFERENCE: https://youtu.be/y1b8pObvndA
// QUESTION: https://leetcode.com/problems/longest-common-subsequence/

#include <bits/stdc++.h>
using namespace std;

/* Recursion + Memoization */
class Solution {
public:

    int solve(string &text1, string &text2, int i, int j, vector<vector<int>> &dp) {

        if (i == text1.length() or j == text2.length()) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int ans = 0;
        if (text1[i] == text2[j]) {
            ans = 1 + solve(text1, text2, i+1, j+1, dp);
        } else {
            ans = max(solve(text1, text2, i+1, j, dp), solve(text1, text2, i, j+1, dp));
        }

        return dp[i][j] = ans;

    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length(), m = text2.length();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(text1, text2, 0, 0, dp);
    }
};

/* Tabulation */
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {

        int n = text1.length(), m = text2.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        for (int i=n-1; i>=0; i--) {
            for (int j=m-1; j>=0; j--) {

                if (text1[i] == text2[j]) {
                    dp[i][j] = 1 + dp[i+1][j+1];
                } else {
                    dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
                }

            }
        }

        return dp[0][0];

    }
};

/* Space Optimization */
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {

        int n = text1.length(), m = text2.length();

        vector<int> curr(m+1, 0);
        vector<int> next(m+1, 0);

        for (int i=n-1; i>=0; i--) {
            for (int j=m-1; j>=0; j--) {

                if (text1[i] == text2[j]) {
                    curr[j] = 1 + next[j+1];
                } else {
                    curr[j] = max(next[j], curr[j+1]);
                }

            }
            next = curr;
        }

        return curr[0];

    }
};

int main() {

    

    return 0;
}