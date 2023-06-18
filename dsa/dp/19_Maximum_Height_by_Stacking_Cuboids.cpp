/* TOPIC: Maximum Height by Stacking Cuboids */

// TIME COMPLEXITY: O()
// SPACE COMPLEXITY: O()

// REFERENCE: https://youtu.be/Ntzuz7XsdCI
// QUESTION: https://leetcode.com/problems/maximum-height-by-stacking-cuboids/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool check(vector<int> &base, vector<int> &newBox) {
        for (int i=0; i<3; i++) {
            if (base[i] < newBox[i]) {
                return false;
            }
        }
        return true;
    }

    int LIS(vector<vector<int>>& nums) {

        int n = nums.size();
        
        vector<int> currRow(n+2, 0);
        vector<int> nextRow(n+2, 0);

        for (int curr = n-1; curr>=0; curr--) {
            for (int prev = curr-1; prev>=-1; prev--) {

                int take = 0;
                if (prev == -1 or check(nums[curr], nums[prev])) {
                    take = nums[curr][2] + nextRow[curr + 1];
                }
                int ntake = 0 + nextRow[prev+1];

                currRow[prev+1] = max(take, ntake);

            }
            nextRow = currRow;
        }

        return nextRow[0];

    }

    int maxHeight(vector<vector<int>>& cuboids) {
        
        // 1. sort dimensions of all cuboids
        for (auto &cuboid: cuboids) {
            sort(cuboid.begin(), cuboid.end());
        }

        // 2. sort all cuboids
        sort(cuboids.begin(), cuboids.end());

        // 3. Take height as last dimension and apply LIS logic on it
        return LIS(cuboids);

    }
};

int main() {

    

    return 0;
}