// Slimming Plan
// Chokudai loves eating so much. However, his doctor Akensho told him that he was overweight, so he finally decided to lose his weight.

// Chokudai made a slimming plan of a D-day cycle. It is represented by D integers w0,...,wD−1. His weight is S on the 0-th day of the plan and he aims to reduce it to T (S>T). If his weight on the i-th day of the plan is x, it will be x+wi%D on the (i+1)-th day. Note that i%D is the remainder obtained by dividing i by D. If his weight successfully gets less than or equal to T, he will stop slimming immediately.

// If his slimming plan takes too many days or even does not end forever, he should reconsider it.

// Determine whether it ends or not, and report how many days it takes if it ends.

// Input
// The input consists of a single test case formatted as follows.

// S T D
// w0...wD−1
// The first line consists of three integers S, T, D (1≤S,T,D≤100,000,S>T). The second line consists of D integers w0,...,wD−1 (−100,000≤wi≤100,000 for each i).

// Output
// If Chokudai's slimming plan ends on the d-th day, print d in one line. If it never ends, print −1.

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll s,t,d;
ll dw[100010];
ll min_d;
int main() {
    cin >> s >> t >> d;
    for (int i = 0; i < d; i++) {
        cin >> dw[i];
        if (i != 0) dw[i] += dw[i-1];
        min_d = min(min_d,dw[i]);
    }
    if (s + min_d > t && dw[d-1] >= 0) {
        cout << -1 << endl;
        return 0;
    }
    ll ans = 0;
    while (1) {
        if (s + min_d <= t) break;
        s += dw[d-1];
        ans += d;
    }
    for (int i = 0; i < d; i++) {
        if (s + dw[i] <= t) {
            cout << ans + i + 1 << endl;
            return 0;
        }
    }
    return 0;
}