#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1);
using ll = long long;
using ull = unsigned long long;
const int inf = 2e9;
const ll INF = 4e18;
const ll MOD = 1e9+7;
const double eps = 0.00000001;
typedef pair<int,int> P;

template <typename T>
class Triangle{
public:
  T xa, xb, xc, ya, yb, yc;
  T S, R;
  T a, b, c;
  T Ap, Bp, Cp;

  Triangle(T x1, T y1, T x2, T y2, T x3, T y3) {
    xa = x1; xb = x2; xc = x3;
    ya = y1; yb = y2; yc = y3;

    a = sqrt((xb-xc)*(xb-xc)+(yb-yc)*(yb-yc));
    b = sqrt((xa-xc)*(xa-xc)+(ya-yc)*(ya-yc));
    c = sqrt((xb-xa)*(xb-xa)+(yb-ya)*(yb-ya));

    S = abs((x2-x1)*(y3-y1) - (x3-x1)*(y2-y1))/2;
    R = a*b*c/(4*S);

    Ap = acos((b*b+c*c-a*a)/(2*b*c));
    Bp = acos((a*a+c*c-b*b)/(2*a*c));
    Cp = acos((b*b+a*a-c*c)/(2*b*a));
  }
};

double toAngle(double angle) {
  return 180 * angle / PI;
}

double toPI(double angle) {
  return PI * angle / 180;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  double x1,y1,x2,y2,x3,y3;
  cin>>x1>>y1>>x2>>y2>>x3>>y3;
  Triangle<double> tri(x1,y1,x2,y2,x3,y3);

  return 0;
}
