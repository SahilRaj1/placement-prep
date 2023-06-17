/* TOPIC: Minimum Number of Coins */

// TIME COMPLEXITY: O()
// SPACE COMPLEXITY: O()

// REFERENCE: https://youtu.be/myPeWb3Y68A
// QUESTION: 

#include <bits/stdc++.h>
using namespace std;

/* Recursion + Memoization */
class Solution {
public:
    int dp[10010];

    int solve(int amount, vector<int>& coins) {

        // base cases
        if (amount == 0) {
            return 0;
        }

        if (dp[amount] != -1) {
            return dp[amount];
        }

        int ans = INT_MAX;
        for (int &coin: coins) {
            if (amount >= coin) {
                ans = min(ans + 0LL, solve(amount-coin, coins) + 1LL);
            }
        }

        dp[amount]=ans;
        return dp[amount];

    }

    int coinChange(vector<int>& coins, int amount) {
        memset(dp, -1, sizeof(dp));
        int ans = solve(amount, coins);
        return ans==INT_MAX ? -1 : ans;
    }
};

/* Tabulation */
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+10, INT_MAX);
        dp[0] = 0;
        for (int i=1; i<=amount; i++) {
            for (auto &coin: coins) {
                if (i >= coin) {
                    dp[i] = min(dp[i] + 0LL, dp[i-coin] + 1LL);
                }
            }
        }

        for (auto &it: dp) {
            cout<<it<<" ";
        } cout<<endl;

        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};

int main() {

    

    return 0;
}