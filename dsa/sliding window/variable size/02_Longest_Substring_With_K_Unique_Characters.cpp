/* TOPIC: Longest Substring With K Unique Characters */

// REFERENCE: https://youtu.be/Lav6St0W_pQ
// QUESTION: https://practice.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestKSubstr(string s, int k) {

        int n = s.length();
        unordered_map<char, int> hsh;
        int i = 0, j = 0, ct = 0, ans = -1;

        while (j < n) {

            hsh[s[j]]++;
            if (hsh[s[j]] == 1) {
                ct++;
            }

            if (ct == k) {
                ans = max(ans, j - i + 1);
            }

            while (ct > k) {
                hsh[s[i]]--;
                if (hsh[s[i]] == 0) {
                    ct--;
                }
                i++;
            }

            j++;

        }

        return ans;

    }
};

int main() {

    

    return 0;
}