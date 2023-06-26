/* TOPIC: Maximum of All Subarrays of Size K */

// REFERENCE: https://youtu.be/xFJXtB5vSmM
// QUESTION: https://leetcode.com/problems/sliding-window-maximum/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        int n = nums.size();
        deque<int> deq;
        vector<int> ans;

        int i = 0, j = 0;

        while (j < n) {

            // processing jth element
            while (!deq.empty() and nums[j] > deq.front()) {
                deq.pop_front();
            }
            while (!deq.empty() and nums[j] > deq.back()) {
                deq.pop_back();
            }
            deq.push_back(nums[j]);

            // increase window size to k
            if (j-i < k-1) {
                j++;
                continue;
            }

            // processing the window of size k
            ans.push_back(deq.front());
            
            // remove proccessing of ith element
            if (nums[i] == deq.front()) {
                deq.pop_front();
            }
            
            // slide window forward
            i++;
            j++;

        }

        return ans;

    }
};

int main() {

    

    return 0;
}