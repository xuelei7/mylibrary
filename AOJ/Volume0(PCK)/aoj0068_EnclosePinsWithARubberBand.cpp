// n 本の釘を平板上の座標 P1 (x1, y1), P2 (x2, y2), P3 (x3, y3),..., Pn (xn, yn) に１本ずつ打ち、輪ゴムの輪の中に全ての釘が入るように 1 本の輪ゴムで囲みます。このとき、輪ゴムが交差してはいけません。

// 釘の座標を読み込んで、上記のように釘を輪ゴムで囲んだときに輪ゴムに接していない釘の本数を出力するプログラムを作成してください。輪ゴムは充分に伸び縮みするものとします。同じ座標に 2 本以上の釘を打つことはないものとします。また、輪ゴムがかかった釘と釘の間は直線で結ばれるものとし、その直線上に 3 本以上の釘が並ぶことはないものとします。例えば、図 1 に示すような入力はありえません。図 2 に示すように輪ゴムがかかっていない釘が 1 直線上に並ぶことはありえます。

// ただし、それぞれの座標値は -1000.0 以上1000.0 以下の実数です。また、n は 3 以上 100 以下の整数です。

// Input
// 複数のデータセットが与えられます。各データセットは以下のような形式です与えられます。

// n  
// x1, y1
// x2, y2
// ... 　　　　
// ...
// xn, yn
// n が 0 の時、入力の最後を示します。データセットの数は 50 を超えません。

// Output
// データセットごとに、ゴムと接していない釘の本数を出力してください。 例えば、図 3 に示す４つの釘を表す入力があった場合、図 4 のように囲まれるので、輪ゴムに接していない釘の本数は 1 本です。

// to geometry, from string

#include <bits/stdc++.h>
using namespace std;
#define EPS (1e-10)

static const int COUNTER_CLOCKWISE = 1;
static const int CLOCKWISE = -1;
static const int ONLINE_BACK = 2;
static const int ONLINE_FRONT = -2;
static const int ON_SEGMENT = 0;

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
int ccw(Point p0,Point p1,Point p2){
  Vector a = p1-p0;
  Vector b = p2-p0;
  if(cross(a,b) > EPS) return COUNTER_CLOCKWISE;
  if(cross(a,b) < -EPS) return CLOCKWISE;
  if(dot(a,b) < -EPS) return ONLINE_BACK;
  if(a.norm()<b.norm()) return ONLINE_FRONT;
  return ON_SEGMENT;
}
int andrewScan(Polygon s){
  Polygon u,l;
  if(s.size()<3) return s.size();
  sort(s.begin(),s.end());
  u.push_back(s[0]);
  u.push_back(s[1]);
  l.push_back(s[s.size()-1]);
  l.push_back(s[s.size()-2]);

  for(int i=2;i<s.size();i++){
    for(int n=u.size();n>=2&&ccw(u[n-2],u[n-1],s[i]) != CLOCKWISE;n--){
      u.pop_back();
    }
    u.push_back(s[i]);
  } 
  for(int i=s.size()-3;i>=0;i--){
    for(int n=l.size();n>=2&&ccw(l[n-2],l[n-1],s[i]) != CLOCKWISE;n--){
      l.pop_back();
    }
    l.push_back(s[i]);
  }

  reverse(l.begin(),l.end());
  for(int i=u.size()-2;i>=1;i--) l.push_back(u[i]);
  return l.size();
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
    int n;
    while (cin >> n) {
        if (n == 0) break;
        string s;
        Polygon plg;
        for (int i = 0; i < n; i++) {
            cin >> s;
            vector<double> v = split_string_to_double(s,',');
            plg.push_back(Point(v[0],v[1]));
        }
        cout << n - andrewScan(plg) << endl;
    }
    return 0;
}