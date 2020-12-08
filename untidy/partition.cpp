#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;

ll memo[1200][1200];

ll pat(int t, int n) {
  if (t < 0) return 0;
  if (n == 0) return t == 0;
  if (t == 0) return 1;
  if (memo[t][n] >= 0) return memo[t][n];

  ll ret = 0;
  ret += pat(t-n, n) + pat(t, n - 1);
  return memo[t][n] = ret % MOD;
}

int main () {

  return 0;
}
