// 凸 n 角形の面積
// 凸 n 角形（すべての頂点の内角が 180 度未満である多角形、要するにへこんでいない多角形のこと）の頂点の座標を読んで、その面積を出力するプログラムを作成してください。頂点には辺のつながりの順序に従って頂点 1、頂点 2、頂点 3、‥‥頂点 n という名前がついています。

// ただし、 n は 3 以上 20 以下とします。また、次の、三角形の 3 辺の長さ a,b,c から面積 S を求める公式を使ってもかまいません。



// 入力
// 入力は以下の形式で与えられます。

// x1,y1
// x2,y2
// :
// xn,yn
// xi, yi はそれぞれ頂点 i の x 座標, y 座標を表す実数です。

// 出力
// 面積 S （実数）を１行に出力します。 出力は 0.000001 以下の誤差を含んでもかまいません。

// from string


#include <bits/stdc++.h>
using namespace std;
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
double triangle_area(Vector a, Vector b, Vector c) {
    double la = a.abs(), lb = b.abs(), lc = c.abs();
    double z = (la + lb + lc) / 2;
    return sqrt(z * (z - la) * (z - lb) * (z - lc));
}
double area(Polygon p) {
    double ret = 0;
    for (int i = 1; i + 1 < p.size(); i++) {
        ret += triangle_area(p[i] - p[0], p[i+1] - p[i], p[i+1] - p[0]);
    }
    return ret;
}
int main() {
    string s;
    Polygon plg;
    while (cin >> s) {
        vector<double> v = split_string_to_double(s,',');
        plg.push_back(Point(v[0],v[1]));
    }
    cout << setprecision(20) << area(plg) << endl;
    return 0;
}