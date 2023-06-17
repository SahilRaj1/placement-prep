/* TOPIC: Minimum Score Triangulation of Polygon */

// TIME COMPLEXITY: O()
// SPACE COMPLEXITY: O()

// REFERENCE: https://youtu.be/Eo4G_LPCgX8
// QUESTION: https://leetcode.com/problems/minimum-score-triangulation-of-polygon/

#include <bits/stdc++.h>
using namespace std;

/* Recursion + Memoization */
class Solution {
public:

    int solve(int i, int j, vector<int> &values, vector<vector<int>> &dp) {
        
        // base cases
        if (i+1 == j) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        dp[i][j] = INT_MAX;
        for (int k=i+1; k<j; k++) {
            int score = values[i] * values[j] * values[k];
            int total = score + solve(i, k, values, dp) + solve(k, j, values, dp);
            dp[i][j] = min(dp[i][j], total);
        }

        return dp[i][j];

    }

    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return solve(0, n-1, values, dp);
    }
};

/* Tabulation */
class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {

        int n = values.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, INT_MAX));
        
        // base case
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (i+1 == j) {
                    dp[i][j] = 0;
                }
            }
        }

        // filling dp array
        for (int i=n-1; i>=0; i--) {
            for (int j=0; j<n; j++) {
                for (int k=i+1; k<j; k++) {
                    int score = values[i] * values[j] * values[k];
                    int total = score + dp[i][k] + dp[k][j];
                    dp[i][j] = min(dp[i][j], total);
                }
            }
        }

        return dp[0][n-1];

    }
};

int main() {

    

    return 0;
}