// Sum of 4 Integers
// Write a program which reads an integer n and identifies the number of combinations of a,b,c and d (0 ≤ a,b,c,d ≤ 9) which meet the following equality:

// a+b+c+d=n

// For example, for n = 35, we have 4 different combinations of (a,b,c,d): (8,9,9,9), (9,8,9,9), (9,9,8,9), and (9,9,9,8).

// Input
// The input consists of several datasets. Each dataset consists of n (1 ≤ n ≤ 50) in a line. The number of datasets is less than or equal to 50.

// Output
// Print the number of combination in a line.

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        int ans = 0;
        for (int i = 0; i <= 9; i++) {
            for (int j = 0; j <= 9; j++) {
                for (int k = 0; k <= 9; k++) {
                    for (int l = 0; l <= 9; l++) {
                        if (i + j + k + l == n) ans++;
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}