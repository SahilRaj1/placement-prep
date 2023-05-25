/* TOPIC: Bits Basics */

// REFERENCE: https://youtu.be/yEa0vkjJSf0

#include <bits/stdc++.h>
using namespace std;

void printBinary(int num) {
    for (int i = 10; i >= 0; --i) {
        cout << ((num >> i) & 1);
    } cout<<endl;
}

int main() {

    int a = 9;
    int i = 3;
    printBinary(1 << i);

    // Check if ith bit is set or unset
    if ((a & (1 << i)) != 0) {
        cout << "Set bit" << endl;
    } else {
        cout << "Unset bit" << endl;
    }

     // set a bit
    cout << "Set 2nd bit: ";
    printBinary(a | (1 << 2));

    // unset a bit
    cout << "Unset 3rd bit: ";
    printBinary(a & ~(1 << 3));

    // toggle a bit
    cout << "Toggle 1st bit: ";
    printBinary(a ^ (1 << 1));

    // count set bits
    int ct = 0;
    cout << "No. of set bits: ";
    for (int j=31; j>=0; j--) {
        if ((a & (1 << j)) != 0) {
            ct++;
        }
    }
    cout << ct << endl;

    // using built in method to find set bits
    cout << "No. of set bits (int): "<< __builtin_popcount(a)<<endl;
    cout << "No. of set bits (long long): "<< __builtin_popcountll(1LL<<35)<<endl;

    return 0;
}