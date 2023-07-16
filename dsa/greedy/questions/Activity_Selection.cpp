/* TOPIC: Activity Selection */

// TIME COMPLEXITY: O()
// SPACE COMPLEXITY: O()

// REFERENCE: https://practice.geeksforgeeks.org/problems/activity-selection-1587115620/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    static bool cmp(pair<int, int> &a, pair<int, int> &b) {
        return a.second < b.second;
    }

    int activitySelection(vector<int> start, vector<int> end, int n) {
        
        vector<pair<int, int>> arr(n);
        for (int i=0; i<n; i++) {
            arr[i].first = start[i];
            arr[i].second = end[i];
        }
        
        sort(arr.begin(), arr.end(), cmp);
        int ans = 1, last = arr[0].second;
        for (int i=1; i<n; i++) {
            if (arr[i].first > last) {
                ans++;
                last = arr[i].second;
            }
        }

        return ans;

    }
};

int main() {

    

    return 0;
}