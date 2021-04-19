// Problem Statement
// You are given a connected undirected graph which has even numbers of nodes. A connected graph is a graph in which all nodes are connected directly or indirectly by edges.

// Your task is to find a spanning tree whose median value of edges' costs is minimum. A spanning tree of a graph means that a tree which contains all nodes of the graph.

// Input
// The input consists of multiple datasets.

// The format of each dataset is as follows.

// n m
// s1 t1 c1
// ...
// sm tm cm
// The first line contains an even number n (2≤n≤1,000) and an integer m (n−1≤m≤10,000). n is the nubmer of nodes and m is the number of edges in the graph.

// Then m lines follow, each of which contains si (1≤si≤n), ti (1≤si≤n,ti≠si) and ci (1≤ci≤1,000). This means there is an edge between the nodes si and ti and its cost is ci. There is no more than one edge which connects si and ti.

// The input terminates when n=0 and m=0. Your program must not output anything for this case.

// Output
// Print the median value in a line for each dataset.

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
#define dbg(x) cerr << __LINE__ << 
#else
#define dbg(x) true
#endif

struct P{
    int f,t,c;
    P(){}
    P(int f, int t, int c):f(f),t(t),c(c){}
    bool operator < (const P& other) const {
        return c < other.c;
    }
};

const int MAXN = 1010;
int par[MAXN];
int rk[MAXN];
void init (int n) {
  for (int i = 0; i < n; i++) {
    par[i] = i;
    rk[i] = 0;
  }
}
int fd(int x) {
  if (par[x] == x) {
    return x;
  } else {
    return par[x] = fd(par[x]);
  }
}
void unite (int x, int y) {
  x = fd(x);
  y = fd(y);
  if (x == y) return;

  if (rk[x] < rk[y]) {
    par[x] = y;
  } else {
    par[y] = x;
    if (rk[x] == rk[y]) rk[x]++;
  }
}

// クラスカル法で(n-1)/2の辺を決める
auto solve (int n, int m, V<P>& v) -> int {
    init(n);
    sort(all(v));

    int cnt = 0;

    rep(i,0,m) {
        auto p = v[i];
        if (fd(p.f) == fd(p.t)) continue;
        unite(p.f, p.t);
        cnt++;
        if (cnt == n / 2) {
            return p.c;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    int n,m;
    while (cin >> n >> m) {
        if (n+m == 0) break;
        
        V<P> v;
        rep(i,0,m) {
            int a,b,c;
            cin >> a >> b >> c;
            a--;b--;
            v.push_back(P(a,b,c));
        }

        auto ans = solve(n,m,v);
        cout << ans << endl;
    }
    return 0;
}