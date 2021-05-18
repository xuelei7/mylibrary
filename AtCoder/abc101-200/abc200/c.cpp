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
    
    ll n;
    cin >> n;
    V<ll> a(n);
    rep(i,0,n) cin >> a[i];

    V<ll> cnt(210);
    rep(i,0,n) {
        cnt[a[i] % 200]++;
    }

    ll ans = 0;
    rep(i,0,200) {
        ll k = cnt[i];
        ans += k * (k - 1) / 2;
    }
    cout << ans << endl;
    
    return 0;
}