/* TOPIC: Fruit Into Baskets (OR) Pick Toys*/

// REFERENCE: https://youtu.be/seOKHXB_w74
// QUESTION: https://leetcode.com/problems/fruit-into-baskets/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        int n = fruits.size();
        unordered_map<int, int> hsh;

        int i = 0, j = 0, ct = 0, ans = 0;
        while (j < n) {

            hsh[fruits[j]]++;
            if (hsh[fruits[j]] == 1) {
                ct++;
            }

            if (ct <= 2) {
                ans = max(ans, j-i+1);
            }

            while (ct > 2) {
                hsh[fruits[i]]--;
                if (hsh[fruits[i]] == 0) {
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