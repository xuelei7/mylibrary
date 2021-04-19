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

auto solve () -> void {
    int n,m,p;
    cin >> m >> n >> p;
    int inf = 1e9;
    VV<int> dist(m+n, V<int>(m+n, inf));
    rep(i,0,m+n) {
        string s;
        cin >> s;
        rep(j,0,m+n) {
            if (s[j] == 'Y') {
                dist[i][j] = 0;
            }
        }
    }


    bool changed = 1;
    int step = 0;
    while (changed) {
        step++;
        changed = 0;

        vector<pair<int,int>> v;
        rep(i,0,m) {
            rep(j,0,m+n) {
                if (dist[i][j] == inf) continue;
                if (i == j) continue;
                rep(k,j+1,m+n) {
                    if (i == k) continue;
                    if (dist[i][k] == inf) continue;
                    if (dist[j][k] != inf) continue;

                    v.push_back({j,k});
                    changed = 1;
                }
            }
        }

        for (auto e: v) {
            dist[e.first][e.second] = dist[e.second][e.first] = step;
        }
    }



    rep(i,0,p) {
        int a,b;
        cin >> a >> b;
        a--; b--;
        if (dist[a][b] == inf) {
            cout << " -1";
        } else {
            cout << " " << dist[a][b];
        }
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    int t;
    cin >> t;
    rep(i,1,t+1) {
        cout << "Case #" << i << ":";
        solve();
    }
    
    return 0;
}