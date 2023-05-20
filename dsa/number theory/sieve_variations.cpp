/* TOPIC: Sieve Variations */

// TIME COMPLEXITY: O(n log log n)
// SPACE COMPLEXITY: O(N)

// REFERENCE: https://cp-algorithms.com/algebra/sieve-of-eratosthenes.html

#include <bits/stdc++.h>
using namespace std;

const int N = 1e7+10;
vector<bool> isPrime(N, true);
vector<int> lowestPrime(N, 0);
vector<int> highestPrime(N);

int main() {

    int n;
    cin>>n;

    /* higest and lowest prime factors */
    isPrime[0] = isPrime[1] = false;
    for (int i=2; i<N; i++) {
        if (isPrime[i]) {
            lowestPrime[i] = highestPrime[i] = i; // lowest and higest prime factor of a prime number is itself
            for (int j=2*i; j<N; j+=i) {
                isPrime[j] = false;
                highestPrime[j] = i; // highest prime gets updated everytime it is encountered for a prime
                if (lowestPrime[j]==0) {
                    lowestPrime[j] = i; // lowest prime updated only first time
                }
            }
        }
    }
    cout<<lowestPrime[n]<<" "<<highestPrime[n]<<endl;

    /* prime factorization */
    unordered_map<int, int> primeFactors;
    while (n>1) {
        int pf = lowestPrime[n];
        while(n%pf == 0) {
            primeFactors[pf]++;
            n /= pf;
        }
    }
    for (auto &pf: primeFactors) {
        cout<<pf.first<<":"<<pf.second<<" ";
    } cout<<endl;

    return 0;
}