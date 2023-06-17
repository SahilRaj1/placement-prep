/* TOPIC: Minimum Sideways Jump */

// TIME COMPLEXITY: O()
// SPACE COMPLEXITY: O()

// REFERENCE: https://youtu.be/dvTTtzamEEo?list=PLDzeHZWIZsTomOPnCiU3J95WufjE36wsb
// QUESTION: https://leetcode.com/problems/minimum-sideway-jumps/

#include <bits/stdc++.h>
using namespace std;

/* Recursion + Memoization */
class Solution {
public:

    int solve(vector<int> &obstacles, int currlane, int currpos, vector<vector<int>> &dp) {

        // base cases
        int n = obstacles.size();
        if (currpos == n-1) {
            return 0;
        }

        if (dp[currlane][currpos] != -1) {
            return dp[currlane][currpos];
        }

        // no obstacle in next position of current lane
        if (obstacles[currpos+1] != currlane) {
            return solve(obstacles, currlane, currpos + 1, dp);
        }

        // obstacle in next position of current lane
        dp[currlane][currpos] = INT_MAX;
        for (int i=1; i<=3; i++) {
            if (i != currlane and obstacles[currpos] != i) {
                dp[currlane][currpos] = min(dp[currlane][currpos], 1 + solve(obstacles, i, currpos, dp));
            }
        }

        return dp[currlane][currpos];

    }

    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<vector<int>> dp(4, vector<int>(n, -1));
        return solve(obstacles, 2, 0, dp);
    }
};

/* Tabulation */
class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {

        int n = obstacles.size();
        vector<vector<int>> dp(4, vector<int>(n, 1e9));
        for (int i=0; i<=3; i++) {
            dp[i][n-1] = 0;
        }

        for (int currpos=n-2; currpos>=0; currpos--) {
            for (int currlane=1; currlane<=3; currlane++) {

                // no obstacle in next position of current lane
                if (obstacles[currpos+1] != currlane) {
                    dp[currlane][currpos] = dp[currlane][currpos+1];
                }

                // obstacle in next position of current lane
                else {
                    int ans = 1e9;
                    for (int i=1; i<=3; i++) {
                        if (i != currlane and obstacles[currpos] != i) {
                            ans = min(ans, 1 + dp[i][currpos+1]);
                        }
                    }
                    dp[currlane][currpos] = ans;
                }

            }
        }

        return min(dp[2][0], min(1 + dp[1][0], 1 + dp[3][0]));
        
    }
};

/* Space Optimization */
class Solution {
public:

    // nhk

};

int main() {

    

    return 0;
}