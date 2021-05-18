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
    VV<ll> a(n,V<ll>(5));
    rep(i,0,n) {
        rep(j,0,5) cin >> a[i][j];
    }
    V<ll> mx(1<<5);

    rep(i,0,n) {
        rep(j,0,(1<<5)) {
            ll mi = 1e9+7;
            rep(k,0,5) {
                if ((j>>k)&1) {
                    mi = min(mi, a[i][k]);
                }
            }
            mx[j] = max(mx[j], mi);
        }
    }

    ll pow = 3*3*3*3*3;
    ll ans = 0;
    rep(i,0,pow) {
        int num[3] = {};
        int tmp = i;
        rep(j,0,5) {
            num[tmp%3] += (1<<j);
            tmp /= 3;
        }
        ans = max(ans, min({mx[num[0]], mx[num[1]], mx[num[2]]}));
    }

    cout << ans << endl;
    return 0;
}