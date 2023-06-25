/* TOPIC: First Negative Number in Every Window of Size K */

// REFERENCE: https://youtu.be/uUXXEgK2Jh8
// QUESTION: https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1

#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long arr[], long long n, long long k) {

    vector<long long> ans;
    queue<long long> q;

    long long i = 0, j = 0;

    while (j < n) {

        // increase window size to k
        if (j-i < k-1) {
            if (arr[j] < 0) {
                q.push(arr[j]);
            }
            j++;
            continue;
        }

        // processing the window of size k
        if (arr[j] < 0) {
            q.push(arr[j]);
        }
        if (!q.empty()) {
            ans.push_back(q.front());
        } else {
            ans.push_back(0);
        }

        // remove proccessing of ith element
        if (arr[i] == q.front()) {
            q.pop();
        }

        // slide window forward
        i++;
        j++;

    }

    return ans;

}

int main() {

    

    return 0;
}