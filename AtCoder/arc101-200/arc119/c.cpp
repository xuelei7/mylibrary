#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (int)(a); (i) < (int)(b); (i)++)
#define rrep(i, a, b) for (int i = (int)(b) - 1; (i) >= (int)(a); (i)--)
#define all(v) v.begin(), v.end()

typedef long long ll;
template <class T> using V = vector<T>;
template <class T> using VV = vector<V<T>>;

/* 提出時これをコメントアウトする */
#define LOCAL true

#ifdef LOCAL
#define dbg(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl
#else
#define dbg(x) true
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    int n;
    cin >> n;
    V<ll> a(n);
    rep(i,0,n) cin >> a[i];

    map<ll,ll> mp;
    ll num = a[0];
    V<ll> b(n);
    b[0] = num;
    mp[num]++;
    rep(i,1,n) {
        if (i & 1) {
            num -= a[i];
        } else {
            num += a[i];
        }
        mp[num]++;
        b[i] = num;
    }
    // rep(i,0,n) {
    //     cout << b[i] << " ";
    // }
    // cout << endl;

    ll ans = 0;
    ll base = 0;
    rep(i,0,n-1) {
        mp[b[i]]--;
        if (mp[b[i]] == 0) mp.erase(b[i]);
        ans += mp[base];
        // cout << base << " " << mp[base] << endl;
        if (i & 1) {
            base -= a[i];
        } else {
            base += a[i];
        }
    }

    cout << ans << endl;
    return 0;
}