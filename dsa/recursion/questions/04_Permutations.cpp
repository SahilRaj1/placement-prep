/* Sahil Raj */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void solve(vector<int> &nums, vector<int> &temp, vector<bool> &visited, vector<vector<int>> &ans) {

        if (temp.size() == nums.size()) {
            ans.push_back(temp);
            return;
        }

        for (int i=0; i<nums.size(); i++) {
            if (!visited[i]) {
                temp.push_back(nums[i]);
                visited[i] = true;
                solve(nums, temp, visited, ans);
                visited[i] = false;
                temp.pop_back();
            }
        }

        return;

    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        vector<bool> visited(n, false);
        vector<vector<int>> ans;
        solve(nums, temp, visited, ans);
        return ans;
    }
};

int main() {

    

    return 0;
}