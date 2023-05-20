/* TOPIC: Fermat's Primality Test  */

// TIME COMPLEXITY: O()
// SPACE COMPLEXITY: O()

// REFERENCE: https://youtu.be/sDrXeCs3ghQ

// used to check whether a number is prime or not.
// according to the test, if a number(p) is prime then,
// (a^p)-a is a multiple of p; for all 1 <= a < p.
// ((a^p) - a) % m = 0
// optimally calculate a^p using binary exponentiation

#include <bits/stdc++.h>
using namespace std;

const int M = 1e9+7;

int binExp(int a, int b) {
    int ans = 1;
    while(b) {
        if (b&1) {
            ans = (ans * 1LL * a) % M;
        }
        a = (a * 1LL * a) % M;
        b = b >> 1;
    }
    return ans;
}

bool isPrime(int n) {
    for (int a=1; a<n; a++) {
        if ((binExp(a, n)-a)%n != 0) {
            return false;
        }
    }
    return true;
}

int main() {

    int n;
    cin>>n;
    cout<<isPrime(n)<<endl;

    return 0;
}