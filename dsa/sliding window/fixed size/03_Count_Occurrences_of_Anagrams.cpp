/* TOPIC: Count Occurrences of Anagrams */

// REFERENCE: https://youtu.be/MW4lJ8Y0xXk
// QUESTION: https://practice.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
	int search(string pat, string txt) {

        int n = txt.length(), k = pat.length();

        unordered_map<char, int> hsh;
        for (auto &it: pat) {
            hsh[it]++;
        }

        int i = 0, j = 0, size = hsh.size(), ans = 0;

        while (j < n) {

            // increase window size to k
            if (j-i < k-1) {
                if (hsh.find(txt[j]) != hsh.end()) {
                    hsh[txt[j]]--;
                    if (hsh[txt[j]] == 0) {
                        size--;
                    }
                }
                j++;
                continue;
            }

            // processing the window of size k
            if (hsh.find(txt[j]) != hsh.end()) {
                hsh[txt[j]]--;
                if (hsh[txt[j]] == 0) {
                    size--;
                }
            }

            if (size == 0) {
                ans++;
            }

            // remove proccessing of ith element
            if (hsh.find(txt[i]) != hsh.end()) {
                hsh[txt[i]]++;
                if (hsh[txt[i]] == 1) {
                    size++;
                }
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