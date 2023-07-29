/* Sahil Raj */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void solve(vector<int> &nums, int i, vector<int> &temp, vector<vector<int>> &ans) {

        if (i == nums.size()) {
            if (temp.size() == 2)
                ans.push_back(temp);
            return;
        }

        // ntake
        solve(nums, i+1, temp, ans);

        // take
        temp.push_back(nums[i]);
        solve(nums, i+1, temp, ans);
        temp.pop_back();

        return;

    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(nums, 0, temp, ans);
        return ans;
    }
};

int main() {

    

    return 0;
}