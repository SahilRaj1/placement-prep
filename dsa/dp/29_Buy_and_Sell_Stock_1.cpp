/* TOPIC: Buy and Sell Stock 1 */

// TIME COMPLEXITY: O()
// SPACE COMPLEXITY: O()

// REFERENCE: https://youtu.be/BSRTUtvJSIk
// QUESTION: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();
        int mn = prices[0], profit = 0;

        for (int i=1; i<n; i++) {
            mn = min(mn, prices[i]);
            profit = max(profit, prices[i]-mn);
        }
        
        return profit;

    }
};

int main() {

    

    return 0;
}