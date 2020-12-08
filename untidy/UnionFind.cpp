#include <bits/stdc++.h>
using namespace std;

//const double PI = acos(-1);
using ll = long long;
using ull = unsigned long long;
const int inf = 2e9;
const ll INF = 4e18;
const ll MOD = 1e9+7;

int par[150010];
int rk[150010];

void init (int n) {
  for (int i = 0; i < n; i++) {
    par[i] = i;
    rk[i] = 0;
    edge[i] = make_pair(i,i);
  }
}

int fd(int x) {
  if (par[x] == x) {
    return x;
  } else {
    return par[x] = fd(par[x]);
  }
}

void unite (int x, int y) {
  x = fd(x);
  y = fd(y);
  if (x == y) return;

  if (rk[x] < rk[y]) {
    par[x] = y;
  } else {
    par[y] = x;
    if (rk[x] == rk[y]) rk[x]++;
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  init(n);
  for (int i = 0; i < n-1; i++) {
    int a, b;
    cin >> a >> b;
    --a;--b;
    unite(a,b);
  }

  return 0;
}
