// GCD and LCM
// Write a program which computes the greatest common divisor (GCD) and the least common multiple (LCM) of given a and b.

// Input
// Input consists of several data sets. Each data set contains a and b separated by a single space in a line. The input terminates with EOF.

// Constraints
// 0 < a,b ≤ 2,000,000,000
// LCM(a,b) ≤ 2,000,000,000
// The number of data sets ≤ 50
// Output
// For each data set, print GCD and LCM separated by a single space in a line.

// to number

#include <bits/stdc++.h>
using namespace std;

int main() {
    long long a,b;
    while (cin >> a >> b) {
        long long gcd = __gcd(a,b);
        cout << gcd << " " << a / gcd * b << endl;
    }

}