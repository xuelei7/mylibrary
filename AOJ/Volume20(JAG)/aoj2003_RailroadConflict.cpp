// Railroad Conflict
// Nate U. Smith は大都市圏の鉄道会社を経営している．この大都市圏には，彼の鉄道会社以外にライバルの鉄道会社がある．2 社は互いに競合関係にある．

// この大都市圏では，列車の運行を容易にするため，全ての路線は両端の駅を結んだ線分を経路としている．また，踏切等の設置をさけるため，全ての路線は高架または地下に敷設されている．既存路線は，全線にわたって高架を走るか，または全線にわたって地下を走るかのいずれかである．

// ところで，最近，この大都市圏にある 2 つの街区 A，B がさかんに開発されていることから，Nate の会社ではこれらの街区の間に新しい路線を設けることを決断した．この新路線は，従来の路線と同様に A，B を両端とする線分を経路としたいが，経路の途中には別の路線があることから，高架あるいは地下のいずれかに全線を敷設することは不可能である．そこで，路線の一部を高架に，残りの部分を地下に敷設することにした．このとき，新路線が自社の既存路線と交わるところでは，新路線と既存路線との間の乗り継ぎを便利にするため，既存路線が高架ならば新路線も高架に，既存路線が地下ならば新路線も地下を走るようにする．また，新路線が他社の既存路線と交わるところでは，他社による妨害をさけるため，既存路線が高架ならば新路線は地下に，既存路線が地下ならば新路線は高架を走るようにする．A 駅および B 駅をそれぞれ高架あるいは地下のいずれに設けるかは特に問わない．

// 当然のことながら，新路線が高架から地下に，あるいは地下から高架に移るところには出入口を設けなければならない．ところが，出入口を設けるためには費用がかかるため，新路線に設ける出入口の個数は最小限に抑えたい．それには，プログラマであるあなたの助けを要すると考えた Nate は，あなたを彼の会社に呼び出した．

// あなたの仕事は，A 駅，B 駅の位置，そして既存路線に関する情報が与えられたときに，新路線において最低限設けなければならない出入口の個数を求めるプログラムを作成することである．

// 以下の図は，サンプルとして与えた入力および出力の内容を示したものである．



// Input
// 入力の先頭行には単一の正の整数が含まれ，これはデータセットの個数を表す．それぞれのデータセットは次の形式で与えられる．

// xa ya xb yb
// n
// xs1 ys1 xt1 yt1 o1 l1
// xs2 ys2 xt2 yt2 o2 l2
// ...
// xsn ysn xtn ytn on ln
// ただし，(xa,ya) および (xb,yb) はそれぞれ A 駅，B 駅の座標を表す．N は既存路線の数を表す 100 以下の正の整数である．(xsi,ysi) および (ysi,yti) は i 番目の既存路線における始点および終点の座標を表す．oi は i 番目の既存路線の所有者を表す整数である．これは 1 または 0 のいずれかであり，1 はその路線が自社所有であることを，0 は他社所有であることをそれぞれ表す．li は i 番目の既存路線が高架または地下のいずれにあるかを表す整数である．これも 1 または 0 のいずれかであり，1 はその路線が高架にあることを，0 は地下にあることをそれぞれ表す．
// 入力中に現れる x 座標および y 座標の値は -10000 から 10000 の範囲にある（両端も範囲に含まれる）．また，それぞれのデータセットにおいて，新路線を含めた全ての路線に対して，以下の条件を満たすと仮定してよい．ここで 2 点が非常に近いとは，その 2 点間の距離が 10-9 以下であることを表す．

// ある交点の非常に近くに別の交点があることはない．
// ある路線の端点の非常に近くを別の路線が通ることはない．
// 2 つの路線の一部または全部が重なることはない．
// Output
// それぞれのデータセットに対して，最低限設けなければならない出入口の個数を 1 行に出力しなさい．

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
// judge the relation between vector(p0, p1) and vector(p0, p2)
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
bool intersect(Point p1,Point p2,Point p3,Point p4){
  return (ccw(p1,p2,p3) * ccw(p1,p2,p4) <= 0 &&
	  ccw(p3,p4,p1) * ccw(p3,p4,p2) <= 0 );
}
Point getCrossPoint(Point a, Point b, Point c, Point d) {
  Vector base = d - c;
  double d1 = abs(cross(base,a-c));
  double d2 = abs(cross(base,b-c));
  double t = d1 / (d1+d2);
  return a + (b-a) * t;
}

Point s,t;
Point p[2][110];
bool o[110],l[110];
void solve() {
    cin >> s.x >> s.y >> t.x >> t.y;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> p[0][i].x >> p[0][i].y >> p[1][i].x >> p[1][i].y >> o[i] >> l[i];
    vector<pair<double,bool>> v;
    for (int i = 0; i < n; i++) {
        bool f = intersect(s,t,p[0][i], p[1][i]);
        if (!f) continue;
        Point e = getCrossPoint(s,t,p[0][i], p[1][i]);
        bool status;
        if (o[i] == 1) status = l[i];
        else status = !l[i];
        v.push_back({(e-s).abs()/(t-s).abs(),status});
    }
    sort(v.begin(),v.end());
    if (v.size() == 0) {
      cout << 0 << endl;
      return;
    }
    int ans = 0;
    bool status = v[0].second;
    for (int i = 1; i < v.size(); i++) {
      if (v[i].second != status) {
        ans++;
        status = !status;
      }
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}