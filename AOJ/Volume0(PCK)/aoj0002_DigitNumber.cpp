// Digit Number
// Write a program which computes the digit number of sum of two integers a and b.

// Input
// There are several test cases. Each test case consists of two non-negative integers a and b which are separeted by a space in a line. The input terminates with EOF.

// Constraints
// 0 ≤ a, b ≤ 1,000,000
// The number of datasets ≤ 200
// Output
// Print the number of digits of a + b for each data set.

// to utils

#include <bits/stdc++.h>
using namespace std;

int main() {
    int a,b;
    while (cin >> a >> b) {
        int c = a + b;
        if (c == 0) {
            cout << 1 << endl;
            continue;
        }
        int cnt = 0;
        while (c > 0) {
            c /= 10;
            cnt++;
        }
        cout << cnt << endl;
    }

    return 0;
}