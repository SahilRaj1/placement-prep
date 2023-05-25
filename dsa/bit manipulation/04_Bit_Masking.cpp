/* TOPIC: Bit Masking */

// QUESTION: https://codeforces.com/blog/entry/73558
// REFERENCE: https://youtu.be/mqCdA8mcJeo

#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;
    vector<int> masks(n, 0);
    for (int k=0; k<n; k++) {
        int no_days;
        cin >> no_days;
        int mask = 0;
        for (int i=0; i<no_days; i++) {
            int day;
            cin >> day;
            mask = (mask | (1 << day));
        }
        masks[k] = mask;
    }

    for (int i=0; i<n; ++i) {
        for (int j=i+1; j<n; ++j) {
            int common_days = (masks[i] & masks[j]);
            int ct_common_days = __builtin_popcount(common_days);
            cout << i << " " << j << " " << ct_common_days << endl;
        }
    }

    return 0;
}