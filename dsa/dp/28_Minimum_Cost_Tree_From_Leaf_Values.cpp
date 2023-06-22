/* TOPIC: Minimum Cost Tree From Leaf Values */

// TIME COMPLEXITY: O()
// SPACE COMPLEXITY: O()

// REFERENCE: https://youtu.be/LDiD9fr28tc
// QUESTION: https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/

#include <bits/stdc++.h>
using namespace std;

/* Recursion + Memoization */
class Solution {
public:

    int solve(vector<int>& arr, map<pair<int, int>, int> &maxi, int left, int right, vector<vector<int>> &dp) {

        if (left == right) {
            return 0;
        }

        if (dp[left][right] != -1) {
            return dp[left][right];
        }

        int ans = INT_MAX;
        for (int i=left; i<right; i++) {
            ans = min(ans, maxi[{left, i}] * maxi[{i+1, right}] + solve(arr, maxi, left, i, dp) + solve(arr, maxi, i+1, right, dp));
        }

        return dp[left][right] = ans;

    }

    int mctFromLeafValues(vector<int>& arr) {
        
        int n = arr.size();
        map<pair<int, int>, int> maxi;
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));

        for (int i=0; i<n; i++) {
            maxi[{i, i}] = arr[i];
            for (int j=i+1; j<n; j++) {
                maxi[{i, j}] = max(arr[j], maxi[{i, j-1}]);
            }
        }

        return solve(arr, maxi, 0, n-1, dp);

    }
};

/* Tabulation */
class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        
        int n = arr.size();
        map<pair<int, int>, int> maxi;
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for (int i=0; i<n; i++) {
            maxi[{i, i}] = arr[i];
            for (int j=i+1; j<n; j++) {
                maxi[{i, j}] = max(arr[j], maxi[{i, j-1}]);
            }
        }

        for (int left=n-1; left>=0; left--) {
            for (int right=0; right<n; right++) {

                if (left == right) {
                    dp[left][right] = 0;
                    continue;
                }

                int ans = INT_MAX;
                for (int i=left; i<right; i++) {
                    ans = min(ans, maxi[{left, i}] * maxi[{i+1, right}] + dp[left][i] + dp[i+1][right]);
                }

                dp[left][right] = ans;

            }
        }

        return dp[0][n-1];

    }
};

/* Space Optimization */


int main() {

    

    return 0;
}