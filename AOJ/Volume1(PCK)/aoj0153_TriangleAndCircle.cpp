// 三角形と円
// 平面上にある三角形と円の位置関係を判定するプログラムを作成してください。対象となる図形はいずれも境界を含むものとします。 三角形は 3 頂点の位置が与えられ、円は中心の位置と半径が与えられます。位置は直交座標系による２つの整数の組によって与えられます。半径も整数で与えられます。

// Input
// 複数のデータセットの並びが入力として与えられます。入力の終わりはゼロふたつの行で示されます。 各データセットは以下の形式で与えられます。

// x1 y1
// x2 y2
// x3 y3
// xc yc
// r
// １行目から３行目に、三角形の第 i の頂点座標 xi, yi が与えられます。４行目に円の中心の座標 xc, yc、５行目に円の半径 r が与えられます。与えられる入力はすべて、1 以上 10,000 以下の整数とします。

// データセットの数は 100 を超えません。

// Output
// 入力データセットごとに以下の形式で判定結果を１行に出力します。

// 円が三角形に含まれる場合 a
// 三角形が円に含まれる場合 b
// それ以外の場合で、共通部分がある場合には c
// 共通部分がない場合には d

// from geometry

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

class Circle {
public:
  Point o;
  double r;
  Circle(Point o = Point(0,0), double r = 0):o(o), r(r) {}
  bool operator == (const Circle &p) const {return o == p.o && r == p.r;}
};

typedef Point Vector;
typedef vector<Point> Polygon;
double dot(Vector a,Vector b){
  return a.x * b.x + a.y * b.y;
}
double cross(Vector a,Vector b){
  return a.x * b.y - a.y * b.x;
}

double distance(Point x1, Point x2, Point q) {
    // 直線に関して対称点を見つける
    Vector a = x1 - q;
    Vector b = x2 - q;
    Vector c = x1 - x2;
    double x = (a.norm() - b.norm() + c.norm()) / (2 * c.abs());
    return sqrt(a.norm() - x*x);
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
  return (x ? 2:0);
}
Point projection(Point x1, Point x2, Point q) {
    double x = dot(q - x1, x1 - x2) / (x1 - x2).norm();
    return x1 + (x1 - x2) * x;
}
bool intersect(Point a, Point b, Circle c) {
    double dist1 = (c.o-a).abs();
    double dist2 = (c.o-b).abs();
    // inside
    if (dist1 < c.r + EPS || dist2 < c.r + EPS) return 1;
    
    Point h = projection(a,b,c.o);
    if ((h-c.o).norm() - c.r * c.r > EPS) return 0;
    return dot(a-h,b-h) < 0;
}

int main() {
    Point p[4];
    while (cin >> p[0].x >> p[0].y) {
        if (p[0].x == 0 && p[0].y == 0) break;
        cin >> p[1].x >> p[1].y;
        cin >> p[2].x >> p[2].y;
        cin >> p[3].x >> p[3].y;
        double r;
        cin >> r;
        Circle c = Circle(p[3],r);
        if (distance(p[0],p[1],p[3]) > r - EPS
         && distance(p[1],p[2],p[3]) > r - EPS
         && distance(p[2],p[0],p[3]) > r - EPS
         && contains(Polygon({p[0],p[1],p[2]}),p[3]) > 0) {
           cout << "a" << endl;
        } else if ((p[0]-p[3]).norm() < r*r + EPS
        && (p[1]-p[3]).norm() < r*r + EPS
        && (p[2]-p[3]).norm() < r*r + EPS) {
          cout << "b" << endl;
        } else if (intersect(p[0],p[1],c)
        || intersect(p[1],p[2],c)
        || intersect(p[2],p[0],c)) {
          cout << "c" << endl;
        } else {
          cout << "d" << endl;
        }
    }
    return 0;
}