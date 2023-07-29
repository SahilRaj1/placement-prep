/* Sahil Raj */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<vector<int>> ans;

    void solve(unordered_map<int, int>& freq, int n, vector<int>& temp) {
        
        if (temp.size() == n) {
            ans.push_back(temp);
            return;
        }

        for (auto &it: freq) {
            if (it.second > 0) {
                temp.push_back(it.first);
                it.second--;
                solve(freq, n, temp);
                it.second++;
                temp.pop_back();
            }
        }

    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> temp;
        unordered_map<int, int> freq;
        for (int &it: nums) {
            freq[it]++;
        }
        solve(freq, nums.size(), temp);
        return ans;
    }
};

int main() {

    

    return 0;
}