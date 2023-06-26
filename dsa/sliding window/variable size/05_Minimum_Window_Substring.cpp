/* TOPIC: Minimum Window Substring */

// REFERENCE: https://youtu.be/iwv1llyN6mo
// QUESTION: https://leetcode.com/problems/minimum-window-substring/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {

        int n = s.length(), m = t.length();
        unordered_map<char, int> hsh;
        string ans;
        for (char &it: t) {
            hsh[it]++;
        }
        
        int i=0, j=0, start=0, end=0, mini=INT_MAX, ct=hsh.size();
        while (j<n) {

            if (hsh.find(s[j]) != hsh.end()) {
                hsh[s[j]]--;
                if (hsh[s[j]] == 0) {
                    ct--;
                }
            }
        
            while (ct == 0) {
                if (j-i+1 < mini) {
                    start = i;
                    end = j;
                    mini = j-i+1;
                }
                if (hsh.find(s[i]) == hsh.end()) {
                    i++;
                } else {
                    hsh[s[i]]++;
                    if (hsh[s[i]] == 1) {
                        ct++;
                    }
                    i++;
                }
            }

            j++;

        }

        if (mini == INT_MAX) {
            return ans;
        }

        for (int k=start; k<=end; k++) {
            ans.push_back(s[k]);
        }

        return ans;
    }
}; 

int main() {

    

    return 0;
}