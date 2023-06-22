/* TOPIC: Buy and Sell Stock 2 */

// TIME COMPLEXITY: O()
// SPACE COMPLEXITY: O()

// REFERENCE: https://youtu.be/dlKGCNVel6A
// QUESTION: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

#include <bits/stdc++.h>
using namespace std;

/* Without DP */
class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();
        int mn=prices[0], profit=0, mx=prices[0];
        
        for (int i=1; i<n; i++) {
            if (prices[i]<=prices[i-1]) {
                mn = prices[i];
            } else {
                mx = prices[i];
                profit += mx-mn;
                mn = prices[i];
            }
        }

        return profit;

    }
};

/* Recursion + Memoization */
class Solution {
public:

    int solve(vector<int>& prices, int i, int buy, vector<vector<int>> &dp) {

        if (i == prices.size()) {
            return 0;
        }

        if (dp[i][buy] != -1) {
            return dp[i][buy];
        }

        int profit = 0;

        if (buy) {
            int takeBuy = -prices[i] + solve(prices, i+1, 0, dp);
            int ntakeBuy = 0 + solve(prices, i+1, 1, dp);
            profit = max(takeBuy, ntakeBuy);
        } else {
            int takeSell = prices[i] + solve(prices, i+1, 1, dp);
            int ntakeSell = 0 + solve(prices, i+1, 0, dp);
            profit = max(takeSell, ntakeSell);
        }

        return dp[i][buy] = profit;

    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, -1));
        return solve(prices, 0, true, dp);
    }
};

/* Tabulation */
class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));

        for (int i=n-1; i>=0; i--) {
            for (int buy=0; buy<=1; buy++) {

                int profit = 0;

                if (buy) {
                    profit = max(-prices[i] + dp[i+1][0], dp[i+1][1]);
                } else {
                    profit = max(prices[i] + dp[i+1][1], dp[i+1][0]);
                }

                dp[i][buy] = profit;

            }
        }

        return dp[0][1];

    }
};

/* Space Optimization */
class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        vector<int> curr(2, 0);
        vector<int> next(2, 0);

        for (int i=n-1; i>=0; i--) {
            for (int buy=0; buy<=1; buy++) {

                int profit = 0;

                if (buy) {
                    profit = max(-prices[i] + next[0], next[1]);
                } else {
                    profit = max(prices[i] + next[1], next[0]);
                }

                curr[buy] = profit;

            }
            next = curr;
        }

        return curr[1];

    }
};

int main() {

    

    return 0;
}