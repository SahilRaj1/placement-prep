/* TOPIC: Euclidean Algorithm */

// TIME COMPLEXITY: O(log(min(a,b)))
// SPACE COMPLEXITY: O(1)

// REFERENCE: https://youtu.be/utZcJ0leZ_g?list=PLauivoElc3giVROwL-6g9hO-LlSen_NaV

#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if (b==0) {
        return a;
    }
    gcd(b, a%b);
}

int iterativeGcd(int a, int b) {
    while (b) {
        a = a%b;
        swap(a, b);
    }
    return a;
}

int lcm(int a, int b) {
    return a*b/gcd(a, b);
}

int main() {

    int a, b;
    cin>>a>>b;
    cout<<gcd(a, b)<<endl;
    cout<<iterativeGcd(a, b)<<endl;
    cout<<lcm(a, b)<<endl;

    return 0;
}