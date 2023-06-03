/* TOPIC: Maximum Sum of Non-Adjacent Elements */

// TIME COMPLEXITY: O(n)
// SPACE COMPLEXITY: O(n)

// REFERENCE: https://youtu.be/m9-H6AUBLgY
// QUESTION: https://www.codingninjas.com/codestudio/problems/maximum-sum-of-non-adjacent-elements_843261

#include <bits/stdc++.h>
using namespace std;

/* Recursion + Memoization */
class Solution {
public:

    int solve(vector<int> &arr, int i, vector<int> &dp) {
        
        // base case
        if (i < 0) {
            return 0;
        }
        
        if (i == 0) {
            return arr[i];
        }

        if (dp[i] != -1) {
            return dp[i];
        }
        
        // recursion calls
        int take = arr[i] + solve(arr, i-2, dp);
        int ntake = 0 + solve(arr, i-1, dp);

        // return answer
        dp[i] = max(take, ntake);
        return dp[i];

    }

    int maximumNonAdjacentSum(vector<int> &nums){
        int n = nums.size();
        vector<int> dp(n+10, -1);
        int ans = solve(nums, n-1, dp);
        return ans;    
    }

};


/* Tabulation */
class Solution {
public:

    int maximumNonAdjacentSum(vector<int> &nums){

        int n = nums.size();
        vector<int> dp(n+10, 0);
        dp[0] = nums[0];
        
        for (int i=1; i<n; i++) {
            int take = nums[i];
            if (i > 1) {
                take += dp[i-2];
            }
            int ntake = 0 + dp[i-1];
            dp[i] = max(take, ntake);
        }

        return dp[n-1];
        
    }

};

/* Space Optimization */
class Solution {
public:

    int maximumNonAdjacentSum(vector<int> &nums){

        int n = nums.size();
        int curr = nums[0], prev;
        
        for (int i=1; i<n; i++) {
            int take = nums[i];
            if (i > 1) {
                take += prev;
            }
            int ntake = 0 + curr;
            prev = curr;
            curr = max(take, ntake);
        }

        return curr;
        
    }

};

int main() {

    

    return 0;
}