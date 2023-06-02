/* TOPIC: Frog Jump  */

// TIME COMPLEXITY: O(n)
// SPACE COMPLEXITY: O(n)

// REFERENCE: https://youtu.be/EgG3jsGoPvQ
// QUESTION: https://www.codingninjas.com/codestudio/problems/frog-jump_3621012

#include <bits/stdc++.h>
using namespace std;

/* Memoization */
class Solution {
public:
    int solve(vector<int> &heights, int i, vector<int> &dp) {
        
        // base case
        if (i == 0) {
            return 0;
        }

        if (dp[i] != -1) {
            return dp[i];
        }

        // recursion call
        int left = solve(heights, i-1, dp) + abs(heights[i] - heights[i-1]);
        int right = INT_MAX;
        if (i > 1) {
            right = solve(heights, i-2, dp) + abs(heights[i] - heights[i-2]);
        }

        // return answer
        dp[i] = min(left, right);
        return dp[i];

    }

    int frogJump(int n, vector<int> &heights) {
        vector<int> dp(n+10, -1);
        int ans = solve(heights, n-1, dp);
        return ans;
    }
};

/* Tabulation */
class Solution {
public:
    int frogJump(int n, vector<int> &heights) {

        vector<int> dp(n+10);
        
        // base case
        dp[0] = 0;

        // iteratively filling dp array
        for (int i=1; i<n; i++) {
            int left = dp[i-1] + abs(heights[i] - heights[i-1]);
            int right = INT_MAX;
            if (i > 1) {
                right = dp[i-2] + abs(heights[i] - heights[i-2]);
            }
            dp[i] = min(left, right);
        }

        // return answer
        return dp[n-1];

    }
};

/* Space Optimization */
class Solution {
public:
    int frogJump(int n, vector<int> &heights) {

    vector<int> dp(n+10);
        
        // base case
        int prev1, prev2 = 0;

        // iteratively filling dp array
        for (int i=1; i<n; i++) {
            int left = prev2 + abs(heights[i] - heights[i-1]);
            int right = INT_MAX;
            if (i > 1) {
                right = prev1 + abs(heights[i] - heights[i-2]);
            }
            prev1 = prev2;
            prev2 = min(left, right);
        }

        // return answer
        return prev2;

    }
};

int main() {

    

    return 0;
}