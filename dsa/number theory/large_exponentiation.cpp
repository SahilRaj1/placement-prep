/* TOPIC: Binary Exponentiation */

// TIME COMPLEXITY: O(log^2 n)
// SPACE COMPLEXITY: O(1)

// REFERENCE: https://youtu.be/vz0P_2V0y7M, 

#include <bits/stdc++.h>
using namespace std;

const int M = 1e9+7;

// binary multiplication for large values of 'a' and 'M'
int binMul(long long a, long long b) {
    long long ans = 0;
    while(b) {
        if (b&1) {
            ans = (ans + a) % M;
        }
        a = (a + a) % M;
        b = b>>1;
    }
    return ans;
}

// binary exponentiation for large values of 'a' and 'M' using binMul
int binExp(long long a, long long b) {
    long long ans = 1;
    while (b) {
        if (b&1) {
            ans = binMul(ans, a);
        }
        a = binMul(a, a);
        b = b>>1;
    }
    return ans;
}

int main() {

    int a, b;
    cin>>a>>b;
    cout<<binExp(a, b)<<endl;

    return 0;
}