/* TOPIC: Longest Substring Without Repeating Characters */

// REFERENCE: https://youtu.be/L6cffskouPQ
// QUESTION: https://leetcode.com/problems/longest-substring-without-repeating-characters/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n = s.length();
        unordered_map<char, int> hsh;
        
        int i = 0, j = 0, ct = 0, ans = 0;
        while (j < n) {
            
            hsh[s[j]]++;
            if (hsh[s[j]] == 1) {
                ct++;
            }

            if (ct == j-i+1) {
                ans = max(ans, j - i + 1);
            }

            while (ct < j-i+1) {
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