// 牽牛と織女
// 織女は天帝の子供でしたが、父の言いつけであけてもくれても機を織っていました。

// 織女の織る雲錦という見事な布で仕立てた服を着るのが天帝の楽しみでした。雲錦は寿命が短くすぐに劣化してしまいますが、働き者の織女が毎日織ってくれるので、問題はありませんでした。織女は、父の言いつけを守り、毎日毎日雲錦を織り続けていたので、ボーイフレンドはいませんでした。かわいそうに思った父は、天の川の向こう岸に住む牽牛という働き者を紹介し、嫁入りさせました。

// すると、織女は、結婚の楽しさに夢中になって、機織りなどそっちのけで、牽牛と遊び呆けています。天帝のお気に入りの雲錦の服も新しく仕立てられないためボロボロになってしまいました。

// これには父も怒って、織女を宮殿に連れ戻したいと思いました。しかし人間である牽牛の前にボロボロの服で姿を現すわけにはいきません。遊び呆けている二人を 3 角形の壁で遮断し自分以外の全てのものが行き来できなくすることを考えました。そして、牽牛に見つからずに、織女に会って、まじめに機を織るか、さもなければ強制的に連れ帰ると宣言するというのです。



// 天帝はこの作戦を遂行するために 3 角形の壁生成装置を開発することにしました。3 角形の 3 頂点の位置 (xp1,yp1), (xp2,yp2), (xp3,yp3)、牽牛の位置 (xk,yk)、および織女の位置 (xs,ys)、を入力とし、三角形が牽牛と織女を遮断しているか否かを判定し、遮断できている場合は OK、遮断できていない場合には NG を出力するプログラムを作成してください。ただし、遮断しているとは、牽牛と織女のいずれかが三角形の内側にあり、他方が外側にある場合を言います。牽牛と織女は三角形の頂点もしくは辺の上にはいないものとします。

// 織女と牽牛は時々刻々場所を変えるため、プログラムは様々な位置情報を入力し質問に答えなければなりません。

// Input
// 入力は以下の形式で与えられます。

// n
// query1
// query2
// :
// queryn
// １行目に判別したい情報の個数 n (n ≤ 10000)、続く n 行に i 番目の質問 queryi が与えられます。各質問は以下の形式で与えられます。

// xp1 yp1 xp2 yp2 xp3 yp3 xk yk xs ys
// 各質問として、3 角形の 3 頂点の位置、牽牛の位置、および織女の位置 (-1000 ≤ xp1, yp1, xp2, yp2, xp3, yp3, xk, yk, xs, ys ≤ 1000) が１行に与えられます。入力はすべて整数です。

// Output
// 質問ごとに、判定結果 OK または NG を１行に出力してください。

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

int main() {
    int n;
    cin >> n;
    while (n--) {
        Point p[5];
        for (int i = 0; i < 5; i++) cin >> p[i].x >> p[i].y;
        Polygon pg;
        pg.push_back(p[0]);
        pg.push_back(p[1]);
        pg.push_back(p[2]);
        int a = contains(pg, p[3]);
        int b = contains(pg, p[4]);
        cout << (a != b? "OK":"NG") << endl;
    }
    return 0;
}