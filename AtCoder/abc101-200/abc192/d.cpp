#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string x;
ll m;
bool ok(ll k) {
    ll ret = 0;
    for (auto e:x) {
        if (ret > (m - e + '0') / k) return 0;
        ret = ret * k + e - '0';
    }
    return ret <= m;
}
int main() {
    cin >> x >> m;
    if (x.size() == 1) {
        cout << (x[0] - '0' <= m) << endl;
        return 0;
    }
    int mx = *max_element(x.begin(),x.end()) - '0' + 1;
    ll l = 1, r = m + 1;
    while (l < r) {
        ll mid = l + r >> 1;
        if (ok(mid)) l = mid + 1;
        else r = mid;
        // cout << mid << " " << l << " " << r << endl;
    }
    cout << max(0LL, l - mx) << endl;
    return 0;
}
