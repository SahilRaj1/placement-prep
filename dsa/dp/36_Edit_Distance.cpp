/* TOPIC: Edit Distance */

// TIME COMPLEXITY: O()
// SPACE COMPLEXITY: O()

// REFERENCE: https://youtu.be/8HEjwf28LyE
// QUESTION: https://leetcode.com/problems/edit-distance/

#include <bits/stdc++.h>
using namespace std;

/* Recursion + Memoization */
class Solution {
public:

    int solve(string &a, string &b, int i, int j, vector<vector<int>> &dp) {

        if (i == a.length()) {
            return b.length() - j;
        }

        if (j == b.length()) {
            return a.length() - i;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        // character matched
        if (a[i] == b[j]) {
            return solve(a, b, i+1, j+1, dp);
        }

        // character not matched
        int ans = INT_MAX;

        // insert
        int insertAns = solve(a, b, i, j+1, dp);
        // delete
        int deleteAns = solve(a, b, i+1, j, dp);
        // replace
        int replaceAns = solve(a, b, i+1, j+1, dp);

        ans = 1 + min(insertAns, min(deleteAns, replaceAns));
        return dp[i][j] = ans;

    }

    int minDistance(string word1, string word2) {
        int n = word1.length(), m = word2.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return solve(word1, word2, 0, 0, dp);
    }
};

/* Tabulation */
class Solution {
public:
    int minDistance(string word1, string word2) {

        int n = word1.length(), m = word2.length();
        vector<vector<int>> dp(n+2, vector<int>(m+2, 0));

        for (int i=0; i<=n; i++) {
            dp[i][m] = n - i;
        }

        for (int i=0; i<=m; i++) {
            dp[n][i] = m - i;
        }

        for (int i=n-1; i>=0; i--) {
            for (int j=m-1; j>=0; j--) {

                // character matched
                if (word1[i] == word2[j]) {
                    dp[i][j] = dp[i+1][j+1];
                    continue;
                }

                // character not matched
                int ans = INT_MAX;

                // 1. insert
                int insertAns = dp[i][j+1];
                // 2. delete
                int deleteAns = dp[i+1][j];
                // 3. replace
                int replaceAns = dp[i+1][j+1];

                ans = 1 + min(insertAns, min(deleteAns, replaceAns));
                dp[i][j] = ans;

            }
        }

        return dp[0][0];
    }
};

/* Space Optimization */
class Solution {
public:
    int minDistance(string word1, string word2) {

        int n = word1.length(), m = word2.length();

        if (n == 0) {
            return m;
        }

        vector<int> curr(m+1, 0);
        vector<int> next(m+1, 0);

        // base case
        for (int i=0; i<=m; i++) {
            next[i] = m - i;
        }

        for (int i=n-1; i>=0; i--) {

            // base case
            curr[m] = n - i;

            for (int j=m-1; j>=0; j--) {

                // character matched
                if (word1[i] == word2[j]) {
                    curr[j] = next[j+1];
                    continue;
                }

                // character not matched
                int ans = INT_MAX;

                // 1. insert
                int insertAns = curr[j+1];
                // 2. delete
                int deleteAns = next[j];
                // 3. replace
                int replaceAns = next[j+1];

                ans = 1 + min(insertAns, min(deleteAns, replaceAns));
                curr[j] = ans;

            }
            next = curr;
        }

        return curr[0];
    }
};

int main() {

    

    return 0;
}