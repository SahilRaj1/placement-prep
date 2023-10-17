/* TOPIC: Largest Subarray of Sum K */

// REFERENCE: https://youtu.be/cyu_nuW5utA
// QUESTION: https://leetcode.com/problems/subarray-sum-equals-k/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        
        int n = arr.size();
        if (n == 1) {
            return arr[0] == k;
        }

        int i = 0, j = 0, sum = 0, ans = 0;

        while (j < n) {

            sum += arr[j];

            // checking condition and calculating window size
            if (sum == k) {
                ans = max(ans, j-i+1);
            }

            // remove proccessing of ith element
            while (sum > k) {
                sum -= arr[i];
                i++;
                if (sum == k) {
                    ans = max(ans, j-i+1);
                }
            }

            // increase window size
            j++;

        }

        return ans;
        
    }
};

int main() {

    

    return 0;
}