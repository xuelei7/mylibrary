// Problem B: Carrot Tour
// うさぎがある国を旅行している. この国には1 からn の番号がついたn 個の都市があり, うさぎは今都市1にいる. 都市i は座標平面上の1 点(xi, yi) とみなす.

// うさぎは以下の条件をみたすように旅をする.

// 移動経路は折れ線であり, その各部分は異なる2 都市を結ぶ線分でなければならない.
// 移動経路の全長はr 以下でなければならない. 経路のうち重なった部分も, 通った回数分数える.
// 移動する方向が変わるとき, 曲がる角度はθ 以下でなければならない. 最初の移動方向に制限はない.
// うさぎがある都市から別の都市へ移動をすると, 移動先の都市でニンジンを1 本もらえる. 同じ都市を複数回訪れることは可能であり, 訪れるたびにニンジンをもらえる. うさぎがこの旅で手に入れることのできるニンジンの本数の最大値を求めよ.

// Input
// 入力の一行目には一つの整数n が, 二行目には二つの実数r, θ がスペースで区切られて与えられる.

// 1 ≤ n ≤ 20
// 0 < r < 104
// 0° < θ < 180°
// 続くn 行には, 整数xi, yi がスペースで区切られて与えられる

// -10 000 ≤ xi, yi ≤ 10 000

// r, θ を±10−3 以内で変化させても答えは変わらない.
// どの2 つの都市の位置も異なる.

// Output
// うさぎがこの旅で手に入れることのできるニンジンの本数の最大値を一行に出力せよ.

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

#define EPS (1e-10)
class Point{
public:
  double x,y;
  Point(double x = 0, double y = 0):x(x), y(y) {}
  
  Point operator + (Point p){return Point(x+p.x,y+p.y);}
  Point operator - (Point p){return Point(x-p.x,y-p.y);}
  Point operator * (double k){return Point(x*k,y*k);}
  Point operator / (double k){return Point(x/k,y/k);}

  double norm(){return x*x+y*y;}
  double abs(){return sqrt(norm());}

  bool operator <(const Point &p) const {
      return x!=p.x ? x<p.x : y<p.y;
  }
  bool operator == (const Point &p) const{
    return fabs(x-p.x) < EPS && fabs(y-p.y) < EPS;
  }
};
typedef Point Vector;
typedef vector<Point> Polygon;
double dot(Vector a,Vector b){
  return a.x * b.x + a.y * b.y;
}
double cross(Vector a,Vector b){
  return a.x * b.y - a.y * b.x;
}

auto solve (int N, double R, double THETA, V<double>& X, V<double>& Y) -> int {
    
    // distance between point i and point j
    VV<double> dist(N, V<double>(N));
    rep(i,0,N) {
        rep(j,0,N) {
            dist[i][j] = sqrt((X[i] - X[j]) * (X[i] - X[j]) + (Y[i] - Y[j]) * (Y[i] - Y[j]));
        }
    }

    // see if f -> i -> t is ok
    V<VV<bool>> ok(N,VV<bool>(N, V<bool>(N)));
    double lim = cos(THETA * acos(-1) / 180);
    // f -> i -> t
    rep(i,0,N) {
        rep(f,0,N) {
            if (i == f) continue;
            rep(t,0,N) {
                if (i == t || f == t) continue;

                Vector a = Point(X[i],Y[i]) - Point(X[f],Y[f]);
                Vector b = Point(X[t],Y[t]) - Point(X[i],Y[i]);

                // cos(現在の角度) >= cos(theta*pi/180.0)
                // acos(現在) <= acos(限界値)
                double cos_ab = dot(a,b)/a.abs()/b.abs();

                if (cos_ab > lim + EPS) {
                    ok[f][i][t] = true;
                }
            }
        }
    }
    
    struct S{
        double dist;
        int f, t, k;
        S(){}
        S(double dist, int f, int t, int k):dist(dist),f(f),t(t),k(k) {}
        bool operator > (const S& other) const {
            return dist > other.dist;
        }
    };
    
    // 辺i->jを通って，k個のニンジンが得られる最小経路
    V<VV<double>> dp(N, VV<double>(N, V<double>(1e4+1, 1e9)));
    priority_queue<S,vector<S>,greater<S>> pq;
    rep(i,1,N) {
        if (dist[0][i] < R + EPS) {
            dp[0][i][1] = dist[0][i];
            pq.push(S(dp[0][i][1], 0, i, 1));
        }
    }
    while (!pq.empty()) {
        auto tp = pq.top(); pq.pop();
        if (dp[tp.f][tp.t][tp.k] < tp.dist - EPS) continue;
        rep(i,0,N) {
            if (i == tp.t) continue; // 同じ点
            if (!ok[tp.f][tp.t][i]) continue; // 角度が不合格
            if (tp.dist + dist[tp.t][i] > R + EPS) continue; // 距離が不合格
            if (dp[tp.t][i][tp.k+1] < tp.dist + dist[tp.t][i] + EPS) continue; // 最小ではない
            dp[tp.t][i][tp.k+1] = tp.dist + dist[tp.t][i];
#ifdef LOCAL
    cerr << tp.t << " -> " << i << " " << tp.k + 1 << " " << dp[tp.t][i][tp.k+1] << endl;
#endif
            pq.push(S(dp[tp.t][i][tp.k+1], tp.t, i, tp.k+1));
        }
    }

    // result
    int ans = 0;
    rrep(k,0,1e4+1) {
        rep(i,0,N) {
            rep(j,0,N) {
                if (dp[i][j][k] < R + EPS) {
                    ans = k;
                    goto result;
                }
            }
        }
    }
    result:
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    int n;
    cin >> n;
    double r,theta;
    cin >> r >> theta;
    V<double> x(n),y(n);
    rep(i,0,n) {
        cin >> x[i] >> y[i];
    }
    auto ans = solve(n,r,theta,x,y);
    cout << ans << endl;
    return 0;
}