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

int n;
V<pair<ll,ll>> G[200010];
ll cnt[200010];
ll ans = 0;
ll mod =1e9+7;
V<bool> used(200010);

void dfs(int k, ll num, ll e, V<ll> digit) {
    used[k] = 1;


    ll new_sum = 0;
    // new digit
    rep(i,0,60) {
        if ((e>>i)&1) {
            digit[i] = (num - digit[i]);
        }
    }
    // add e
    rep(i,0,60) {
        if ((e>>i)&1) {
            digit[i]++;
        }
    }
    num++;
    // new sum
    rep(i,0,60) {
        new_sum = (new_sum + (1LL << i) * digit[i] % mod) % mod;
    }

    ans += new_sum;
    ans %= mod;

#ifdef LOCAL
    cout << k << " " << num << " " << e << " " << new_sum << endl;
    rrep(i,0,6) {
        cout << digit[i];
    }
    cout << endl;
#endif
    rep(i,0,G[k].size()) {
        if (used[G[k][i].first]) continue;
        dfs(G[k][i].first, num, G[k][i].second, digit);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    cin >> n;
    rep(i,0,n-1) {
        ll a,b,c;
        cin >> a >> b >> c;
        a--; b--;
        G[a].push_back({b,c});
        G[b].push_back({a,c});
        cnt[a]++;
        cnt[b]++;
    }

    int s;
    rep(i,0,n) {
        if (cnt[i] == 1) {
            s = i;
            break;
        }
    }

    V<ll> digit(65,0);
    dfs(s, -1, 0, digit);
    cout << ans % mod << endl;
    return 0;
}