/* TOPIC: Buy and Sell Stock 3 */

// TIME COMPLEXITY: O()
// SPACE COMPLEXITY: O()

// REFERENCE: https://youtu.be/NW7XRzg3smo
// QUESTION: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

#include <bits/stdc++.h>
using namespace std;

/* Recursion + Memoization */
/* Recursion + Memoization */
class Solution {
public:

    int solve(vector<int>& prices, int i, int buy, int limit, vector<vector<vector<int>>> &dp) {

        if (i == prices.size()) {
            return 0;
        }

        if (limit == 0) {
            return 0;
        }

        if (dp[i][buy][limit] != -1) {
            return dp[i][buy][limit];
        }

        int profit = 0;

        if (buy) {
            int takeBuy = -prices[i] + solve(prices, i+1, 0, limit, dp);
            int ntakeBuy = 0 + solve(prices, i+1, 1, limit, dp);
            profit = max(takeBuy, ntakeBuy);
        } else {
            int takeSell = prices[i] + solve(prices, i+1, 1, limit-1, dp);
            int ntakeSell = 0 + solve(prices, i+1, 0, limit, dp);
            profit = max(takeSell, ntakeSell);
        }

        return dp[i][buy][limit] = profit;

    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, -1)));
        return solve(prices, 0, true, 2, dp);
    }
};

/* Tabulation */
class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));

        for (int i=n-1; i>=0; i--) {
            for (int buy=0; buy<=1; buy++) {
                for (int limit=1; limit<=2; limit++) {

                    int profit = 0;

                    if (buy) {
                        profit = max(-prices[i] + dp[i+1][0][limit], dp[i+1][1][limit]);
                    } else {
                        profit = max(prices[i] + dp[i+1][1][limit-1], dp[i+1][0][limit]);
                    }

                    dp[i][buy][limit] = profit;

                }
            }
        }

        return dp[0][1][2];

    }
};

/* Space Optimization */
class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        vector<vector<int>> curr(2, vector<int>(3, 0));
        vector<vector<int>> next(2, vector<int>(3, 0));

        for (int i=n-1; i>=0; i--) {
            for (int buy=0; buy<=1; buy++) {
                for (int limit=1; limit<=2; limit++) {

                    int profit = 0;

                    if (buy) {
                        profit = max(-prices[i] + next[0][limit], next[1][limit]);
                    } else {
                        profit = max(prices[i] + next[1][limit-1], next[0][limit]);
                    }

                    curr[buy][limit] = profit;

                }
                next = curr;
            }
        }

        return curr[1][2];

    }
};

int main() {

    

    return 0;
}