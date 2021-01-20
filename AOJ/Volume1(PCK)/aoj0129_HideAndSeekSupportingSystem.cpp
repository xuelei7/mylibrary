// かくれんぼう
// たろう君はかくれんぼうが苦手です。隠れるとすぐ見つかっちゃうし、隠れている子をなかなか見つけることができません。見かねたお父さんは、超高性能位置探索システムを作ってくれました。これを使うと自分の位置を含めて、友達の位置を正確に知ることができます。鬼になったら、隠れている子を探すことが簡単にできるようになりました。

// たろう君はさらにこのシステムを進化させ、鬼から自分が見えるか否かを判定する機能を付加することを思いつきました。これができれば、「もういいかい」と言われても、見える位置にいれば「まあだだよ」だし、見えない位置にいれば「もういいよ」ですね。いつも遊んでいる公園には大小さまざまな円筒形の壁があります。この壁は外からは中は見えないし、中から外も見えません。鬼と一緒に中に入ると別の壁がなければ見えちゃいます。



// たろう君はアイデアはいいのですが、ソフトを作るのが苦手です。そこで親友のあなたはたろう君に代わって、「鬼から見えないこと確認システム」のソフトウェアを作ることになりました。公園の壁は固定されていますが、たろう君と鬼のいろいろな位置情報に対して見えるか否かを判定する必要があります。

// 公園にある壁の情報(中心の座標 (wx, wy) と 半径 r) とたろう君と鬼の位置情報(たろう君の位置の座標 (tx, ty) と鬼の位置の座標 (sx, sy) ) を入力とし、その位置で鬼からたろう君が見えるか否かを判定するプログラムを作成してください。

// なお、鬼からたろう君が見える場合には Danger、見えない場合には Safe と出力してください。鬼とたろう君の位置を結んだ線分上に壁がある場合には見えないものとし、鬼もたろう君も壁の上にはいないものとします。

// Input
// 複数のデータセットが与えられます。各データセットは以下の形式で与えられます。

// n
// wx1 wy1 r1
// wx2 wy2 r2
// :
// wxn wyn rn
// m
// tx1 ty1 sx1 sy1
// tx2 ty2 sx2 sy2
// :
// txm tym sxm sym
// 1 行目に円筒形の壁の数 n (0 ≤ n ≤ 100)、続く n 行に壁 i の中心の座標を表す整数 wxi, wyi (0 ≤ wxi, wyi ≤ 255) と半径を表す整数 ri (1 ≤ ri ≤ 255) が与えられます。

// 続く行にたろう君と鬼の位置情報の個数 m (m ≤ 100)、続く m 行に位置情報 i のたろう君の位置の座標を表す整数 txi, tyi (0 ≤ txi, tyi ≤ 255) と鬼の位置の座標を表す整数 sxi, syi (0 ≤ sxi, syi ≤ 255) が与えられます。

// また、円筒形の壁の一部だけが公園にあるということはなく、全ての壁は円筒として、公園の内部に入っています。

// n が 0 のとき入力の終わりを示します。データセットの数は 20 を超えません。

// Output
// 各データセットについて、位置情報 i の判定結果 Danger または Safe を i 行目に出力してください。

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
  Circle(Point o = Point(0,0), double r = 0):o(o), r(r) {}
  bool operator == (const Circle &p) const {return o == p.o && r == p.r;}
};

Point projection(Point x1, Point x2, Point q) {
    double x = dot(q - x1, x1 - x2) / (x1 - x2).norm();
    return x1 + (x1 - x2) * x;
}

int n,m;
Circle p[110];

bool intersect(Point a, Point b, Circle c) {
    double dist1 = (c.o-a).abs();
    double dist2 = (c.o-b).abs();
    // both inside
    if (dist1 < c.r + EPS && dist2 < c.r + EPS) return 0;
    // in and out
    if (dist1 < c.r - EPS && dist2 > c.r + EPS) return 1;
    if (dist1 > c.r + EPS && dist2 < c.r - EPS) return 1;
    
    Point h = projection(a,b,c.o);
    if ((h-c.o).norm() - c.r * c.r > EPS) return 0;
    return dot(a-h,b-h) < 0;
}

int main() {
    while (cin >> n) {
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            cin >> p[i].o.x >> p[i].o.y >> p[i].r;
        }
        cin >> m;
        for (int i = 0; i < m; i++) {
            bool danger = 1;
            Point t,s;
            cin >> t.x >> t.y >> s.x >> s.y;
            for (int j = 0; j < n; j++) {
                if (intersect(t,s,p[j])) {
                    danger = 0;
                    break;
                }
            }
            cout << (danger? "Danger":"Safe") << endl;
        }
    }
    return 0;
}