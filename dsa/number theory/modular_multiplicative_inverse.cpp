/* TOPIC: Modular Multiplicative Inverse */

// TIME COMPLEXITY: O(logn)
// SPACE COMPLEXITY: O(1)

// REFERENCE: https://youtu.be/Gd9w8m-klho

// MMI(X)=X^-1 is a number between 0 and M such that (X * MMI(X)) % M = 1.
// MMI(X) can exist if and only if X and M are co-primes.

/* Finding X^-1 using Fermat Little Theorem */
// (X^(M-1)) % M = 1 ; if 'M is a prime number' and 'X is not a multiple of M'. (Fermat Theorem)
// multiplying X^-1 on both sides we get,
// (X^(M-2)) % M = X^-1  =>  MMI(X) = X^-1 = (X^(M-2)) % M
// (X^(M-2)) % M can be calculated optimally using binary exponentiation => binExp(X, M-2, M);
// If 'M is not prime' then can use Extended Euclid's Algorithm to get a co-prime.

#include <bits/stdc++.h>
using namespace std;

const int m = 1e9+7;

int binExp(int a, int b, int m) {
    int ans = 1;
    while(b) {
        if (b&1) {
            ans = (ans * 1LL * a) % m;
        }
        a = (a * 1LL * a) % m;
        b = b >> 1;
    }
    return ans;
}

int main() {

    int n;
    cin>>n;
    cout<<binExp(n, m-2, m)<<endl;

    return 0;
}