// Problem B Parallel Lines
// Given an even number of distinct planar points, consider coupling all of the points into pairs. All the possible couplings are to be considered as long as all the given points are coupled to one and only one other point.

// When lines are drawn connecting the two points of all the coupled point pairs, some of the drawn lines can be parallel to some others. Your task is to find the maximum number of parallel line pairs considering all the possible couplings of the points.

// For the case given in the first sample input with four points, there are three patterns of point couplings as shown in Figure B.1. The numbers of parallel line pairs are 0, 0, and 1, from the left. So the maximum is 1.


// Figure B.1. All three possible couplings for Sample Input 1

// For the case given in the second sample input with eight points, the points can be coupled as shown in Figure B.2. With such a point pairing, all four lines are parallel to one another. In other words, the six line pairs [Math Processing Error], [Math Processing Error], [Math Processing Error], [Math Processing Error], [Math Processing Error] and [Math Processing Error] are parallel. So the maximum number of parallel line pairs, in this case, is 6.

// Input
// The input consists of a single test case of the following format.

// [Math Processing Error]
// [Math Processing Error] [Math Processing Error]
// ...
// [Math Processing Error] [Math Processing Error]

// Figure B.2. Maximizing the number of parallel line pairs for Sample Input 2

// The first line contains an even integer [Math Processing Error], which is the number of points ([Math Processing Error]). Each of the following [Math Processing Error] lines gives the coordinates of a point. Integers [Math Processing Error] and [Math Processing Error] ([Math Processing Error]) in the [Math Processing Error]-th line of them give the [Math Processing Error]- and [Math Processing Error]-coordinates, respectively, of the [Math Processing Error]-th point.

// The positions of points are all different, that is, [Math Processing Error] or [Math Processing Error] holds for all [Math Processing Error]. Furthermore, No three points lie on a single line.

// Output
// Output the maximum possible number of parallel line pairs stated above, in one line.

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
bool parallel(Vector a, Vector b) {
  return abs(cross(a,b)) < EPS;
}

int count_pair(V<Vector> v) {
    int ret = 0;
    rep(i,0,v.size()) {
        rep(j,i+1,v.size()) {
            if (parallel(v[i],v[j])) ret++;
        }
    }
    return ret;
}

auto solve (int n, V<Point>& p) -> int {
    bitset<16> bs(0);
    V<Vector> v;
    
    int ans = 0;
    auto dfs = [&](auto self, int cnt) -> void {
        if (cnt == n) {
            ans = max(ans, count_pair(v));
            return;
        }
        rep(i,0,n) { // 1個目の点
            if (bs[i]) continue;
            bs.set(i);
            rep(j,i,n) { // 2個目の点
                if (bs[j]) continue;
                bs.set(j);
                v.push_back(p[i]-p[j]); // ベクトルをvに入れる
                self(self, cnt + 2);
                v.pop_back();
                bs.reset(j);
            }
            bs.reset(i);
            break;
        }
    };

    dfs(dfs,0);

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    // input
    int n;
    cin >> n;
    V<Point> p(n);
    rep(i,0,n) cin >> p[i].x >> p[i].y;

    // solve
    auto ans = solve(n,p);

    // output
    cout << ans << endl;
    
    return 0;
}