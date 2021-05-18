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
    
    ll h,w;
    cin >> h >> w;
    VV<char> maze(h, V<char>(w));
    rep(i,0,h) rep(j,0,w) cin >> maze[i][j];

    VV<ll> dp(h, V<ll>(w));
    V<VV<ll>> dpp(3, VV<ll>(h, V<ll>(w)));
    ll mod = 1e9+7;

    dp[0][0] = 1;
    rep(i,0,h) {
        rep(j,0,w) {
            if (maze[i][j] == '#') continue;
            if (i != 0) {
                dp[i][j] += dpp[0][i-1][j];
                dp[i][j] %= mod;
            }
            if (j != 0) {
                dp[i][j] += dpp[1][i][j-1];
                dp[i][j] %= mod;
            }
            if (i != 0 && j != 0) {
                dp[i][j] += dpp[2][i-1][j-1];
                dp[i][j] %= mod;
            }
            rep(k,0,3) dpp[k][i][j] = dp[i][j];
            if (i != 0) {
                dpp[0][i][j] += dpp[0][i-1][j];
                dpp[0][i][j] %= mod;
            }
            if (j != 0) {
                dpp[1][i][j] += dpp[1][i][j-1];
                dpp[1][i][j] %= mod;
            }
            if (i != 0 && j != 0) {
                dpp[2][i][j] += dpp[2][i-1][j-1];
                dpp[2][i][j] %= mod;
            }
        }
    }    
    cout << dp[h-1][w-1] << endl;
    return 0;
}