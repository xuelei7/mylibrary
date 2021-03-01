// 宝探し II
// 蔵を片付けていたら、先祖の宝のありかへの行き方を記した古文書が見つかりました。この古文書にはおおよそ次のような事が書かれていました。

// 1. まず、町外れの井戸から、真東に 1m の地点に立ち、まっすぐ井戸の方向を向け。
// 2. 右回りに 90 度向きを変え、1m 直進したら、まっすぐ井戸の方向を向け。
// 3. 右回りに 90 度向きを変え、1m 直進したら、まっすぐ井戸の方向を向け。
// 4.                   〃
// 5.                   〃
// 6.                   ：
// 2 行目以降は、全く同じことが書かれていました。あなたは、宝を探そうと思いましたが、厄介なことに気がつきました。昔と違い建物が邪魔をしていて、まっすぐ井戸の方向をむこうにも井戸が見えなかったり 1m 直進しようにも直進できなかったりします。さらに、この古文書ときたら、1000 行近くあり、古文書どおりの作業をすることは、かなりの時間と体力が要ります。しかしながら、幸運なことに、あなたはコンピュータを利用することができます。

// 古文書に書かれている行数 n を入力して、宝のありかを出力するプログラムを作成してください。ただし、 n は 2 以上 1,000 以下の正の整数とします。

// 入力
// 複数のデータセットが与えられます。各データセットとして、古文書の行数を表す１つの整数 n が１行に与えられます。

// 入力は -1 で終わります。データセットの数は 50 を超えません。

// 出力
// 町外れの井戸から東に x (m)，北に y (m)の位置に宝があるとして、 各データセットごとに以下の形式で出力して下さい。

// x
// y
// 出力は実数とし、0.01 以下の誤差を含んでもよい。

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
typedef Point Vector;
typedef vector<Point> Polygon;
double dot(Vector a,Vector b){
  return a.x * b.x + a.y * b.y;
}
double cross(Vector a,Vector b){
  return a.x * b.y - a.y * b.x;
}
int main() {
    int n;
    while (cin >> n) {
        if (n == -1) break;
        Point p(1,0);
        n--;
        for (int i = 0; i < n; i++) {
            Point tp(-p.y,p.x);
            tp = tp / tp.abs();
            p = p + tp;
        }
        cout << setprecision(20) << p.x << " " << p.y << endl;
    }
    return 0;
}