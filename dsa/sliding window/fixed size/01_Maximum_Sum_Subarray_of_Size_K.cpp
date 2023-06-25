/* TOPIC: Maximum Sum Subarray of Size K */

// REFERENCE: https://youtu.be/KtpqeN0Goro
// QUESTION: https://practice.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1

#include <bits/stdc++.h>
using namespace std;

class Solution{   
public:
    long maximumSumSubarray(int k, vector<int> &arr , int n){
        
        int i = 0, j = 0;
        long sum = 0, ans = 0;

        while (j < n) {

            // increase window size to k
            if (j-i < k-1) {
                sum += arr[j] + 0L;
                j++;
                continue;
            }

            // processing the window of size k
            sum += arr[j] + 0L;
            ans = max(ans, sum);
            
            // remove proccessing of ith element
            sum -= arr[i];

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