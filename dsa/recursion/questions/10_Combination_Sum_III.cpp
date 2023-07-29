/* Sahil Raj */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void solve(int i, int n, int k, vector<int> &temp, vector<vector<int>> &ans) {

        // base cases
        if (k == 0) {
            if (n == 0) {
                ans.push_back(temp);
            }
            return;
        }

        if (i > 9) {
            return;
        }

        if (n <= 0) {
            return;
        }

        // not take
        solve(i+1, n, k, temp, ans);
        
        // take
        temp.push_back(i);
        solve(i+1, n-i, k-1, temp, ans);
        temp.pop_back();

        return;

    }

    vector<vector<int>> combinationSum3(int k, int n) { 
        vector<int> temp;
        vector<vector<int>> ans;
        solve(1, n, k, temp, ans);
        return ans;
    }
};

int main() {

    

    return 0;
}