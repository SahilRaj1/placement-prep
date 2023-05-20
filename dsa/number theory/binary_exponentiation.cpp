/* TOPIC: Binary Exponentiation */

// TIME COMPLEXITY: O(log n)
// SPACE COMPLEXITY: O(1)

// REFERENCE: https://youtu.be/J63JPxqmyzg, https://youtu.be/K8mJ27S72v0

#include <bits/stdc++.h>
using namespace std;

const int M = 1e9+7;

// recursive binary exponentiation
int recursiveBinExp(int a, int b) {
    if (b==0) {
        return 1;
    }
    int res = recursiveBinExp(a, b/2);
    if (b&1) {
        return ((res * 1LL * res) % M * a) % M;
    } else {
        return (res * 1LL * res) % M;
    }
}

// iterative binary exponentiation
int iterativeBinExp(int a, int b) {
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

int main() {

    int a, b;
    cin>>a>>b;
    cout<<recursiveBinExp(a, b)<<endl;
    cout<<iterativeBinExp(a, b)<<endl;

    return 0;
}