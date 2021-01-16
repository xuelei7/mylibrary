#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k;
ll cnt[300010];
int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        cnt[x]++;
    }
    ll mi = k;
    ll ans = 0;
    for (ll i = 0; i < n; i++) {
        if (cnt[i] < mi) {
            ans += (mi - cnt[i]) * i;
            mi = cnt[i];
        }
    }
    cout << ans << endl;
    return 0;
}