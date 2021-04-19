// A Point in a Triangle
// There is a triangle formed by three points (x1,y1), (x2,y2), (x3,y3) on a plain.

// Write a program which prints "YES" if a point P (xp,yp) is in the triangle and "NO" if not.

// Input
// Input consists of several datasets. Each dataset consists of:

// x1 y1 x2 y2 x3 y3 xp yp

// All the input are real numbers. Input ends with EOF. The number of datasets is less than or equal to 100.

// Constraints
// You can assume that:

// −100≤x1,y1,x2,y2,x3,y3,xp,yp≤100
// 1.0 ≤ Length of each side of a tringle
// 0.001 ≤ Distance between P and each side of a triangle

// Output
// For each dataset, print "YES" or "NO" in a line.

// to geometry

/* solution1 */
// #include <bits/stdc++.h>
// using namespace std;

// #define EPS (1e-10)
// class Point{
// public:
//   double x,y;
//   Point(double x = 0, double y = 0):x(x), y(y) {}
//   Point operator + (Point p){
//     return Point(x+p.x,y+p.y);
//   }
//   Point operator - (Point p){
//     return Point(x-p.x,y-p.y);
//   }
//   Point operator * (double k){
//     return Point(x*k,y*k);
//   }
//   Point operator / (double k){
//     return Point(x/k,y/k);
//   }
//   bool operator == (const Point &p) const{
//     return fabs(x-p.x) < EPS && fabs(y-p.y) < EPS;
//   }
// };
// typedef Point Vector;
// typedef vector<Point> Polygon;
// double dot(Vector a,Vector b){
//   return a.x * b.x + a.y * b.y;
// }
// double cross(Vector a,Vector b){
//   return a.x * b.y - a.y * b.x;
// }
// // IN 2 ON 1 OUT 0
// int contains(Polygon g,Point p){
//   int n=g.size();
//   bool x = false;
//   for(int i=0;i<n;i++){
//     Point a = g[i] - p, b = g[(i+1)%n] - p;
//     if(fabs(cross(a,b))<EPS && dot(a,b)<EPS) return 1;
//     if(a.y > b.y) swap(a,b);
//     if(a.y<EPS && EPS < b.y && cross(a,b) > EPS) x = !x;
//   }
//   return ( x ? 2:0);
// }

// int main() {
//     Point a,b,c,d;
//     while (cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y) {
//         Polygon p;
//         p.push_back(a);
//         p.push_back(b);
//         p.push_back(c);
//         if (contains(p,d)) {
//             cout << "YES" << endl;
//         } else {
//             cout << "NO" << endl;
//         }
//     }
//     return 0;
// }

/* solution 2 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    double x1,x2,x3,y1,y2,y3,xp,yp;
    while (cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> xp >> yp) {
        double c1 = (x2 - x1) * (yp - y1) - (y2 - y1) * (xp - x1);
        double c2 = (x3 - x2) * (yp - y2) - (y3 - y2) * (xp - x2);
        double c3 = (x1 - x3) * (yp - y3) - (y1 - y3) * (xp - x3);
        if ((c1>0 && c2>0 && c3>0) || (c1<0 && c2<0 && c3<0)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}