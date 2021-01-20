// from
// aoj0003
// given 3 length of edges, judge whether these edges forms a RIGHT triangle
bool isRightTriangle(int a, int b, int c) {
    if (b > a) {
        int k = b;
        b = a;
        a = k;
    }
    if (c > a) {
        int k = c;
        c = a;
        a = k;
    }
    return a * a == b * b + c * c;
}

// from
// aoj0010
// 三角形の頂点座標から外接円の円心座標と半径を求める
pair<pair<double,double>, double> CircumscribedCircleOfATriangle(double x1, double y1, double x2, double y2, double x3, double y3) {
    double px,py,r;
    py = ((x1-x3) * (x1*x1 - x2*x2 + y1*y1 - y2*y2) - (x1-x2) * (x1*x1 - x3*x3 + y1*y1 - y3*y3)) / (2 * ((y1-y2)*(x1-x3) - (y1-y3)*(x1-x2)));
    if (x1 != x2) px = (x1*x1 - x2*x2 + y1*y1 - y2*y2) / (2 * (x1-x2)) - py * (y1-y2) / (x1-x2);
    else px = (x1*x1 - x3*x3 + y1*y1 - y3*y3) / (2 * (x1-x3)) - py * (y1-y3) / (x1-x3);
    r = sqrt((x1 - px) * (x1 - px) + (y1 - py) * (y1 - py));
    return {{px,py},r};
}

// from
// aoj0012, aoj0035, aoj0059, aoj0068, aoj0076, aoj0079, aoj0081, aoj0090
// returns if a polygon contains a point
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
// from aoj0021
bool parallel(Vector a, Vector b) {
  return abs(cross(a,b)) < EPS;
}
// from aoj0058
bool orthogonal(Vector a, Vector b) {
  return abs(dot(a,b)) <= EPS;
}
// from aoj0068, aoj0081
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
// return the number of points on the convex
Polygon andrewScan(Polygon s){
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
  return l;
}

// from aoj0079
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
// from aoj0081
Point symmetric_point(Point x1, Point x2, Point q) {
    // 直線に関して対称点を見つける
    Vector a = x1 - q;
    Vector b = x2 - q;
    Vector c = x1 - x2;
    double x = (a.norm() - b.norm() + c.norm()) / (2 * c.abs());
    double dist = sqrt(a.norm() - x*x);
    Vector dir = Point(-c.y,c.x);
    dir = dir / dir.abs() * dist * 2;
    Point p1 = q + dir;
    Point p2 = q - dir;
    if (ccw(x1,x2,q) != ccw(x1,x2,p1)) return p1;
    else return p2;
}
// from aoj0129
Point projection(Point x1, Point x2, Point q) {
    double x = dot(q - x1, x1 - x2) / (x1 - x2).norm();
    return x1 + (x1 - x2) * x;
}
// from
// aoj0023, aoj0090
class Circle {
public:
  Point o;
  double r;
  Circle(Point o = Point(0,0), double r = 0):o(o), r(r) {}
  bool operator == (const Circle &p) const {return o == p.o && r == p.r;}
};
// return the relation ship between 2 circles
// 1: intersect, 0: outside, 2: B in A, -2: A in B
int intersection(Circle a, Circle b) {
  double dist = (a.o-b.o).abs();
  // 交叉
  if (dist >= abs(a.r - b.r) && dist <= a.r + b.r) {
    return 1;
  }
  // 外部
  if (dist > a.r + b.r) {
    return 0;
  }
  // 内部
  if (b.r < a.r) return 2;
  else return -2;
}
// from aoj0090
vector<Point> intersect_points(Circle a, Circle b) {
    if (a == b || intersection(a,b) != 1) return vector<Point>();
    double r1 = a.r, r2 = b.r, dist = (a.o - b.o).abs();
    double x = (r1 * r1 - r2 * r2 + dist * dist) / (2 * dist);
    double h = sqrt(r1 * r1 - x * x);
    Vector dx = b.o - a.o;
    dx = dx / dist * x;
    Vector dir = Vector(-dx.y, dx.x);
    dir = dir / dir.abs() * h;
    Point p1 = a.o + dx + dir;
    Point p2 = a.o + dx - dir;
    if ((p1-p2).abs() < EPS) return {p1};
    else return {p1,p2};
}
// from aoj0129
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
// from
// aoj0012
// return if the triangle contains a point
bool trangleContainsPoint(double x1, double y1, double x2, double y2, double x3, double y3, double xp, double yp) {
    double c1 = (x2 - x1) * (yp - y1) - (y2 - y1) * (xp - x1);
    double c2 = (x3 - x2) * (yp - y2) - (y3 - y2) * (xp - x2);
    double c3 = (x1 - x3) * (yp - y3) - (y1 - y3) * (xp - x3);
    return ((c1>0 && c2>0 && c3>0) || (c1<0 && c2<0 && c3<0));
}

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
  bool operator == (const Point &p) const{
    return fabs(x-p.x) < EPS && fabs(y-p.y) < EPS && fabs(z-p.z) < EPS;
  }
};

double dot (Point3D a, Point3D b) {
  return a.x * b.x + a.y * b.y + a.z * b.z;
}

Point3D cross (Point3D a, Point3D b) {
  return Point3D(a.y*b.z-a.z*b.y, a.z*b.x-a.x*b.z, a.x*b.y-a.y*b.x);
}

bool intersect(Point3D from, Point3D to, Point3D p1, Point3D p2, Point3D p3, Point3D &res) {
    // 平面の法線
    Point3D n = cross(p2 - p1, p3 - p1);
    // nにおける射影の長さ
    double s = dot(to - from, n);
    // バリアと平行
    if (abs(s) < EPS) return 0;

    // 起点からバリアの距離
    double r = dot(p1 - from, n);
    double t = r / s;
    // 起点と終点がバリアの同じ側にある
    if (t < -EPS || t > 1.0 + EPS) return 0;
    
    // 起点終点とバリアの交点
    Point3D res = from * (1 - t) + to * t;
    
    // // 交点がバリア内にあるかを判断する
    // Point3D d = cross(p2 - p1, res - p1);
    // Point3D e = cross(p3 - p2, res - p2);
    // Point3D f = cross(p1 - p3, res - p3);
    // // 交点がない
    // if (dot(d,e) < -EPS || dot(d,f) < -EPS) return 0;
    
    return 1;
}
// menu
// bool isRightTriangle(int a, int b, int c)
// pair<pair<double,double>, double> CircumscribedCircleOfATriangle(double x1, double y1, double x2, double y2, double x3, double y3)
// class Point
// -- dot (Point)
// -- cross (Point)
// -- contains (Point)
// -- parallel (Point)
// -- orthogonal (Point)
// -- ccw (Point)
// -- andrewScan (convex)
// -- triangle_area
// -- area(Polygon)
// -- symmetric_point 対称点
// class Circle (need Point)
// -- intersection (Circle)
// -- intersect_points (Circle)
// bool trangleContainsPoint(double x1, double y1, double x2, double y2, double x3, double y3, double xp, double yp)
// class Point3D
// -- dot (Point3D)
// -- cross (Point3D)
// -- intersect (Point3D)