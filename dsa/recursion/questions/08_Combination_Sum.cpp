/* Sahil Raj */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void comb(int i, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds) {
        if (i==arr.size()) {
            if (target==0) ans.push_back(ds);
            return;
        }
        
        if (arr[i]<=target) {
            ds.push_back(arr[i]);
            comb(i, target-arr[i], arr, ans, ds);
            ds.pop_back();
        }
        
        comb(i+1, target, arr, ans, ds);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ds;
        vector<vector<int>> ans;
        comb(0, target, candidates, ans, ds);
        return ans;
    }
};

int main() {

    

    return 0;
}