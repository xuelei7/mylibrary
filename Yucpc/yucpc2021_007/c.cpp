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
    
    ll n,m,x;
    cin >> n >> m >> x;
    V<ll> c(n);
    VV<ll> a(n, V<ll>(m));
    rep(i,0,n) {
        cin >> c[i];
        rep(j,0,m) {
            cin >> a[i][j];
        }
    }

    ll ans = 1e9;
    rep(i,0,(1<<n)) {
        V<ll> sum(m);
        ll c_sum = 0;
        rep(j,0,n) {
            if (!((i>>j)&1)) continue;
            c_sum += c[j];
            rep(k,0,m) {
                sum[k] += a[j][k];
            }
        }
        bool f = 1;
        rep(j,0,m) {
            if (sum[j] < x) f = 0;
        }
        if (f) ans = min(ans, c_sum);
    }

    if (ans == 1e9) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
    return 0;
}