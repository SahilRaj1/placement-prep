/* TOPIC: Longest Palindromic Subsequence */

// TIME COMPLEXITY: O()
// SPACE COMPLEXITY: O()

// REFERENCE: https://youtu.be/U095bJJtW3w
// QUESTION: https://leetcode.com/problems/longest-palindromic-subsequence/

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

    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        string rev;
        for (int i=n-1; i>=0; i--) {
            rev.push_back(s[i]);
        }
        return solve(s, rev, 0, 0, dp);
    }
};

/* Tabulation */
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        
        int n = s.length();
        string rev;
        for (int i=n-1; i>=0; i--) {
            rev.push_back(s[i]);
        }

        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for (int i=n-1; i>=0; i--) {
            for (int j=n-1; j>=0; j--) {

                if (s[i] == rev[j]) {
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
    int longestPalindromeSubseq(string s) {
        
        int n = s.length();
        string rev;
        for (int i=n-1; i>=0; i--) {
            rev.push_back(s[i]);
        }
        
        vector<int> curr(n+1, 0);
        vector<int> next(n+1, 0);

        for (int i=n-1; i>=0; i--) {
            for (int j=n-1; j>=0; j--) {

                if (s[i] == rev[j]) {
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