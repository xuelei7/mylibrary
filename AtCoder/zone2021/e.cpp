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
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    // constexpr char endl = '\n';
    
    ll r,c;
    cin >> r >> c;
    VV<ll> a(r, V<ll>(c));
    rep(i,0,r) {
        rep(j,0,c-1) {
            cin >> a[i][j];
        }
    }
    VV<ll> b(r, V<ll>(c));
    rep(i,0,r-1) {
        rep(j,0,c) {
            cin >> b[i][j];
        }
    }
    
    VV<pair<ll,ll>> G(r*c*2);
    rep(i,0,r) {
        rep(j,0,c-1) {
            G[i*c+j].push_back({i*c+j+1,a[i][j]});
            G[i*c+j+1].push_back({i*c+j,a[i][j]});
        }
    }
    rep(i,0,r) {
        rep(j,0,c) {
            if (i < r-1)
                G[i*c+j].push_back({(i+1)*c+j, b[i][j]});
            if (i >= 1) {
                G[i*c+j+r*c].push_back({(i-1)*c+j+r*c, 1});
            }
            G[i*c+j].push_back({i*c+j+r*c, 1});
            G[i*c+j+r*c].push_back({i*c+j, 0});
        }
    }

    // rep(i,0,r*c) {
    //     cout << i/c << " " << i%c << endl;
    //     rep(j,0,G[i].size()) {
    //         cout << " " << G[i][j].first/c << " " << G[i][j].first%c << " " << G[i][j].second << endl;
    //     }
    // }

    ll inf = 1e9;
    V<ll> d(r*c*2, inf);
    d[0] = 0;
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    pq.push({0,0});
    while (!pq.empty()) {
        auto tp = pq.top(); pq.pop();
        if (tp.first > d[tp.second]) continue;
        // cout << tp.second / c << " " << tp.second % c << " " << tp.first << endl;
        rep(i,0,G[tp.second].size()) {
            auto to = G[tp.second][i].first;
            auto cost = G[tp.second][i].second;
            if (d[to] > tp.first + cost) {
                d[to] = tp.first + cost;
                pq.push({d[to], to});
            }
        }
    }
    // rep(i,0,r*c*2) {
    //     cout << i/c << " " << i % c << " " << d[i] << endl;
    // }
    cout << d[r*c-1] << endl;
    return 0;
}