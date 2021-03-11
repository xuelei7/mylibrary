// Milky Way
// 天の川
// English text is not available in this practice contest.

// 天の川交通公社は星間旅行ツアーの企画・運営を行う旅行会社である。 天の川交通公社では「天の川横断織姫彦星体験ツアー」という企画を計画中である。 このツアーは琴座のベガを出発し、 星々を巡って鷲座のアルタイルに向かうというものである。 あなたは天の川交通公社に社員であり、 ツアーの経路の選択を任されている。

// 簡単のため天の川は2次元座標上にあるものとし、 星は五芒星で表現されるものとする。 ツアーに使用する宇宙船には特殊なエンジンが搭載されており、 五芒星の線分上はエネルギー無しで移動することができる。 一方、五芒星の間を移動する際には、その距離に比例したエネルギーが必要となる。

// 近年、天の川交通公社の売上は低迷しており、 宇宙船のエネルギー代を始めとした各種必要経費の節約を迫られている。 あなたの仕事は、ベガからアルタイルに移動する際、 星間移動距離の総和が最小になるような経路を求め、 その総和を出力するプログラムを書くことである。

// ある五芒星からその内部に含まれる別の五芒星に移動する場合、 五芒星同士が接していない場合は星間の移動として扱われることに注意せよ。

// 図D-1は3つ目のSample Inputを図示したものである。 図中、赤色の線分は星間移動距離の総和が最小になるような経路の、 星間移動の部分を表している。


// 図 D-1: 星間の移動

// Input
// 入力は1つ以上のデータセットからなる。1つのデータセットは次の形式をしている。

// N M L
// x1 y1 a1 r1
// x2 y2 a2 r2
// …
// xN yN aN rN
// 各テストケースの初めの1行は整数N、M、Lからなり、 Nは星の数(1 ≤ N ≤ 100)、 Mはベガの番号(1 ≤ M ≤ N)、 Lはアルタイルの番号(1 ≤ L ≤ N)を表す。 続くN行には各星の情報が与えられる。 各行はxi、yi、ai、riの4つの整数からなり、 xiはi番目の星の中心のx座標(0 ≤ xi ≤ 1,000)、 yiはi番目の星の中心のy座標(0 ≤ yi ≤ 1,000)、 aiはi番目の星の中心座標と星の先端を結んだ直線がy軸となす角度(0 ≤ ai < 72)、 riはi番目の星の中心座標から星の先端までの長さ(1 ≤ ri ≤ 1,000)である。 入力の終わりは3つのゼロを含む行で表される。

// 図 D-2の左の星はx=5, y=10, a=0, r=5の星を表しており、右の星はx=15, y=10, a=30, r=5の星を表している。


// 図 D-2: 星の例

// Output
// 各入力ごとに、ベガからアルタイルに移動する際に必要な星間移動距離の総和の最小値を1行に出力せよ。 出力には、0.000001を超える誤差があってはならない。

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
// IN 2 ON 1 OUT 0
int contains(Polygon g,Point p){
  int n=g.size();
  bool x = false;
  for(int i=0;i<n;i++){
    Point a = g[i] - p, b = g[(i+1)%n] - p;
    if(fabs(cross(a,b))<EPS && dot(a,b)<EPS) return 1;
    if(a.y > b.y) swap(a,b);
    if(a.y<EPS && EPS < b.y && cross(a,b) > EPS) x = !x;
  }
  return ( x ? 2:0);
}
// from aoj0021
bool parallel(Vector a, Vector b) {
  return abs(cross(a,b)) < EPS;
}
// from aoj0058
bool orthogonal(Vector a, Vector b) {
  return abs(dot(a,b)) <= EPS;
}
// from aoj2402
Vector rotate(Vector a, double arg) {
    Vector b;
    b.x = cos(arg) * a.x - sin(arg) * a.y;
    b.y = sin(arg) * a.x + cos(arg) * a.y;
    return b;
}
// judge the relation between vector(p0, p1) and vector(p0, p2)
static const int COUNTER_CLOCKWISE = 1;
static const int CLOCKWISE = -1;
static const int ONLINE_BACK = 2;
static const int ONLINE_FRONT = -2;
static const int ON_SEGMENT = 0;
int ccw(Point p0,Point p1,Point p2){
  Vector a = p1-p0;
  Vector b = p2-p0;
  if(cross(a,b) > EPS) return COUNTER_CLOCKWISE;
  if(cross(a,b) < -EPS) return CLOCKWISE;
  if(dot(a,b) < -EPS) return ONLINE_BACK;
  if(a.norm()<b.norm()) return ONLINE_FRONT;
  return ON_SEGMENT;
}
bool intersect(Point p1,Point p2,Point p3,Point p4){
  return (ccw(p1,p2,p3) * ccw(p1,p2,p4) <= 0 &&
	  ccw(p3,p4,p1) * ccw(p3,p4,p2) <= 0 );
}
Point projection(Point x1, Point x2, Point q) {
    double x = dot(q - x1, x1 - x2) / (x1 - x2).norm();
    return x1 + (x1 - x2) * x;
}
int n,m,l;
struct Star {
    double a = 0, r = 0;
    Point p[5], c;
    Star(){}
    Star(double _x, double _y, double _a, double _r) {
        c.x = _x;
        c.y = _y;
        a = _a;
        r = _r;
        p[0] = rotate(Point(c.x, c.y + r) - c, acos(-1)*a/180.0) + c;
        rep(i,1,5) {
            p[i] = rotate(p[i-1]-c, acos(-1)*72.0/180.0) + c;
        }
    }
};

