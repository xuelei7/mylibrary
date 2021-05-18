#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (int)(a); (i) < (int)(b); (i)++)
#define rrep(i, a, b) for (int i = (int)(b) - 1; (i) >= (int)(a); (i)--)
#define all(v) v.begin(), v.end()

typedef long long ll;
template <class T> using V = vector<T>;
template <class T> using VV = vector<V<T>>;

/* 提出時これをコメントアウトする */
// #define LOCAL true

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
    V<ll> a(n),t(n);
    ll sum = 0;
    ll mi = -1e18, mx = 1e18;
    rep(i,0,n) {
        cin >> a[i] >> t[i];
        if (t[i] == 1) {
            sum += a[i];
            mi += a[i];
            mx += a[i];
        }
        if (t[i] == 2) {
            mi = max(mi, a[i]);
            if (mi > mx) mx = mi;
        }
        if (t[i] == 3) {
            mx = min(mx, a[i]);
            if (mx < mi) mi = mx;
        }
    }

    int q;
    cin >> q;
    rep(i,0,q) {
        ll x;
        cin >> x;
        x += sum;
        if (x >= mi && x <= mx) {
            cout << x << endl;
        } else {
            cout << (x > mx ? mx: mi) << endl;
        }
    }
    
    return 0;
}