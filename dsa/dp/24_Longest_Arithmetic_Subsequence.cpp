/* TOPIC: Longest Arithmetic Subsequence */

// TIME COMPLEXITY: O()
// SPACE COMPLEXITY: O()

// REFERENCE: https://youtu.be/YaMcX7sem70
// QUESTION: https://leetcode.com/problems/longest-arithmetic-subsequence/

#include <bits/stdc++.h>
using namespace std;

/* Tabulation */
class Solution {
public: 
    int longestArithSeqLength(vector<int>& nums) {

        int n = nums.size();

        if (n <= 2) {
            return n;
        }

        int ans = 0;
        unordered_map<int, int> dp[n+1];

        for (int i=1; i<n; i++) {
            for (int j=0; j<i; j++) {
                
                int diff = nums[i] - nums[j];
                int ct = 1;

                if (dp[j].count(diff)) {
                    ct = dp[j][diff];
                }

                dp[i][diff] = 1 + ct;
                ans = max(ans, dp[i][diff]);

            }
        }

        return ans;
        
    }
};

int main() {

    

    return 0;
}