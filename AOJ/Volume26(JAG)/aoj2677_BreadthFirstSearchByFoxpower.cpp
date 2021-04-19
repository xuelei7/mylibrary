// A - Breadth-First Search by Foxpower
// Problem Statement
// Fox Ciel went to JAG Kingdom by bicycle, but she forgot a place where she parked her bicycle. So she needs to search it from a bicycle-parking area before returning home.

// The parking area is formed as a unweighted rooted tree $T$ with $n$ vertices, numbered $1$ through $n$. Each vertex has a space for parking one or more bicycles. Ciel thought that she parked her bicycle near the vertex $1$, so she decided to search it from there by the breadth-first search. That is, she searches it at the vertices in the increasing order of their distances from the vertex $1$. If multiple vertices have the same distance, she gives priority to the vertices in the order of searching at their parents. If multiple vertices have the same parent, she searches at the vertex with minimum number at first.

// Unlike a computer, she can't go to a next vertex by random access. Thus, if she goes to the vertex $j$ after the vertex $i$, she needs to walk the distance between the vertices $i$ and $j$. BFS by fox power perhaps takes a long time, so she asks you to calculate the total moving distance in the worst case starting from the vertex $1$.

// Input
// The input is formatted as follows.

// $n$
// $p_2$ $p_3$ $p_4$ $\cdots$ $p_n$
// The first line contains an integer $n$ ($1 \le n \le 10^5$), which is the number of vertices on the unweighted rooted tree $T$. The second line contains $n-1$ integers $p_i$ ($1 \le p_i < i$), which are the parent of the vertex $i$. The vertex $1$ is a root node, so $p_1$ does not exist.

// Output
// Print the total moving distance in the worst case in one line.

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

const int MAX_N = 100010;
const int MAX_V = 20;
int N;
ll dep[MAX_N];
ll par[MAX_V][MAX_N];

void init() {
    /* find dep and par[0][...] */

    for (int i = 1; i < MAX_V; i++) {
        for (int j = 0; j < N; j++) {
            par[i][j] = par[i-1][par[i-1][j]];
        }
    }
}

int LCA(int u, int v) {
    //to the same height
    for (int i = 19; i >= 0; i--) if (dep[u] - (1 << i) >= dep[v]) u = par[i][u];
    for (int i = 19; i >= 0; i--) if (dep[v] - (1 << i) >= dep[u]) v = par[i][v];
    if (u == v) return u;
    //to one step before LCA
    for (int i = MAX_V-1; i >= 0; i--) {
        if (par[i][u] != par[i][v]) u = par[i][u], v = par[i][v];
    }
    return par[0][u];
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    cin >> N;
    VV<int> G(N);
    rep(i,1,N) {
        int p;
        cin >> p;
        p--;
        par[0][i] = p;
        dep[i] = dep[p] + 1;
        G[p].push_back(i);
    }
    init();

    ll ans = 0;

    int pre = -1;
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        auto tp = q.front(); q.pop();
dbg(tp+1);
        // calculate distance
        if (pre != -1) {
            int lca = LCA(tp, pre);
            ans += dep[tp] + dep[pre] - dep[lca] * 2;
            dbg(lca+1);
            dbg(ans);
        }
        pre = tp;

        sort(all(G[tp]));
        rep(i,0,G[tp].size()) {
            q.push(G[tp][i]);
        }
    }

    cout << ans << endl;
    
    return 0;
}