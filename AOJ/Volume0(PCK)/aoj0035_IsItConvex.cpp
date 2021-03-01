// 凸？
// 平面上の異なる 4 点　A(xa,ya), B(xb,yb), C(xc,yc), D(xd,yd) の座標を読み込んで、それら 4 点を頂点とした四角形 ABCD に凹みがなければ YES、凹みがあれば NO と出力するプログラムを作成してください。

// 凹みのある四角形とは図 1 のような四角形です。

// Input
// 複数のデータセットが与えられます。各データセットの形式は以下のとおりです。

// xa,ya,xb,yb,xc,yc,xd,yd

// xa, ya, xb, yb, xc, yc, xd, yd はそれぞれ -100 以上 100 以下であり、実数で与えられます。

// 1 直線上に 3 つ以上点が並ぶことはないものとします。また、入力順に点を結んでいけば、四角形になる順番に点の座標が入力されるものとします。（つまり、図 2 のような形になる順番で点が与えられることはありません。)

// データセットの数は 100 を超えません。

// Output
// 各データセットごとに、YES または NO を１行に出力します。

// to string, geometry

// returns if a polygon contains a point
#include <bits/stdc++.h>
using namespace std;
#define EPS (1e-10)
class Point{
public:
  double x,y;
  Point(double x = 0, double y = 0):x(x), y(y) {}
  Point operator + (Point p){
    return Point(x+p.x,y+p.y);
  }
  Point operator - (Point p){
    return Point(x-p.x,y-p.y);
  }
  Point operator * (double k){
    return Point(x*k,y*k);
  }
  Point operator / (double k){
    return Point(x/k,y/k);
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

int main() {
    string s;
    while (cin >> s) {
        vector<double> v = split_string_to_double(s, ',');
        Point p[4];
        for (int i = 0; i < 4; i++) {
            p[i].x = v[i*2];
            p[i].y = v[i*2+1];
        }
        bool f = 1;
        for (int i = 0; i < 4; i++) {
            Polygon g;
            for (int j = 0; j < 4; j++) {
                if (i != j) g.push_back(p[j]);
            }
            if (contains(g,p[i]) == 2) f = 0;
        }
        cout << (f?"YES":"NO") << endl;
    }
    return 0;
}