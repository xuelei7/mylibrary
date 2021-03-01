// Integral
// Write a program which computes the area of a shape represented by the following three lines:

// y=x2
// y=0
// x=600

// Input
// The input consists of several datasets. Each dataset consists of an integer d in a line. The number of datasets is less than or equal to 20.

// Output
// For each dataset, print the area s in a line.

#include <bits/stdc++.h>
using namespace std;

int main() {
    int d;
    while (cin >> d) {
        int ans = 0;
        for (int i = 0; i < 600; i+=d) {
            ans += i * i;
        }
        cout << ans * d << endl;
    }
    return 0;
}