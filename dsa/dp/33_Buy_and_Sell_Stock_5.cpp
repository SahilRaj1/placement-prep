/* TOPIC: Buy and Sell Stock 5 */

// TIME COMPLEXITY: O()
// SPACE COMPLEXITY: O()

// REFERENCE: https://youtu.be/KFqhgQeQAXc
// QUESTION: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

#include <bits/stdc++.h>
using namespace std;

/* Recursion + Memoization */
class Solution {
public:

    int solve(vector<int>& prices, int i, int buy, int fee, vector<vector<int>> &dp) {

        if (i == prices.size()) {
            return 0;
        }

        if (dp[i][buy] != -1) {
            return dp[i][buy];
        }

        int profit = 0;

        if (buy) {
            int takeBuy = -prices[i] + solve(prices, i+1, 0, fee, dp);
            int ntakeBuy = 0 + solve(prices, i+1, 1, fee, dp);
            profit = max(takeBuy, ntakeBuy);
        } else {
            int takeSell = prices[i] - fee + solve(prices, i+1, 1, fee, dp);
            int ntakeSell = 0 + solve(prices, i+1, 0, fee, dp);
            profit = max(takeSell, ntakeSell);
        }

        return dp[i][buy] = profit;

    }

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, -1));
        return solve(prices, 0, true, fee, dp);
    }
};

/* Tabulation */
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {

        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));

        for (int i=n-1; i>=0; i--) {
            for (int buy=0; buy<=1; buy++) {

                int profit = 0;

                if (buy) {
                    profit = max(-prices[i] + dp[i+1][0], dp[i+1][1]);
                } else {
                    profit = max(prices[i] + dp[i+1][1] - fee, dp[i+1][0]);
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
    int maxProfit(vector<int>& prices, int fee) {

        int n = prices.size();

        vector<int> curr(2, 0);
        vector<int> next(2, 0);

        for (int i=n-1; i>=0; i--) {
            for (int buy=0; buy<=1; buy++) {

                int profit = 0;

                if (buy) {
                    profit = max(-prices[i] + next[0], next[1]);
                } else {
                    profit = max(prices[i] + next[1] - fee, next[0]);
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