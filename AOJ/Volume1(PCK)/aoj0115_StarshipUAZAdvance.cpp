// 宇宙船 UAZ アドバンス号
// 恒星歴 2005.11.5。あなたは宇宙船 UAZ アドバンス号の艦長として敵の宇宙船と交戦しようとしています。 幸い敵の宇宙船はまだこちらに気付かずに静止しています。また、すでに敵の宇宙座標は判明しており強力な直線のビームを放つ「フェザー砲」は発射準備を完了しています。あとは、発射命令を出すばかりです。

// ところが、宇宙空間には、敵の設置したエネルギーバリアが存在しています。バリアは三角形をしており「フェザー砲」のビームをはね返してしまいます。また、ビームがバリアに当たれば敵に気付かれて逃げられてしまいます。事前に命中すると判定できなければ、発射命令は出せません。

// そこで、UAZ アドバンス号、敵、バリアの位置の宇宙座標(3次元座標 x, y, z) を入力して、ビームがバリアをさけて敵に命中する場合は "HIT"、バリアに当たってしまう場合"MISS"と出力するプログラムを作成してください。

// ただし、バリアはアドバンス号から 3 角形に見えるものだけが対象であり、線分につぶれて見えるものはないものとします。また、バリアは 3 角形の頂点を含む境界でも有効であり、ビームをはね返すものとします。また、敵がバリア内にいる場合は"MISS"と出力して下さい。

// Input
// 入力データの形式は以下のとおりです：

// 1 行目は、UAZ アドバンス号の座標 (x, y, z) (整数、半角空白区切り)
// 2 行目は、敵の座標 (x, y, z) (整数、半角空白区切り)
// 3 行目は、バリアの頂点 1 の座標 (x, y, z) (整数、半角空白区切り)
// 4 行目は、バリアの頂点 2 の座標 (x, y, z ) (整数、半角空白区切り)
// 5 行目は、バリアの頂点 3 の座標 (x, y, z ) (整数、半角空白区切り)
// Output
// HIT または MISS と１行に出力してください。

// to geometry

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
};

double dot (Point3D a, Point3D b) {
  return a.x * b.x + a.y * b.y + a.z * b.z;
}

Point3D cross (Point3D a, Point3D b) {
  return Point3D(a.y*b.z-a.z*b.y, a.z*b.x-a.x*b.z, a.x*b.y-a.y*b.x);
}

int main() {
    Point3D p[5];
    for (int i = 0; i < 5; i++) cin >> p[i].x >> p[i].y >> p[i].z;
    // 平面の法線
    Point3D n = cross(p[3] - p[2], p[4] - p[2]);
    // p[0]p[1]がnにおける射影の長さ
    double s = dot(p[1] - p[0], n);
    // バリアと平行ならHIT
    if (abs(s) < EPS) {
        cout << "HIT" << endl;
        return 0;
    }

    // p[0]p[2]がnにおける射影の長さ --p[0]からバリアの距離
    double r = dot(p[2] - p[0], n);
    double t = r / s;
    // 起点と終点がバリアの同じ側にあるならHIT
    if (t < -EPS || t > 1.0 + EPS) {
        cout << "HIT" << endl;
        return 0;
    }
    
    // p[0]p[1]とバリアの交点
    Point3D c = p[0] * (1 - t) + p[1] * t;
    // 交点がバリア内にあるかを判断する
    Point3D d = cross(p[3] - p[2], c - p[2]);
    Point3D e = cross(p[4] - p[3], c - p[3]);
    Point3D f = cross(p[2] - p[4], c - p[4]);
    if (dot(d,e) < -EPS || dot(d,f) < -EPS) {
        cout << "HIT" << endl;
        return 0;
    }
    cout << "MISS" << endl;
    return 0;
}