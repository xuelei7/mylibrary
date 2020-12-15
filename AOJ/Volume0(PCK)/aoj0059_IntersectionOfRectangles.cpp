// 長方形の重なり
// 底辺が x 軸に対して平行な 2 つの長方形があります。長方形 A の左下の座標 (xa1, ya1) と右上の座標 (xa2, ya2)、長方形 B の左下の座標 (xb1, yb1) と右上の座標 (xb2, yb2) を読み込んで、長方形 A と長方形 B が一部でも重なっていれば YES を、まったく重なっていなければ NO を出力するプログラムを作成してください。ただし、長方形 A と長方形 B は同じものではないとします。また、接しているものも重なっているとみなします。

// Input
// 複数のデータセットが与えられます。各データセットの形式は以下のとおりです。

// xa1 ya1 xa2 ya2 xb1 yb1 xb2 yb2
// 入力される値はそれぞれ -2,000 以上 2,000 以下であり、各値は小数点以下最大 5 桁までの数字を含む実数で与えられます。

// データセットの数は 50 を超えません。

// Output
// 各データセットに対して、YES または NO を１行に出力して下さい。

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
int main() {
    Point p[4];
    while (cin >> p[0].x >> p[0].y >> p[1].x >> p[1].y >> p[2].x >> p[2].y >> p[3].x >> p[3].y) {
        if (p[0].x > p[2].x) {
            swap(p[0],p[2]);
            swap(p[1],p[3]);
        }
        Point b = Point(p[1].x, p[0].y);
        Point a = Point(p[2].x, p[3].y);
        Point c = Point(p[0].x, p[1].y);
        Point d = Point(p[3].x, p[2].y);
        if (a.x <= b.x && a.y >= b.y && c.x <= d.x && c.y >= d.y) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}