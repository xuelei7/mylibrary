#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (int)(a); (i) < (int)(b); (i)++)
#define rrep(i, a, b) for (int i = (int)(b) - 1; (i) >= (int)(a); (i)--)
#define all(v) v.begin(), v.end()

typedef long long ll;
typedef long double lld;
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
lld s,g;
V<lld> l(200010), r(200010);

#define EPS (1e-16)
class Point{
public:
  lld x,y;
  Point(lld x = 0, lld y = 0):x(x), y(y) {}
  
  Point operator + (Point p){return Point(x+p.x,y+p.y);}
  Point operator - (Point p){return Point(x-p.x,y-p.y);}
  Point operator * (lld k){return Point(x*k,y*k);}
  Point operator / (lld k){return Point(x/k,y/k);}

  lld norm(){return x*x+y*y;}
  lld abs(){return sqrt(norm());}

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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    cin >> n >> s >> g;
    rep(i,0,n+1) {
        cin >> l[i] >> r[i];
    }
    l[0] = s, r[0] = s;
    l[n] = g, r[n] = g;

    Point now(s,0), pl(l[1],1), pr(r[1],1);
    Vector lft(l[1] - l[0], 1), rt(r[1] - r[0]);
    rep(i,2,n+1) {
        Vector tl(l[i] - now.x, i - now.y), tr(r[i] - now.x, i - now.y);

        // turn left
        if (cross(lft, tr) > EPS) {

        }
        // turn right
        if (cross(rt, tl) < -EPS) {
            
        }
        // shrink area

    }
    
    return 0;
}