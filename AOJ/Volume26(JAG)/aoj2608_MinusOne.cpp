<<<<<<< HEAD
// イクタ君は、無向グラフについて異常なほどの思い入れを持っている。イクタ君は、無向グラフ G とその 2 点 s,tの組(G,s,t)のうち、その「うつくしさ」が大きいものが好きである。 組(G,s,t)の「うつくしさ」とは、辺 e={u,v} (u と v は G の異なる 2 点) で、Gにおけるsからtへの最短路の長さが、Gにeをつけくわえた無向グラフにおけるsからtへの最短路の長さより 1 だけ大きいものの個数である。

// あなたの仕事は、組(G,s,t)が与えられたとき、その「うつくしさ」を求めるプログラムを書くことである。

// Input
// 入力は以下の形式で与えられる。

// N M s t
// x1 y1
// ...
// xi yi
// ...
// xM yM
// 最初に無向グラフの頂点数、辺数、2つの頂点を表す整数N,M,s,tが入力される。 2行目からM+1行目までは辺によって結ばれている2つの頂点が入力される。 (ただし、G の頂点集合を{1,...,N}とする。)

// Constraints
// 入力中の各変数は以下の制約を満たす。

// 2≤N≤100,000
// 1≤M≤300,000
// 1≤s,t,xi,yi≤N
// s と t とは異なる
// s から t に辿り着けることは保証されている
// Output
// 与えられたグラフをGとしたとき、組(G,s,t)の「うつくしさ」を1行で出力せよ。

=======
// イクタ君は、無向グラフについて異常なほどの思い入れを持っている。イクタ君は、無向グラフ G とその 2 点 s,tの組(G,s,t)のうち、その「うつくしさ」が大きいものが好きである。 組(G,s,t)の「うつくしさ」とは、辺 e={u,v} (u と v は G の異なる 2 点) で、Gにおけるsからtへの最短路の長さが、Gにeをつけくわえた無向グラフにおけるsからtへの最短路の長さより 1 だけ大きいものの個数である。

// あなたの仕事は、組(G,s,t)が与えられたとき、その「うつくしさ」を求めるプログラムを書くことである。

// Input
// 入力は以下の形式で与えられる。

// N M s t
// x1 y1
// ...
// xi yi
// ...
// xM yM
// 最初に無向グラフの頂点数、辺数、2つの頂点を表す整数N,M,s,tが入力される。 2行目からM+1行目までは辺によって結ばれている2つの頂点が入力される。 (ただし、G の頂点集合を{1,...,N}とする。)

// Constraints
// 入力中の各変数は以下の制約を満たす。

// 2≤N≤100,000
// 1≤M≤300,000
// 1≤s,t,xi,yi≤N
// s と t とは異なる
// s から t に辿り着けることは保証されている
// Output
// 与えられたグラフをGとしたとき、組(G,s,t)の「うつくしさ」を1行で出力せよ。

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
struct edge{ll to, cost;};
const ll INF = 1e18;
ll V;
const ll MAX_V = 1e5+10;

void dijkstra(ll s, ll *d, vector<edge> *G, ll V, ll *cnt) {
  priority_queue<P, vector<P>, greater<P>> que;
  fill(d, d + V, INF);
  d[s] = 0;
  que.push(P(0, s));
  while (!que.empty()) {
    P p = que.top();
    que.pop();
    ll v = p.second;
    if (d[v] < p.first) continue;
    for (int i = 0; i < G[v].size(); i++) {
      edge e = G[v][i];
      if (d[e.to] > d[v] + e.cost) {
        d[e.to] = d[v] + e.cost;
        que.push(P(d[e.to], e.to));
      }
    }
  }
  for (int i = 0; i < V; i++) {
      if (d[i] != INF)
          cnt[d[i]]++;
  }
}

vector<edge> G[MAX_V];
ll n,m,s,t;
ll d[2][MAX_V];
ll cnt[2][MAX_V];

int main() {
    cin >> n >> m >> s >> t;
    s--;t--;
    for (int i = 0; i < m; i++) {
        ll a,b;
        cin >> a >> b;
        a--;b--;
        G[a].push_back({b,1});
        G[b].push_back({a,1});
    }
    dijkstra(s,d[0],G,n,cnt[0]);
    dijkstra(t,d[1],G,n,cnt[1]);
    ll shortest = d[0][t] - 2;
    ll ans = 0;
    for (int i = 0; i <= shortest; i++) {
        ll j = shortest - i;
        ans += cnt[0][i] * cnt[1][j];
    }
    cout << ans << endl;
    return 0;
}
>>>>>>> 3d537af6c6d6d0e6fecbb17c7d1aa89a0ea36d59
