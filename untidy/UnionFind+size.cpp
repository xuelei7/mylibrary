#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1);
using ll = long long;
using ull = unsigned long long;
const int inf = 2e9;
const ll INF = 2e18;
const ll MOD = 1e9+7;

#define REP(i,n) for (int i = 0; i < (n); i++)
#define sz(s) (s).size()
#define pb push_back
#define fi first
#define se second

pair<ll,ll> par[150010];
ll rk[150010];
ll n, m;

void init (ll n) {
  for (int i = 0; i < n; i++) {
    par[i] = {i,1LL};
    rk[i] = 0LL;
  }
}

pair<ll,ll> fd(ll x) {
  if (par[x].fi == x) {
    return par[x];
  } else {
    return par[x] = fd(par[x].fi);
  }
}

ll unite (ll x, ll y) {
  x = fd(x).fi;
  y = fd(y).fi;
  ll xx = fd(x).se;
  ll yy = fd(y).se;
  //cout << x << " " << y << " " << xx << " " << yy << endl;
  if (x == y) return 0;

  if (rk[x] < rk[y]) {
    par[y].se += fd(x).se;
    par[x] = par[y];
  } else {
    par[x].se += fd(y).se;
    par[y] = par[x];
    if (rk[x] == rk[y]) rk[x]++;
  }
  return (ll)xx*(ll)yy;
}

void print() {
  cout << "-------------------------" << endl;
  for (int i = 0; i < n; i++) {
    cout << par[i].fi << " " << par[i].se << endl;
  }
  cout << "-------------------------" << endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m;
  init(n);
  vector<pair<ll,ll>> v;
  for (int i = 0; i < m; i++) {
    ll a, b;
    cin >> a >> b;
    --a;--b;
    v.pb({a,b});
  }


//  for (int i = 0; i < n; i++) {
//    cout << i+1 << " " << fd(i).fi+1 << " " << fd(i).se << endl;
//  }


  return 0;
}
