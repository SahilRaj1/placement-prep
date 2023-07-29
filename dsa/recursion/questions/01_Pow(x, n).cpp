/* Sahil Raj */

#include <bits/stdc++.h>
using namespace std;

const int M = 1e9+7;

int solve(int a, int b) {

    if (b == 0) {
        return 1;
    }

    int temp = solve(a, b/2);
    int ans = (temp * temp) % M;

    return b%2 ? (ans * a) % M : ans;

}

int main() {

    

    return 0;
}