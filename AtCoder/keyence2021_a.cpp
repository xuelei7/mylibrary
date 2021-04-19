#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200010], b[200010];
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    ll ma = 0, m = 0;
    for (int i = 0; i < n; i++) {
        ma = max(ma, a[i]);
        if (b[i] * ma > m) m = b[i] * ma;
        cout << m << endl;
    }
    return 0;
}