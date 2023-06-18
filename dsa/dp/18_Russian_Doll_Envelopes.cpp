/* TOPIC: Russian Doll Envelopes (DP + Binary Search) */

// TIME COMPLEXITY: O()
// SPACE COMPLEXITY: O()

// REFERENCE: https://youtu.be/MYHajVcnXSA
// QUESTION: https://leetcode.com/problems/russian-doll-envelopes/

#include <bits/stdc++.h>
using namespace std;

/* DP + Binary Search */
class Solution {
public:

    static bool cmp(vector<int> &a, vector<int> &b) {
        if (a[0] == b[0]) {
            return a[1] > b[1];
        }

        return a[0] < b[0];
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        
        sort(envelopes.begin(), envelopes.end(), cmp);
        int n = envelopes.size();

        if (n == 0) {
            return 0;
        }

        vector<int> ans;
        ans.push_back(envelopes[0][1]);

        for (int i=1; i<n; i++) {
            if (envelopes[i][1] > ans.back()) {
                ans.push_back(envelopes[i][1]);
            } else {
                int index = lower_bound(ans.begin(), ans.end(), envelopes[i][1]) - ans.begin();
                ans[index] = envelopes[i][1];
            }
        }

        return ans.size();

    }
};

int main() {

    

    return 0;
}