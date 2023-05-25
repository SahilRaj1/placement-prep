/* TOPIC: XOR */

// REFERENCE: https://youtu.be/SFOlkUnjtA4

// x^x = 0
// x^0 = x

#include <bits/stdc++.h>
using namespace std;

int main() {

    // swapping two numbers
    int a = 4, b = 5;
    cout << a << " " << b << endl;
    a = a ^ b;
    b = b ^ a; // b^a --> b^(a^b)
    a = a ^ b; // a^b --> (a^b)^a
    cout << a << " " << b << endl;

    // odd one out or missing number from duplicates array
    int n;
    cin>>n;
    vector<int> arr(n);
    for (int i=0; i<n; i++) {
        cin>>arr[i];
    }
    int ans=0;
    for (int &it: arr) {
        ans = ans^it;
    }
    cout<<ans<<endl;

    return 0;
}