struct Line {
    Point a, b;
    Line() {}
    Line(Point a, Point b):a(a), b(b) {}
};

bool on(Point p, Point x1, Point x2) {
    Vector v1 = p - x1;
    Vector v2 = x2 - x1;
    Vector v3 = x2 - p;
    return abs(v1.abs() + v3.abs() - v2.abs()) < EPS;
}
double dist(Point p, Point x1, Point x2) {
    double ret = 1e9;
    Point pp = projection(x1, x2, p);
#ifdef LOCAL
    cerr << "pp: " << pp.x << " " << pp.y << endl;
#endif
    if (on(pp, x1, x2)) {
        ret = min(ret, (p - pp).abs());
    } else {
        ret = min(ret, min((p-x1).abs(), (p-x2).abs()));
    }
    return ret;
}
double dist(Line a, Line b) {
    if (intersect(a.a,a.b,b.a,b.b)) return 0;
    double ret = 1e9;
    ret = min(ret, dist(a.a, b.a, b.b));
    dbg(dist(a.a, b.a, b.b));
    ret = min(ret, dist(a.b, b.a, b.b));
    dbg(dist(a.b, b.a, b.b));
    ret = min(ret, dist(b.a, a.a, a.b));
    dbg(dist(b.a, a.a, a.b));
    ret = min(ret, dist(b.b, a.a, a.b));
    dbg(dist(b.b, a.a, a.b));
    dbg(ret);
    return ret;
}

double min_dist(Star a, Star b) {
    V<Line> la(5), lb(5);
    int s = 0;
    rep(i,0,5) {
        la[i] = Line(a.p[s], a.p[(s+2)%5]);
        lb[i] = Line(b.p[s], b.p[(s+2)%5]);
        s = (s + 2) % 5;
    }

    double mi = 1e9;
    rep(i,0,5) {
        rep(j,0,5) {
#ifdef LOCAL
    cerr << "dist: " << i << " " << j << endl;
#endif
            mi = min(mi, dist(la[i], lb[j]));
        }
    }

    return mi;
}

auto solve () -> void {
    // input
    V<Star> stars(n);
    rep(i,0,n) {
        double x,y,a,r;
        cin >> x >> y >> a >> r;
        stars[i] = Star(x,y,a,r);
#ifdef LOCAL
    cerr << "Star[" << i << "]" << endl;
    rep(j,0,5) {
        cerr << "  p[" << j << "]: " << stars[i].p[j].x << " " << stars[i].p[j].y << endl;
    }
#endif
    }

    // 距離を定義
    double inf = 1e9;
    VV<double> d(n,V<double>(n,inf));
    rep(i,0,n) {
        d[i][i] = 0;
        rep(j,i+1,n) {
            d[i][j] = d[j][i] = min_dist(stars[i],stars[j]);
        }
    }
#ifdef LOCAL
    rep(i,0,n) {
        rep(j,0,n) {
            cerr << fixed << setprecision(3) << d[i][j] << " ";
        }
        cerr << endl;
    }
#endif

    // 最短経路
    V<double> dp(n,inf);
    V<bool> used(n,0);
    priority_queue<pair<double,int>,vector<pair<double,int>>,greater<pair<double,int>>> pq;
    pq.push({0,m});
    dp[m] = 0;
    while (!pq.empty()) {
        auto tp = pq.top(); pq.pop();
#ifdef LOCAL
    cerr << "now: " << tp.second << " " << tp.first << endl;
#endif
        if (used[tp.second]) continue;

        rep(i,0,n) {
            if (used[i]) continue;
#ifdef LOCAL
    cerr << "search " << i << endl;
#endif
            if (dp[i] > tp.first + d[tp.second][i]) {
                dp[i] = tp.first + d[tp.second][i];
                pq.push({dp[i], i});
            }
        }
    }
#ifdef LOCAL
    rep(i,0,n) {
        cerr << "dp[" << i << "]: " << dp[i] << endl;
    }
#endif
    cout << fixed << setprecision(20) << dp[l] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';

    while (cin >> n >> m >> l) {
        if (n+m+l == 0) break;
        m--;
        l--;
        solve();
    }
    return 0;
}