// 西暦20XX 年，学校対抗魔法競技大会が開かれていた．大会もいよいよ，最終競技を残すのみとなった．あなたはその競技の選手の1 人である．

// あなたが出場する競技は，空間内に配置された青いオブジェをすべて破壊するまでの時間を競うというものである．選手は競技用の銃の持込が許可されている．空間内には複数の青いオブジェと同じ数の赤いオブジェ，そして複数の障害物が配置されている．青いオブジェと赤いオブジェは1 対1 に対応しており，赤いオブジェが配置されている座標から青いオブジェに弾を撃つことで青いオブジェを破壊しなければならない．空間内に配置されている障害物は球状であり，少しずつ組成が異なっているが，通常の弾であれば障害物に触れると弾はその場に止まってしまう．

// 競技に使われる弾はMagic Bullet という特殊な弾である．この弾は魔力をため込むことができ，弾が障害物に接触した際に自動的に魔力を消費し，弾が貫通する魔法が発動する．障害物の組成の違いから，貫通するために必要な魔法やその発動のために消費する魔力の量は異なっている．このため，ある障害物に対する魔法が発動した後であっても，別の障害物を貫通するためには新たに別の魔法を発動する必要がある．また，弾が複数の障害物に同時に接触した場合は同時に魔法が発動する．弾に込められた魔力の量は魔法の発動のたびに減少する．

// 障害物の位置や大きさ，貫通する魔法の発動に必要な魔力の量はすでに公開されているのに対し，赤いオブジェ，青いオブジェの位置は公開されていない．しかし，過去の同一競技の情報から，ある程度オブジェの位置を予想することができた．魔力を弾にこめることは非常に体力を消耗してしまうため，あなたは魔力をできるだけ節約したいと考えた．そこで，赤いオブジェとそれに対応する青いオブジェの位置を仮定して，そのときに弾にこめるべき必要な魔力の最小量，つまり，青いオブジェに到達している時点で弾に残っている魔力が0 になる魔力の量を求めよう．

// Input
// 入力はすべて整数である．それぞれの数は1 つの空白により区切られる．

// N Q
// x1 y1 z1 r1 l1
// :
// xN yN zN rN lN
// sx1 sy1 sz1 dx1 dy1 dz1
// :
// sxQ syQ szQ dxQ dyQ dzQ
// N は障害物の個数であり，Q は仮定した青いオブジェと赤いオブジェの座標の組の個数である．
// xi, yi, zi はそれぞれ i 個目の障害物の中心の位置を表す x 座標，y 座標，z 座標である．
// ri は i 個目の障害物の半径である．
// li は i 個目の障害物を貫通するための魔法で消費する魔力の量である．
// sxj, syj, szj はそれぞれ j 番目の仮定における赤いオブジェの位置を表す x 座標，y 座標，z 座標である．
// dxj, dyj, dzj はそれぞれ j 番目の仮定における青いオブジェの位置を表す x 座標，y 座標，z 座標である．
// Constraints
// 0 ≤ N ≤ 50
// 1 ≤ Q ≤ 50
// -500 ≤ xi,yi,zi ≤ 500
// 1 ≤ ri ≤ 1,000
// 1 ≤ li ≤ 1016
// -500 ≤ sxj,syj,szj ≤ 500
// -500 ≤ dxj,dyj,dzj≤500
// 障害物が他の障害物にめり込んでいることはない
// オブジェの座標は障害物の内部，表面にはない
// それぞれの仮定において，赤いオブジェと青いオブジェの座標は一致しない
// Output
// それぞれ1 組の赤いオブジェとそれに対応する青いオブジェの位置の仮定において，空間中に障害物と赤いオブジェと青いオブジェ1 対とのみがあるものとして，弾にこめるべき魔力の量を1 行に出力せよ．弾は赤いオブジェの位置から青いオブジェの位置まで一直線に飛ぶものとし，弾の大きさは非常に小さいので点として扱う．

#include <bits/stdc++.h>
using namespace std;

#define EPS (1e-10)
class Point3D {
public:
  double x,y,z;
  Point3D(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}

  Point3D operator + (Point3D p){return Point3D(x+p.x,y+p.y,z+p.z);}
  Point3D operator - (Point3D p){return Point3D(x-p.x,y-p.y,z-p.z);}
  Point3D operator * (double k){return Point3D(x*k,y*k,z*k);}
  Point3D operator / (double k){return Point3D(x/k,y/k,z/k);}

  double norm(){return x*x+y*y+z*z;}
  double abs(){return sqrt(norm());}

  bool operator <(const Point3D &p) const {
      return x!=p.x ? x<p.x : (y!=p.y ? y<p.y : z<p.z);
  }
  bool operator == (const Point3D &p) const{
    return fabs(x-p.x) < EPS && fabs(y-p.y) < EPS && fabs(z-p.z) < EPS;
  }
  void out() {
    cout << x << " " << y << " " << z << endl;
  }
};

class Circle3D {
public:
  Point3D o;
  double r;
  Circle3D(Point3D o = Point3D(0,0,0), double r = 0):o(o), r(r) {}
  bool operator == (const Circle3D &p) const {return o == p.o && r == p.r;}
};

double dot (Point3D a, Point3D b) {
  return a.x * b.x + a.y * b.y + a.z * b.z;
}

Point3D cross (Point3D a, Point3D b) {
  return Point3D(a.y*b.z-a.z*b.y, a.z*b.x-a.x*b.z, a.x*b.y-a.y*b.x);
}

bool intersect(Circle3D c, Point3D a, Point3D b) {
    if ((a-c.o).abs() < c.r + EPS || (b-c.o).abs() < c.r + EPS) return 1;
    b = b - a;
    Point3D o = c.o - a;
    Point3D h = b * dot(o,b) / b.norm();
    // b.out();o.out();h.out();
    // cout << (h-o).abs() << endl;
    if ((h-o).abs() > c.r + EPS) return 0;

    Point3D eb = b / b.abs();
    Point3D eh = h / h.abs();
    if ((eb - eh).abs() > EPS) return 0;

    return b.abs() + EPS > h.abs();
}

int n,q;
Circle3D p[55];
long long l[55];
Point3D s,t;

int main() {
    cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> p[i].o.x >> p[i].o.y >> p[i].o.z >> p[i].r >> l[i];
    for (int i = 0; i < q; i++) {
        cin >> s.x >> s.y >> s.z >> t.x >> t.y >> t.z;
        long long ans = 0;
        for (int j = 0; j < n; j++) {
            if (intersect(p[j],s,t)) ans += l[j];
        }
        cout << ans << endl;
    }
}