/* Sahil Raj */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool solve(string s, int i, int j) {
        if (i>=j) {
            return true;
        }
        if (s[i]!=s[j]) {
            return false;
        }
        return solve(s, i+1, j-1);
    }

    bool isPalindrome(string s) {
        string s1 = "";
        for (auto &it: s) {
            if ((it>='a' and it<='z') or (it>='A' and it<='Z') or (it>='0' and it<='9')) {
                s1.push_back((it | ' '));
            }
        }
        int n = s1.size();
        return solve(s1, 0, n-1);
    }
};

int main() {

    

    return 0;
}