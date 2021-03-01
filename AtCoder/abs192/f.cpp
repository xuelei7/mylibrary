#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,x,a[110];
ll mx[11][110];
int main() {
    cin >> n >> x;
    for (int i = 0; i < n; i++) cin >> a[i];
    ll ans = x;
    for (int i = 0; i < n; i++) ans = min(ans, x - a[i]);
    for (int mod = 2; mod <= n; mod++) {
        for (int i = 0; i < 11; i++) memset(mx[i],0,sizeof(mx[i]));
        for (int i = 0; i < 10; i++) {
            ll frm = i * 10;
            ll num = max(0LL,min(n-frm,10LL));
            for (int j = 0; j < (1 << num); j++) {
                ll sum = 0, cnt = 0;
                for (int k = 0; k < num; k++) {
                    if ((j >> k) & 1) {
                        sum += a[frm + k];
                        sum %= mod;
                        cnt++;
                    }
                }
                mx[i][sum] = max(mx[i][sum], cnt);
            }
        }
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < mod; j++) {
                cout << mx[i][j] << " ";
            }
            cout << endl;
        }
        cout << "---" << endl;
        for (int i = 0; i < 9; i++) {
            ll tmp[110] = {};
            for (int j = 0; j < mod; j++) {
                tmp[j] = max(tmp[j],mx[i][j]);
                tmp[j] = max(tmp[j],mx[i+1][j]);
                for (int k = 0; k < mod; k++) {
                    if (mx[i][j] != 0 && mx[i+1][k] != 0)
                        tmp[(j+k)%mod] = max(tmp[(j+k)%mod], mx[i][j] + mx[i+1][k]);
                }
            }
            for (int j = 0; j < mod; j++) mx[i+1][j] = tmp[j];
        }
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < mod; j++) {
                cout << mx[i][j] << " ";
            }
            cout << endl;
        }
        ll md = x % mod;
        if (mx[10][md] == 0) continue;
        ans = min(ans, x / mx[10][md]);
    }
    cout << ans << endl;
    return 0;
}