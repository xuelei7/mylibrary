// ２都市間の距離
// 地球上の2 都市の北緯と東経を入力とし、地表距離を計算して出力するプログラムを作成してください。ただし、地球は半径 6,378.1 km の球とし、2 点間の地表距離とはこの球面に沿った最短距離です。また、南半球でも南緯は用いずに北緯 0 ~ -90 度を用い、グリニッジ子午線の西でも西経は用いずに東経 180 ~ 360 度を用いることとします。地表距離は km 単位で求め、小数点以下は四捨五入し、整数値として出力してください。

// 以下に主要都市の北緯、東経の例を示します。

// 地名	北緯(度)	東経(度)
// 東京	35.68	139.77
// シンガポール	1.37	103.92
// シドニー	-33.95	151.18
// シカゴ	41.78	272.25
// ブエノスアイレス	-34.58	301.52
// ロンドン	51.15	359.82


// Input
// 複数のデータセットの並びが入力として与えられます。入力の終わりは-1 四つの行で示されます。各データセットは以下の形式で与えられます。

// a b c d
// 1 行に第 1 の都市の北緯 a、第 1 の都市の東経 b、第 2 の都市の北緯 c、第 2 の都市の東経 d が空白区切りで与えられます。入力はすべて実数で与えられます。

// データセットの数は 30 を超えません。

// Output
// データセット毎に 2 都市の地表距離を１行に出力します。

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

class Point3D {
public:
  double x,y,z;
  Point3D(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}

  Point3D operator + (Point3D p){return Point3D(x+p.x,y+p.y,z+p.z);}
  Point3D operator - (Point3D p){return Point3D(x-p.x,y-p.y,z-p.z);}
  Point3D operator * (double k){return Point3D(x*k,y*k,z*k);}
  Point3D operator / (double k){return Point3D(x/k,y/k,z/k);}

  double norm(){return x*x+y*y+z*z;}
  double abs(){return sqrt(norm());}

  bool operator <(const Point3D &p) const {
      return x!=p.x ? x<p.x : (y!=p.y ? y<p.y : z<p.z);
  }
  bool operator == (const Point3D &p) const{
    return fabs(x-p.x) < EPS && fabs(y-p.y) < EPS && fabs(z-p.z) < EPS;
  }
  void out() {
    cout << x << " " << y << " " << z << endl;
  }
};

double dot (Point3D a, Point3D b) {
  return a.x * b.x + a.y * b.y + a.z * b.z;
}

Point3D cross (Point3D a, Point3D b) {
  return Point3D(a.y*b.z-a.z*b.y, a.z*b.x-a.x*b.z, a.x*b.y-a.y*b.x);
}

Vector rotate(Vector a, double arg) {
    Vector b;
    b.x = cos(arg) * a.x - sin(arg) * a.y;
    b.y = sin(arg) * a.x + cos(arg) * a.y;
    return b;
}

Point3D rotate(Point3D p, double hokui, double toukei) {
    Point tmp(p.x,p.y);
    tmp = rotate(tmp, hokui / 180 * acos(-1));
    p.x = tmp.x;
    p.y = tmp.y;

    tmp = Point(p.x,p.z);
    tmp = rotate(tmp, toukei / 180 * acos(-1));
    p.x = tmp.x;
    p.z = tmp.y;

    return p;
}

auto solve (double a, double b, double c, double d) -> int {
    const double R = 6378.1;
    Point3D A(R,0,0), B(R,0,0);
    A = rotate(A, a, b);
    B = rotate(B, c, d);

    double kakudo = acos(dot(A, B) / A.abs() / B.abs());
    double length = R * kakudo;
    int intlength = length;
    double err = length - intlength;
    if (err >= 0.5) intlength++;
    return intlength;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    double a,b,c,d;
    while (cin >> a >> b >> c >> d) {
        if (a == -1 && b == -1 && c == -1 && d == -1) break;
        cout << solve(a,b,c,d) << endl;
    }
    
    
    return 0;
}