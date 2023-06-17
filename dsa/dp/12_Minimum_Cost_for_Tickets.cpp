/* TOPIC: Minimum Cost for Tickets */

// TIME COMPLEXITY: O()
// SPACE COMPLEXITY: O()

// REFERENCE: https://youtu.be/oZ_xAIGCXw4
// QUESTION: https://leetcode.com/problems/minimum-cost-for-tickets/

#include <bits/stdc++.h>
using namespace std;

/* Recursion + Memoization */
class Solution {
public:

    int solve(int i, vector<int>& days, vector<int>& costs, vector<int> &dp) {

        // base cases
        if (i == days.size()) {
            return 0;
        }

        if (dp[i] != -1) {
            return dp[i];
        }

        // 1 day pass
        int op1 = costs[0] + solve(i+1, days, costs, dp);

        // 7 day pass
        int ind = i;
        while ((ind < days.size()) and (days[ind] < days[i]+7)) {
            ind++;
        }
        int op2 = costs[1] + solve(ind, days, costs, dp);

        // 30 day pass
        ind = i;
        while ((ind < days.size()) and (days[ind] < days[i]+30)) {
            ind++;
        }
        int op3 = costs[2] + solve(ind, days, costs, dp);

        dp[i] = min(op1, min(op2, op3));
        return dp[i];

    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(366, -1);
        return solve(0, days, costs, dp);
    }
};

/* Tabulation */
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {

        int n = days.size();
        vector<int> dp(n+1, INT_MAX);
        dp[n] = 0;

        for (int i=n-1; i>=0; i--) {

            // 1 day pass
            int op1 = costs[0] + dp[i+1];

            // 7 day pass
            int ind = i;
            while ((ind < days.size()) and (days[ind] < days[i]+7)) {
                ind++;
            }
            int op2 = costs[1] + dp[ind];

            // 30 day pass
            ind = i;
            while ((ind < days.size()) and (days[ind] < days[i]+30)) {
                ind++;
            }
            int op3 = costs[2] + dp[ind];

            dp[i] = min(op1, min(op2, op3));

        }
        
        return dp[0];

    }
};

/* Space Optimization */


int main() {

    

    return 0;
}