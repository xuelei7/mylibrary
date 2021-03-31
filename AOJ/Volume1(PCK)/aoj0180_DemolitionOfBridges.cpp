// 橋の取り壊し
// 水の国ウォーターデブンには n 個の都市があります。各都市は水に囲まれており、島国のようになっています。ウォーターデブンには m 本の橋があり、都市間の交通はそれらの橋によって行われ、全ての都市に行き来することができます。

// 最近、道路特定財源の見直しにより橋の維持費の削減が決定されました。全部の橋を維持することができなくなってしまい、いくつかの橋を取り壊すことになりました。そこで、ウォーターデブンはどの都市にでも行くことができるように橋を残しつつ、橋の維持費を最小化することが課題となりました。

// 都市の数、橋の数、各橋の維持費を入力とし、橋を利用してどの都市にも行けるようにしつつ、橋を取り壊した場合の維持費の最小値を出力するプログラムを作成してください。なお、橋の取り壊しには費用が掛からないものとします。ただし、各都市は 0 から n - 1 まで順番に番号が付けられているものとします。

// Input
// 複数のデータセットの並びが入力として与えられます。入力の終わりはゼロふたつの行で示されます。各データセットは以下の形式で与えられます。

// n m
// a1 b1 cost1
// a2 b2 cost2
// :
// am bm costm
// １行目に都市の数 n (2 ≤ n ≤ 100)、 橋の数 m (1 ≤ m ≤ 500) が与えられます。続く m 行に第 i の橋の情報が与えられます。ai, bi は橋がつないでいる都市の番号、costi (1 ≤ costi ≤ 1000) は橋にかかる維持費を表します。

// Output
// データセット毎に橋の維持費の合計を１行に出力します。

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

const int MAXN = 110;
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


struct bridge {
    int f,t,c;
    bridge(int f=0, int t=0, int c=0) : f(f), t(t), c(c) {}
    bool operator < (const bridge& other) const {
        return c < other.c;
    }
};

auto solve (int n, int m, V<bridge>& v) -> int {
    int ret = 0;
    sort(all(v));
    init(n);

    rep(i,0,m) {
        if (fd(v[i].f) == fd(v[i].t)) continue;
        ret += v[i].c;
        unite(v[i].f, v[i].t);
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    int n,m;
    while (cin >> n >> m) {
        if (n == 0 && m == 0) break;
        V<bridge> v(m);
        rep(i,0,m) {
            int a,b,c;
            cin >> a >> b >> c;
            v[i] = bridge(a,b,c);
        }
        cout << solve(n,m,v) << endl;
    }
    
    return 0;
}