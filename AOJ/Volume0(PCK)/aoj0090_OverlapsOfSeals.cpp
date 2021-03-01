// シールの重なり
// 1 辺の長さが 10 の正方形の折り紙に半径 1 の円形のシールを n 枚貼ります。シールは重ねて貼ることができます。シールを貼る位置の座標を読み込んで、折り紙上でもっとも多くシールが重なっている場所(シールが１枚だけでも"重なっている"とする)でのシールの枚数を出力するプログラムを作成してください。

// 折り紙の左下を原点とした x,y 座標を与えます。この x,y を円の中心としてシールを貼ることとします。円の中心が折り紙の外に出ることはありません。また、同一座標に複数のシールが貼られることはありません。

// Input
// 複数のデータセットが与えられます。各データセットは以下のような形式で与えられます。

// n 
// x1,y1
// x2,y2
// : 
// xn,yn
// １行目にシールの枚数 n (0 ≤ 100) が与えられます。続く n 行に、各シールの中心座標が与えられます。 xi, yi は i 枚目のシールの中心の x 座標と y 座標を表します。各値は小数点以下最大 6 桁までの数字を含む実数で与えられます。

// n が 0 のとき、入力の最後とします。データセットの数は 50 を超えません。

// Output
// 各データセットに対し、折り紙上で最も多くシールが重なっている場所でのシールの枚数（整数）を出力して下さい。

// geometry

#include <bits/stdc++.h>
using namespace std;
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
class Circle {
public:
  Point o;
  double r;
  Circle(Point o, double r = 0):o(o), r(r) {}
  bool operator == (const Circle &p) const {
    return o == p.o && r == p.r;
  }
};
// 1: intersect, 0: outside, 2: B in A, -2: A in B
int intersection(Circle a, Circle b) {
  double dist = (a.o-b.o).abs();
  // 交叉
  if (dist >= abs(a.r - b.r) && dist <= a.r + b.r) {
    return 1;
  }
  // 外部
  if (dist > a.r + b.r) {
    return 0;
  }
  // 内部
  if (b.r < a.r) return 2;
  else return -2;
}
vector<Point> intersect_points(Circle a, Circle b) {
    if (a == b || intersection(a,b) != 1) return vector<Point>();
    double r1 = a.r, r2 = b.r, dist = (a.o - b.o).abs();
    double x = (r1 * r1 - r2 * r2 + dist * dist) / (2 * dist);
    double h = sqrt(r1 * r1 - x * x);
    Vector dx = b.o - a.o;
    dx = dx / dist * x;
    Vector dir = Vector(-dx.y, dx.x);
    dir = dir / dir.abs() * h;
    Point p1 = a.o + dx + dir;
    Point p2 = a.o + dx - dir;
    if ((p1-p2).abs() < EPS) return {p1};
    else return {p1,p2};
}
int main() {
    int n;
    while (cin >> n) {
        if (n == 0) break;
        Point p[110];
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < s.size(); j++) if (s[j] == ',') s[j] = ' ';
            stringstream ss(s);
            ss >> p[i].x >> p[i].y;
        }
        int ans = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                vector<Point> v = intersect_points(Circle(p[i],1), Circle(p[j],1));
                for (int k = 0; k < v.size(); k++) {
                    int cnt = 0;
                    for (int idx = 0; idx < n; idx++) {
                        if ((v[0]-p[idx]).abs() < 1.0000001) cnt++;
                    }
                    ans = max(ans, cnt);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}