/* TOPIC: Reducing Dishes */

// TIME COMPLEXITY: O()
// SPACE COMPLEXITY: O()

// REFERENCE: https://youtu.be/_iGlRDLPLxM
// QUESTION: https://leetcode.com/problems/reducing-dishes/

#include <bits/stdc++.h>
using namespace std;

/* Recursion + Memoization */
class Solution {
public:

    int solve(int i, int time, vector<int> &satisfaction, vector<vector<int>> &dp) {

        // base cases
        if (i == satisfaction.size()) {
            return 0;
        }

        if (dp[i][time] != -1) {
            return dp[i][time];
        }

        int take = (satisfaction[i] * time) + solve(i+1, time+1, satisfaction, dp);
        int ntake = 0 + solve(i+1, time, satisfaction, dp);

        dp[i][time] = max(take, ntake);
        return dp[i][time];

    }

    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end());
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return solve(0, 1, satisfaction, dp);
    }
};

/* Tabulation */
class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {

        int n = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end());
        vector<vector<int>> dp(n+1, vector<int>(n+2, 0));
        
        for (int i=n-1; i>=0; i--) {
            for (int time=n; time>0; time--) {
                
                int take = (satisfaction[i] * time) + dp[i+1][time+1];
                int ntake = 0 + dp[i+1][time];

                dp[i][time] = max(take, ntake);

            }
        }

        return dp[0][1];

    }
};

/* Space Optimization */
class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {

        int n = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end());

        vector<int> curr(n+2, 0);
        vector<int> next(n+2, 0);
        
        for (int i=n-1; i>=0; i--) {
            for (int time=n; time>0; time--) {
                
                int take = (satisfaction[i] * time) + next[time+1];
                int ntake = 0 + next[time];

                curr[time] = max(take, ntake);

            }
            next = curr;
        }

        return curr[1];

    }
};

int main() {

    

    return 0;
}