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
    
    ll n,m,k;
    cin >> n >> m >> k;
    V<ll> a(n);
    rep(i,0,n) cin >> a[i];

    VV<ll> dp(k,V<ll>(n));
    rep(i,0,n) {
        dp[0][i] = a[i];
    }
    
    rep(i,1,k) {
        deque<ll> id, val;
        rep(j,0,n) {
            dp[i%2][j] = 0;
        }
        rep(j,0,n) {
            while (!id.empty() && id.front() < j - m) {
                id.pop_front();
                val.pop_front();
            }
            while (!val.empty() && val.back() <= dp[(i-1)%2][j]) {
                val.pop_back();
                id.pop_back();
            }
            if (j >= i)
                dp[i%2][j] = val.front() + (i+1) * a[j];
            val.push_back(dp[(i-1)%2][j]);
            id.push_back(j);
        }
    }
    ll ans = 0;
    rep(i,k-1,n) {
        ans = max(ans, dp[(k-1)%2][i]);
    }
    cout << ans << endl;
    return 0;
}