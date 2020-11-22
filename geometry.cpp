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
// aoj0012
// returns if a polygon contains a point
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
bool parallel(Vector a, Vector b) {
  return abs(cross(a,b)) < EPS;
}

// from
// aoj0023
class Circle {
public:
  Point o;
  double r;
  Circle(Point o, double r = 0):o(o), r(r) {}
}
// 1: intersect, 0: outside, 2: B in A, -2: A in B
int intersection(Circle a, Circle b) {
  double dist = sqrt((a.o.x-b.o.x)*(a.o.x-b.o.x)+(a.o.y-b.o.y)*(a.o.y-b.o.y));
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

// from
// aoj0012
// return if the triangle contains a point
bool trangleContainsPoint(double x1, double y1, double x2, double y2, double x3, double y3, double xp, double yp) {
    double c1 = (x2 - x1) * (yp - y1) - (y2 - y1) * (xp - x1);
    double c2 = (x3 - x2) * (yp - y2) - (y3 - y2) * (xp - x2);
    double c3 = (x1 - x3) * (yp - y3) - (y1 - y3) * (xp - x3);
    return ((c1>0 && c2>0 && c3>0) || (c1<0 && c2<0 && c3<0));
}