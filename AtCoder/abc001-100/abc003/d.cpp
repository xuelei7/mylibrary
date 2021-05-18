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

const int MAXN = 10010;
long long kai[MAXN+1];
long long inv[MAXN+1];
ll mod = 1e9+7;
long long mp(long long a, long long b) {
    long long res = 1;
    for (; b; b >>= 1) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
    }
    return res;
}

/* do this first */
void init() {
    kai[0] = 1;
    for (long long i = 1; i <= MAXN; i++) kai[i] = kai[i - 1] * i % mod;
    inv[MAXN] = mp(kai[MAXN], mod-2);
    for (long long i = MAXN; i >= 1; i--) inv[i - 1] = inv[i] * i % mod;
}
long long combination(long long n, long long k) {
    if (n < k) return 0;
    return (kai[n] * inv[k]) % mod * inv[n - k] % mod;
}


ll r,c,x,y,d,l;
VV<ll> dp(35,V<ll>(35,-1));

ll f(int h, int w) {
    if (dp[h][w] != -1) return dp[h][w];
    if (d+l > h*w) return 0;

    ll base = combination(h*w, d) * combination(h*w-d, l) % mod;
    rep(hh,1,h+1) {
        rep(ww,1,w+1) {
            if (hh == h && ww == w) continue;
            base -= (f(hh,ww) * (h-hh+1) % mod) * (w-ww+1) % mod;
            base += mod * mod;
            base %= mod;
        }
    }
    return dp[h][w] = base;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    cin >> r >> c >> x >> y >> d >> l;

    init();
    ll ans = (r-x+1)*(c-y+1) % mod;
    cout << (ans * f(x,y)) % mod << endl;
    
    return 0;
}