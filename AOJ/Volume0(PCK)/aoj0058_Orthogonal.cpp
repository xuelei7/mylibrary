// 直交判定
// 平面上の異なる 4 点、A(xA,yA), B(xB,yB), C(xC,yC), D(xD,yD) の座標を読み込んで、直線 AB と CD が直交する場合には YES、直交しない場合には NO と出力するプログラムを作成してください。ここで、「直線」とは線分のことではありません。以下の図を参考にして下さい。

// Input
// 複数のデータセットが与えられます。各データセットの形式は以下のとおりです。

// xA yA xB yB xC yC xD yD

// xA, yA, xB, yB, xC, yC, xD, yD はそれぞれ -100 以上 100 以下であり、各値は小数点以下最大 5 桁までの数字を含む実数で与えられます。

// データセットの数は 100 を超えません。

// Output
// 各データセットに対して、YES または NO を１行に出力して下さい。

// geometry

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
bool orthogonal(Vector a, Vector b) {
  return abs(dot(a,b)) <= EPS;
}
int main() {
    Point p[4];
    while (cin >> p[0].x >> p[0].y >> p[1].x >> p[1].y >> p[2].x >> p[2].y >> p[3].x >> p[3].y) {
        Vector a = p[0] - p[1];
        Vector b = p[2] - p[3];
        cout << (orthogonal(a,b)? "YES": "NO") << endl;
    }
    return 0;
}