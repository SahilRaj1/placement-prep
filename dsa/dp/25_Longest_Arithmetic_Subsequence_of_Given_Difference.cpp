/* TOPIC: Longest Arithmetic Subsequence of Given Difference */

// TIME COMPLEXITY: O()
// SPACE COMPLEXITY: O()

// REFERENCE: https://youtu.be/IOOFHFXenQU
// QUESTION: https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/

#include <bits/stdc++.h>
using namespace std;

/* Tabulation */
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
        
        int n = arr.size();
        unordered_map<int, int> dp;
        int ans = 0;

        for (int i=0; i<n; i++) {
            
            int temp = arr[i] - diff;
            int tempAns = 0;

            // check if answer exists for temp
            if (dp.count(temp)) {
                tempAns = dp[temp];
            }

            // update current answer
            dp[arr[i]] = 1 + tempAns;

            // update answer
            ans = max(ans, dp[arr[i]]);

        }

        return ans;

    }
};

int main() {

    

    return 0;
}