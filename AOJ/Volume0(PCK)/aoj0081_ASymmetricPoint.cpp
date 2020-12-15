// 線対称
// 平面上の異なる 3 点 P1(x1,y1), P2(x2,y2), Q(xq,yq) の座標の組を読み込んで、点 P1 点P2 を通る直線を対称軸として点 Q と線対称の位置にある点 R(x,y) を出力するプログラムを作成してください。なお、点 Q は、その対称軸上にないものとします。


// 入力
// 入力は複数のデータセットからなります。各データセットは以下の形式で与えられます。

// x1,y1,x2,y2,xq,yq
// x1, y1, x2, y2, xq, yq (-100 以上 100 以下の実数) がカンマ区切りで１行に与えられます。

// データセットの数は 50 を超えない。

// 出力
// データセットごとに、x, y を空白区切りで 1 行に出力する。出力は実数で 0.0001 以下の誤差を含んでもよい。

// geometry,string

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
vector<double> split_string_to_double (string s, char c) {
    for (int i = 0; i < s.size(); i++) if (s[i] == c) s[i] = ' ';
    stringstream ss(s);
    vector<double> ret;
    double num;
    while (ss >> num) {
        ret.push_back(num);
    }
    return ret;
}
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
Point symmetric_point(Point x1, Point x2, Point q) {
    Vector a = x1 - q;
    Vector b = x2 - q;
    Vector c = x1 - x2;
    double x = (a.norm() - b.norm() + c.norm()) / (2 * c.abs());
    double dist = sqrt(a.norm() - x*x);
    Vector dir = Point(-c.y,c.x);
    dir = dir / dir.abs() * dist * 2;
    Point p1 = q + dir;
    Point p2 = q - dir;
    if (ccw(x1,x2,q) != ccw(x1,x2,p1)) return p1;
    else return p2;
}
int main() {
    string s;
    while (cin >> s) {
        vector<double> v = split_string_to_double(s,',');
        Point x1(v[0],v[1]), x2(v[2],v[3]), q(v[4],v[5]);
        Vector a = x1 - q;
        Vector b = x2 - q;
        Vector c = x1 - x2;
        double x = (a.norm() - b.norm() + c.norm()) / (2 * c.abs());
        double dist = sqrt(a.norm() - x*x);
        Vector dir = Point(-c.y,c.x);
        dir = dir / dir.abs() * dist * 2;
        Point p1 = q + dir;
        Point p2 = q - dir;
        if (ccw(x1,x2,q) != ccw(x1,x2,p1)) {
            cout << setprecision(20) << p1.x << " " << p1.y << endl;
        } else {
            cout << setprecision(20) << p2.x << " " << p2.y << endl;
        }
    }
    return 0;
}