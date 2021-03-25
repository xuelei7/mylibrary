#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (int)(a); (i) < (int)(b); (i)++)
#define rrep(i, a, b) for (int i = (int)(b) - 1; (i) >= (int)(a); (i)--)
#define all(v) v.begin(), v.end()

typedef long long ll;
template <class T> using V = vector<T>;
template <class T> using VV = vector<V<T>>;

/* 提出時これをコメントアウトする */
// #define LOCAL true

#ifdef LOCAL
#define dbg(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl
#else
#define dbg(x) true
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    ll n;
    cin >> n;
    int ans = 0;
    for (ll i = 1; i <= 1000000; i++) {
        string s = to_string(i);
        s = s + s;
        ll num = 0;
        rep(j,0,s.size()) {
            num *= 10;
            num += s[j] - '0';
        }
        if (num <= n) ans++;
    }
    cout << ans << endl;
    
    return 0;
}