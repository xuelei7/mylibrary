#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (int)(a); (i) < (int)(b); (i)++)
#define rrep(i, a, b) for (int i = (int)(b) - 1; (i) >= (int)(a); (i)--)
#define all(v) v.begin(), v.end()

typedef long long ll;
template <class T> using V = vector<T>;
template <class T> using VV = vector<V<T>>;

/* 提出時これをコメントアウトする */
#define LOCAL true

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
    V<ll> a(n);
    rep(i,0,n) cin >> a[i];

    V<ll> l(n+1),r(n+1);
    stack<ll> val, id;
    rep(i,0,n) {
        while (!val.empty() && val.top() >= a[i]) {
            val.pop();
            id.pop();
        }
        if (id.empty()) l[i] = 0;
        else l[i] = id.top()+1;
        val.push(a[i]);
        id.push(i);
    }
    while (!val.empty()) {
        val.pop();
        id.pop();
    }
    rrep(i,0,n) {
        while (!val.empty() && val.top() >= a[i]) {
            val.pop();
            id.pop();
        }
        if (id.empty()) r[i] = n;
        else r[i] = id.top();
        val.push(a[i]);
        id.push(i);
    }
    ll ans = 0;
    rep(i,0,n) {
        ans = max(ans, (r[i] - l[i]) * a[i]);
        // cout << l[i] << " " << r[i] << " " << a[i] << endl;
    }
    cout << ans << endl;
    return 0;
}