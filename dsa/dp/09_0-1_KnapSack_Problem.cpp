/* TOPIC: 0/1 KnapSack Problem */

// TIME COMPLEXITY: O()
// SPACE COMPLEXITY: O()

// REFERENCE: https://youtu.be/xdPv2SZJLVI
// QUESTION: https://www.codingninjas.com/codestudio/problems/0-1-knapsack_920542

#include <bits/stdc++.h>
using namespace std;

/* Recursion + Memoization */
class Solution {
public:

    int solve(vector<int> &weight, vector<int> &value, int i, int maxWeight, vector<vector<int>> &dp) {
        
        // base case
        if (i == 0) {
            if (weight[i] <= maxWeight) {
                return value[i];
            } else {
                return 0;
            }
        }

        if (dp[i][maxWeight] != -1) {
            return dp[i][maxWeight];
        }

        // recursion calls
        int ntake = 0 + solve(weight, value, i-1, maxWeight, dp);
        int take = 0;
        if (weight[i] <= maxWeight) {
            take = value[i] + solve(weight, value, i-1, maxWeight-weight[i], dp);
        }

        // return answer
        dp[i][maxWeight] = max(take, ntake);
        return dp[i][maxWeight];

    }

    int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)  {
        vector<vector<int>> dp(n, vector<int>(maxWeight+1, -1));
        return solve(weight, value, n-1, maxWeight, dp);
    }

};

/* Tabulation */
class Solution {
public:

    int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)  {

        vector<vector<int>> dp(n, vector<int>(maxWeight+1, 0));

        // base case
        for (int w = weight[0]; w <= maxWeight; w++) {
            if (weight[0] <= maxWeight) {
                dp[0][w] = value[0];
            } else {
                dp[0][w] = 0;
            }
        }

        // filling dp
        for (int i=1; i<n; i++) {
            for (int w = 0; w <= maxWeight; w++) {
                
                int ntake = 0 + dp[i-1][w];
                int take = 0;
                if (weight[i] <= w) {
                    take = value[i] + dp[i-1][w - weight[i]];
                }

                dp[i][w] = max(take, ntake);

            }
        }

        // return ans
        return dp[n-1][maxWeight];
        
    }

};

/* Space Optimization */
class Solution {
public:

    int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)  {

        vector<int> prev(maxWeight+1, 0);
        vector<int> curr(maxWeight+1, 0);

        // base case
        for (int w = weight[0]; w <= maxWeight; w++) {
            if (weight[0] <= maxWeight) {
                prev[w] = value[0];
            } else {
                prev[w] = 0;
            }
        }

        // filling dp
        for (int i=1; i<n; i++) {
            for (int w = 0; w <= maxWeight; w++) {
                
                int ntake = 0 + prev[w];
                int take = 0;
                if (weight[i] <= w) {
                    take = value[i] + prev[w - weight[i]];
                }

                curr[w] = max(take, ntake);

            }
            prev = curr;
        }

        // return ans
        return prev[maxWeight];
        
    }

};

int main() {

    

    return 0;
}