#include <bits/stdc++.h>
using namespace std;

//const double PI = acos(-1);
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

const int MAX_N = 100010;
ll K[MAX_N+1];
ll inv[MAX_N+1];

ll mul(ll _a, ll _b) {
  if (_b == 0) return 1LL;
  if (_b == 1) return _a;
  ll ans = mul(_a, _b/2);
  ans *= ans;
  ans %= MOD;
  if (_b&1) ans *= _a;
  return ans % MOD;
}

ll C(ll _n, ll _k) {
  if (_n == _k) return 1;
  if (_k == 0) return 1;
  return (K[_n] * ((inv[_k] * inv[_n-_k]) % MOD)) % MOD;
}

void init() {
  K[1] = 1;
  inv[1] = 1;
  inv[0] = 1;
  for (ll i = 2; i <= MAX_N; i++) {
    K[i] = K[i-1]*i;
    K[i] %= MOD;
    inv[i] = mul(K[i], MOD-2);
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  return 0;
}
