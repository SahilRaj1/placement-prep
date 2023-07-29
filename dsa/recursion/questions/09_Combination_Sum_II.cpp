/* Sahil Raj */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void comb(int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds) {
        
        if (target==0) {
            ans.push_back(ds);
            return;
        }
        
        for (int i=ind; i<arr.size(); i++) {
            if (i > ind and arr[i] == arr[i-1]) {
                continue;
            }
            if (arr[i] > target) {
                break;
            }
            ds.push_back(arr[i]);
            comb(i+1, target-arr[i], arr, ans, ds);
            ds.pop_back();
        }

    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> ds;
        vector<vector<int>> ans;
        comb(0, target, candidates, ans, ds);
        return ans;
    }
};

int main() {

    

    return 0;
}