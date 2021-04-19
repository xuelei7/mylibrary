// Circles Intersection
// You are given circle 
// A with radius ra and with central coordinate (xa,ya) and circle B with radius rb and with central coordinate (xb,yb).

// Write a program which prints:

// "2" if B is in A,
// "-2" if A is in B,
// "1" if circumference of A and B intersect, and
// "0" if A and B do not overlap.
// You may assume that A and B are not identical.

// Input
// The input consists of multiple datasets. The first line consists of an integer 
// N (N≤50), the number of datasets. There will be N lines where each line represents each dataset. Each data set consists of real numbers:

// xa ya ra xb yb rb

// Output
// For each dataset, print 2, -2, 1, or 0 in a line.

// to geometry

#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-10;
int main() {
    int n;
    cin >> n;
    while (n--) {
        double xa,ya,ra,xb,yb,rb;
        cin >> xa >> ya >> ra >> xb >> yb >> rb;
        // 交叉
        if (sqrt((xa-xb)*(xa-xb)+(ya-yb)*(ya-yb)) >= max(ra,rb) - min(ra,rb) && sqrt((xa-xb)*(xa-xb)+(ya-yb)*(ya-yb)) <= ra + rb) {
            cout << 1 << endl;
            continue;
        }
        // 外部
        if (sqrt((xa-xb)*(xa-xb)+(ya-yb)*(ya-yb)) - ra - rb > -EPS) {
            cout << 0 << endl;
            continue;
        }
        // 内部
        if (rb < ra) cout << 2 << endl;
        else cout << -2 << endl;
    }
    return 0;
}