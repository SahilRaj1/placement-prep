/* Sahil Raj */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<vector<int>> ans;

    void solve(int i, int n, int k, vector<int>& temp) {

        if (i==n+1) {
            if (temp.size()==k) {
                ans.push_back(temp);
            }
            return;
        }

        // take
        temp.push_back(i);
        solve(i+1, n, k, temp);
        temp.pop_back();

        // not take
        solve(i+1, n, k, temp);

    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        solve(1, n, k, temp);
        return ans;
    }
};

int main() {

    

    return 0;
}