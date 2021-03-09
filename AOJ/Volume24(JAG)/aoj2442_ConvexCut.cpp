// Convex-Cut
// N個の頂点からなる凸多角形が与えられる。各頂点の座標は反時計周りに(X1, Y1), (X2 ,Y2), ……, (XN, YN)で表わされる。 点Pを通るどのような直線で凸多角形を切断しても、切断後に得られる2つの凸多角形の面積が等しいような点Pの座標を求めよ。

// Input
// 入力は以下の形式で与えられる。

// N
// X1 Y1
// X2 Y2
// ……
// XN YN
// Constraints
// 入力は全て整数である

// 3 ≤ N ≤ 50

// 0 ≤ |Xi|, |Yi| ≤ 1000000

// 入力の多角形は単純な凸多角形である。

// 出力は、出力座標を(X, Y)、厳密解を(cX, cY)とした時にmax(|X-cX|, |Y-cY|) ≤ 0.0001を満たす必要がある

// Output
// 問題文の条件を満たす点があるのならば、その点の座標を

// X Y
// の形式で出力せよ。 点が存在しない場合は"NA"と1行に出力せよ。

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
V<int> x(55), y(55);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    cin >> n;
    rep(i,0,n) {
        cin >> x[i] >> y[i];
    }
    bool f = n % 2;
    int X = x[0] + x[n/2], Y = y[0] + y[n/2];
    rep(i,0,n/2) {
        f |= X != x[i] + x[i+n/2];
        f |= Y != y[i] + y[i+n/2];
    }
    if (f) cout << "NA" << endl;
    else cout << fixed << setprecision(20) << (double) X / 2.0 << " " << (double) Y / 2.0 << endl;

    return 0;
}