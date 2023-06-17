/* TOPIC: Largest Square area in Matrix */

// TIME COMPLEXITY: O()
// SPACE COMPLEXITY: O()

// REFERENCE: https://youtu.be/MMr19RE7KYY
// QUESTION: https://leetcode.com/problems/maximal-square/description/

#include <bits/stdc++.h>
using namespace std;

/* Recursion + Memoization */
class Solution {
public:

    int solve(int i, int j, vector<vector<char>>& matrix, int &maxi, vector<vector<int>> &dp) {

        // base case
        if (i >= matrix.size() or j >= matrix[0].size()) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int right = solve(i, j+1, matrix, maxi, dp);
        int down = solve(i+1, j, matrix, maxi, dp);
        int diag = solve(i+1, j+1, matrix, maxi, dp);

        if (matrix[i][j] == '1') {
            dp[i][j] = 1 + min(right, min(down, diag));
            maxi = max(maxi, dp[i][j]);
            return dp[i][j];
        }

        return 0;

    }

    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vector<int>> dp(301, vector<int>(301, -1));
        int maxi = 0;
        solve(0, 0, matrix, maxi, dp);
        return maxi * maxi;
    }
};

/* Tabulation */
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        int maxi = 0;
        for (int i=n-1; i>=0; i--) {

            for (int j=m-1; j>=0; j--) {
                int right = dp[i][j+1];
                int down = dp[i+1][j];
                int diag = dp[i+1][j+1];

                if (matrix[i][j] == '1') {
                    dp[i][j] = 1 + min(right, min(down, diag));
                    maxi = max(maxi, dp[i][j]);
                } else {
                    dp[i][j] = 0;
                }

            }
        }

        return maxi * maxi;

    }
};

/* Space Optimization */
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<int> curr(m+1, 0);
        vector<int> next(m+1, 0);

        int maxi = 0;
        for (int i=n-1; i>=0; i--) {
            for (int j=m-1; j>=0; j--) {

                int right = curr[j+1];
                int down = next[j];
                int diag = next[j+1];

                if (matrix[i][j] == '1') {
                    curr[j] = 1 + min(right, min(down, diag));
                    maxi = max(maxi, curr[j]);
                } else {
                    curr[j] = 0;
                }
            }
            
            next = curr;
        }

        return maxi * maxi;

    }
};

int main() {

    

    return 0;
}