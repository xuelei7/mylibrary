#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1);
using ll = long long;
using ull = unsigned long long;
const int inf = 2e9;
const ll INF = 4e18;
const ll MOD = 1e9+7;
typedef pair<int,int> P;

double gcd(double x, double y) {
  double eps = 0.0001;
  while (abs(x) > eps && abs(y) > eps) {
    if (x > y) {
      x -= floor(x/y) * y;
    } else {
      y -= floor(y/x) * x;
    }
  }
  return x + y;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);


  return 0;
}
