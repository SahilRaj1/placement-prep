/* TOPIC: Pizza with 3n Slices */

// TIME COMPLEXITY: O()
// SPACE COMPLEXITY: O()

// REFERENCE: https://youtu.be/QZ9edJ0JCPw
// QUESTION: 

#include <bits/stdc++.h>
using namespace std;

/* Recursion + Memoization */
class Solution {
public:

    int solve(int i, int last, vector<int> &slices, int k, vector<vector<int>> &dp) {

        if (k == 0 or i > last) {
            return 0;
        }

        if (dp[i][k] != -1) {
            return dp[i][k];
        }

        int take = slices[i] + solve(i+2, last, slices, k-1, dp);
        int ntake = 0 + solve(i+1, last, slices, k, dp);

        dp[i][k] = max(take, ntake);
        return dp[i][k];

    }

    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size();
        int k = n/3;
        vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
        int ans1 = solve(0, n-2, slices, k, dp);
        for (int i=0; i<=n; i++) {
            for (auto &it: dp[i]) {
                it = -1;
            }
        }
        int ans2 = solve(1, n-1, slices, k, dp);
        return max(ans1, ans2);
    }
};

/* Tabulation */
class Solution {
public:
    int maxSizeSlices(vector<int>& slices) {

        int n = slices.size();

        vector<vector<int>> dp1(n+2, vector<int>(n/3+2, 0));
        vector<vector<int>> dp2(n+2, vector<int>(n/3+2, 0));
        
        for (int i=n-2; i>=0; i--) {
            for (int k=1; k<=n/3; k++) {

                int take = slices[i] + dp1[i+2][k-1];
                int ntake = 0 + dp1[i+1][k];
                dp1[i][k] = max(take, ntake);

            }
        }

        for (int i=n-1; i>=1; i--) {
            for (int k=1; k<=n/3; k++) {

                int take = slices[i] + dp2[i+2][k-1];
                int ntake = 0 + dp2[i+1][k];
                dp2[i][k] = max(take, ntake);
                
            }
        }

        return max(dp1[0][n/3], dp2[1][n/3]);
        
    }
};

/* Space Optimization */
class Solution {
public:
    int maxSizeSlices(vector<int>& slices) {

        int n = slices.size();

        vector<int> prev1(n/3+2, 0);
        vector<int> curr1(n/3+2, 0);
        vector<int> next1(n/3+2, 0);
        
        vector<int> prev2(n/3+2, 0);
        vector<int> curr2(n/3+2, 0);
        vector<int> next2(n/3+2, 0);
        
        for (int i=n-2; i>=0; i--) {
            for (int k=1; k<=n/3; k++) {

                int take = slices[i] + next1[k-1];
                int ntake = 0 + curr1[k];
                prev1[k] = max(take, ntake);

            }
            next1 = curr1;
            curr1 = prev1;
        }

        for (int i=n-1; i>=1; i--) {
            for (int k=1; k<=n/3; k++) {

                int take = slices[i] + next2[k-1];
                int ntake = 0 + curr2[k];
                prev2[k] = max(take, ntake);
                
            }
            next2 = curr2;
            curr2 = prev2;
        }

        return max(prev1[n/3], prev2[n/3]);

    }
};

int main() {

    

    return 0;
}