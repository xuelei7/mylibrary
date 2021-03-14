// Problem Statement
// You are now participating in the Summer Training Camp for Programming Contests with your friend Jiro, who is an enthusiast of the ramen chain SIRO. Since every SIRO restaurant has its own tasteful ramen, he wants to try them at as many different restaurants as possible in the night. He doesn't have plenty of time tonight, however, because he has to get up early in the morning tomorrow to join a training session. So he asked you to find the maximum number of different restaurants to which he would be able to go to eat ramen in the limited time.

// There are $n$ railway stations in the city, which are numbered $1$ through $n$. The station $s$ is the nearest to the camp venue. $m$ pairs of stations are directly connected by the railway: you can move between the stations $a_i$ and $b_i$ in $c_i$ minutes in the both directions. Among the stations, there are $l$ stations where a SIRO restaurant is located nearby. There is at most one SIRO restaurant around each of the stations, and there are no restaurants near the station $s$. It takes $e_i$ minutes for Jiro to eat ramen at the restaurant near the station $j_i$.

// It takes only a negligibly short time to go back and forth between a station and its nearby SIRO restaurant. You can also assume that Jiro doesn't have to wait for the ramen to be served in the restaurants.

// Jiro is now at the station $s$ and have to come back to the station in $t$ minutes. How many different SIRO's can he taste?

// Input
// The input is a sequence of datasets. The number of the datasets does not exceed $100$. Each dataset is formatted as follows:

// $n$ $m$ $l$ $s$ $t$
// $a_1$ $b_1$ $c_1$
// :
// :
// $a_m$ $b_m$ $c_m$
// $j_1$ $e_1$
// :
// :
// $j_l$ $e_l$
// The first line of each dataset contains five integers:

// $n$ for the number of stations,

// $m$ for the number of directly connected pairs of stations,

// $l$ for the number of SIRO restaurants,

// $s$ for the starting-point station, and

// $t$ for the time limit for Jiro.

// Each of the following $m$ lines contains three integers:

// $a_i$ and $b_i$ for the connected stations, and

// $c_i$ for the time it takes to move between the two stations.

// Each of the following $l$ lines contains two integers:

// $j_i$ for the station where a SIRO restaurant is located, and

// $e_i$ for the time it takes for Jiro to eat at the restaurant.

// The end of the input is indicated by a line with five zeros, which is not included in the datasets.

// The datasets satisfy the following constraints:

// $2 \le n \le 300$

// $1 \le m \le 5{,}000$

// $1 \le l \le 16$

// $1 \le s \le n$

// $1 \le t \le 100{,}000$

// $1 \le a_i, b_i \le n$

// $1 \le c_i \le 1{,}000$

// $1 \le j_i \le n$

// $1 \le e_i \le 15$

// $s \ne j_i$

// $j_i$'s are distinct.

// $a_i \ne b_i$

// $(a_i, b_i) \ne (a_j, b_j)$ and $(a_i, b_i) \ne (b_j, a_j)$ for any $i \ne j$

// Note that there may be some stations not reachable from the starting point $s$.

// Output
// For each data set, output the maximum number of different restaurants where Jiro can go within the time limit.

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

auto solve (int N, int L, int S, ll T, VV<pair<int,ll>>& G, V<pair<int,ll>>& E, V<int>& jiroid) -> int {
    // find min distance between jiros
    VV<ll> dist(N,V<ll>(N,1e18));
    rep(i,0,N) dist[i][i] = 0;
    rep(i,0,N) {
        rep(j,0,G[i].size()) {
            dist[i][G[i][j].first] = G[i][j].second;
        }
    }

    rep(k,0,N) {
        rep(i,0,N) {
            rep(j,0,N) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    VV<ll> dp((1<<L),V<ll>(L,1e18));
    int ret = 0;
    rep(i,0,L) {
        dp[1<<i][i] = dist[S][E[i].first] + E[i].second;
    }
    rep(i,0,(1<<L)) {
        rep(j,0,L) {
            if (!(i>>j)&1) continue;
            int cnt = 0;
            rep(k,0,L) {
                if ((i>>k)&1) {
                    cnt++;
                    continue;
                }
                ll cost = dist[E[j].first][E[k].first] + E[k].second;
                dp[i+(1<<k)][k] = min(dp[i+(1<<k)][k], dp[i][j] + cost);
            }
            if (dp[i][j] + dist[E[j].first][S] <= T) {
                ret = max(ret,cnt);
#ifdef LOCAL
    cerr << bitset<4>(i) << " " << j+1 << " " << cnt << " " << dp[i][j] << "+" <<  dist[E[j].first][S] << endl;
#endif
            }
        }
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    int n,m,l,s,t;
    while (cin >> n >> m >> l >> s >> t) {
        if (n+m+l+s+t == 0) break;
        s--;
        VV<pair<int,ll>> G(n);
        rep(i,0,m) {
            ll a,b,c;
            cin >> a >> b >> c;
            a--; b--;
            G[a].push_back({b,c});
            G[b].push_back({a,c});
        }
        V<pair<int,ll>> E;
        V<int> jiro(n,-1);
        rep(i,0,l) {
            int j,e;
            cin >> j >> e;
            j--;
            E.push_back({j,e});
            jiro[j] = i;
        }
        auto ans = solve(n,l,s,t,G,E,jiro);
        cout << ans << endl;
    }

    
    return 0;
}