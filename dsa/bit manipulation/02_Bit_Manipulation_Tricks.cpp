/* TOPIC: ^ Bit Manipulation Tricks */

// REFERENCE: https://youtu.be/XjtYsFjXtoE

#include <bits/stdc++.h>
using namespace std;

void printBinary(int num) {
    for (int i = 10; i >= 0; --i) {
        cout << ((num >> i) & 1);
    } cout<<endl;
}

int main() {

    int n;
    cin >> n;

    // 1. Odd Even Check
    if ((n & 1) == 0) {
        cout << "even\n";
    } else {
        cout << "odd\n";
    }


    // 2. Multiply/Divide by 2
    cout << (n >> 1) << endl;
    cout << (n << 1) << endl;


    // 3. Uppercase/Lowercase conversion
    char A = 'A';
    cout << A << " ";
    printBinary((int)A);
    char a = A | (1 << 5);
    cout << a << " ";
    printBinary((int)a);

    char b = 'b';
    cout << b << " ";
    printBinary((int)b);
    char B = b & ~(1 << 5);
    cout << B << " ";
    printBinary((int)B);

    char c = 'c';
    cout << c << " ";
    printBinary((int)c);
    char C = c ^ (1 << 5);
    cout << C << " ";
    printBinary((int)C);

    A = 'A';
    cout << A << " ";
    printBinary((int)A);
    a = A | ' ';
    cout << a << " ";
    printBinary((int)a);

    b = 'b';
    cout << b << " ";
    printBinary((int)b);
    B = b & '_';
    cout << B << " ";
    printBinary((int)B);


    // 4. Clear LSBs
    printBinary(59);
    n = 59;
    int i = 4;
    /*
        00000111011 -> 00000100000
        11111100000
        00000011111
        00000100000 - 1
        1<<(i+1)
    */
    printBinary(n & ~((1 << (i + 1)) - 1));


    // 5. Clear MSBs
    printBinary(59);
    n = 59;
    i = 3;
    /*
        00000111011 -> 00000001011
        00000001111
        00000010000 - 1
        1<<(i+1)
    */
    printBinary(n & ((1 << (i + 1)) - 1));


    // 6. Power of 2 check
    n = 16;
    /*
        n   = 10000
        n-1 = 01111
    */
    if (n & (n - 1)) {
        cout << "Not a power of 2\n";
    } else {
        cout << "Power of 2\n";
    }

    return 0;
}