// Coin Slider
// You are playing a coin puzzle. The rule of this puzzle is as follows:

// There are N coins on a table. The i-th coin is a circle with ri radius, and its center is initially placed at (sxi,syi). Each coin also has a target position: you should move the i-th coin so that its center is at (txi,tyi). You can move coins one by one and can move each coin at most once. When you move a coin, it must move from its initial position to its target position along the straight line. In addition, coins cannot collide with each other, including in the middle of moves.

// The score of the puzzle is the number of the coins you move from their initial position to their target position. Your task is to write a program that determines the maximum score for a given puzzle instance.

// Input
// The input consists of a single test case formatted as follows.

// N
// r1 sx1 sy1 tx1 ty1
// :
// rN sxN syN tx1 tyN
// The first line contains an integer N (1≤N≤16), which is the number of coins used in the puzzle. The i-th line of the following N lines consists of five integers: ri,sxi,syi,txi, and tyi (1≤ri≤1,000,−1,000≤sxi,syi,txi,tyi≤1,000,(sxi,syi)≠(txi,tyi)). They describe the information of the i-th coin: ri is the radius of the i-th coin, (sxi,syi) is the initial position of the i-th coin, and (txi,tyi) is the target position of the i-th coin.

// You can assume that the coins do not contact or are not overlapped with each other at the initial positions. You can also assume that the maximum score does not change even if the radius of each coin changes by 10−5.

// Output
// Print the maximum score of the given puzzle instance in a line.

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

struct State {
    Point s, t;
    double r;
    bool f = 0;
    State() {}
    State(Point s, Point t, double r) : s(s), t(t), r(r) {}
};

bool intersect (Point c, double r, Point a, Point b) {
    if ((a-c).abs() < r + EPS || (b-c).abs() < r + EPS) return 1;
    b = b - a;
    Point o = c - a;
    Point h = b * dot(o,b) / b.norm();
    // b.out();o.out();h.out();
    // cout << (h-o).abs() << endl;
    if ((h-o).abs() > r + EPS) return 0;

    Point eb = b / b.abs();
    Point eh = h / h.abs();
    if ((eb - eh).abs() > EPS) return 0;

    return b.abs() + EPS > h.abs();
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

bool intersect(State a, State b) {
    // aが移動時bと衝突するか
    // 起点か終点で衝突
    Point bp = (b.f ? b.t : b.s);
    if ((a.s - bp).abs() < a.r + b.r - EPS) return true;
    if ((a.t - bp).abs() < a.r + b.r - EPS) return true;
    
    // 移動時に衝突
    Vector origin = a.t - a.s;
    Vector ov = Point(origin.y, -origin.x) / origin.abs() * a.r;
    // 境界線と接触
    if (intersect(bp, b.r, a.s + ov, a.t + ov)) return true;
    if (intersect(bp, b.r, a.s - ov, a.t - ov)) return true;
    // 境界線に含まれる
    if (contains({a.s+ov,a.s-ov,a.t-ov,a.t+ov}, bp)) return true;
    return false;
}

auto solve (int N, V<State>& Vec) -> int {
    V<bool> used(1<<N);
    int ret = 0;

    auto ok = [&](int k, int u) -> bool {
        rep(i,0,N) {
            if (k == i) continue;
            Vec[i].f = (u>>i) & 1;
            if (intersect(Vec[k], Vec[i])) return false;
        }
        return true;
    };


    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int s = q.front(); q.pop();
        if (used[s]) continue;
        used[s] = 1;

        // renew the result
        int cnt = 0;
        rep(i,0,N) {
            if ((s>>i)&1) cnt++;
        }
        ret = max(ret, cnt);

        rep(i,0,N) {
            if ((s>>i) & 1) continue;
            if (ok(i,s)) {
                if (!used[s + (1<<i)]) {
                    q.push(s + (1<<i));
                }
            }
        }
    }
    return ret;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    int N;
    cin >> N;
    V<State> v(N);
    rep(i,0,N) {
        double r,sx,sy,tx,ty;
        cin >> r >> sx >> sy >> tx >> ty;
        v[i] = State(Point(sx,sy), Point(tx,ty), r);
    }
    auto ans = solve(N,v);
    cout << ans << endl;
    
    return 0;
}