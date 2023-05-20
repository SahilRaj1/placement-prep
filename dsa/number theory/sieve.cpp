/* TOPIC: Sieve of Eratosthenes */

// TIME COMPLEXITY: O(n log log n)
// SPACE COMPLEXITY: O(N)

// REFERENCE: https://cp-algorithms.com/algebra/sieve-of-eratosthenes.html

#include <bits/stdc++.h>
using namespace std;

const int N = 1e7+10;
vector<bool> isPrime(N, true);

int main() {

    // seive
    isPrime[0] = isPrime[1] = false;
    for (int i=2; i*i<=N; i++) {
        if (isPrime[i]) {
            for (int j=i*i; j<N; j+=i) {
                isPrime[j] = false;
            }
        }
    }

    cout<<isPrime[61]<<endl;

    return 0;
}