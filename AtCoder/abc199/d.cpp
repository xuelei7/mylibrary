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
    
    int n,m;
    cin >> n >> m;
    VV<bool> G(n, V<bool> (n));
    rep(i,0,m) {
        int a,b;
        cin >> a >> b;
        a--; b--;
        G[a][b] = G[b][a] = 1;
    }

    V<int> color(n);
    V<int> v;
    auto dfs = [&](auto self, int k, int N) -> ll {
        if (k == N) {
            // rep(i,0,n) {
            //     cout << color[i] << " ";
            // }
            // cout << endl;
            return 1;
        }
        int ret = 0;
        rep(i,0,3) {
            bool ok = 1;
            rep(j,0,k) {
                if (G[v[k]][v[j]] && color[v[j]] == i) {
                    ok = 0;
                    break;
                }
            }
            if (ok) {
                color[v[k]] = i;
                ret += self(self, k+1, N);
            }
        }
        return ret;
    };

    V<bool> used(n);
    auto f = [&](auto self, int k) -> void {
        used[k] = 1;
        v.push_back(k);
        rep(i,0,n) {
            if (used[i]) continue;
            if (G[k][i]) {
                self(self, i);
            }
        }
    };
    ll ret = 1;
    rep(i,0,n) {
        if (!used[i]) {
            v.clear();
            f(f,i);
            ret *= dfs(dfs,0,v.size());
        }
    }
    cout << ret << endl;    
    return 0;
}