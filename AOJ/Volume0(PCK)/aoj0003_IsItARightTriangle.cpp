// Is it a Right Triangle?
// Write a program which judges wheather given length of three side form a right triangle. Print "YES" if the given sides (integers) form a right triangle, "NO" if not so.

// Input
// Input consists of several data sets. In the first line, the number of data set, N is given. Then, N lines follow, each line corresponds to a data set. A data set consists of three integers separated by a single space.

// Constraints
// 1 ≤ length of the side ≤ 1,000
// N ≤ 1,000
// Output
// For each data set, print "YES" or "NO".

// to geometry
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (b > a) swap(a,b);
        if (c > a) swap(a,c);
        if (a * a == b * b + c * c) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}