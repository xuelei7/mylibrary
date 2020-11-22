// Maximum Sum Sequence
// Given a sequence of numbers a1, a2, a3, ..., an, find the maximum sum of a contiguous subsequence of those numbers. Note that, a subsequence of one element is also a contiquous subsequence.

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        if (n == 0) break;
        vector<int> v(n);
        int ans = -1e9;
        for (int i = 0; i < n; i++) cin >> v[i];
        int mi = 0;
        for (int i = 0; i < n; i++) {
            if (i != 0) v[i] += v[i-1];
            ans = max(ans, v[i] - mi);
            mi = min(mi, v[i]);
        }
        cout << ans << endl;
    }
    return 0;
}