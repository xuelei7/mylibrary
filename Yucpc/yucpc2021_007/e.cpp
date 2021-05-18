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
    
    ll n,C;
    cin >> n >> C;
    V<ll> a(n), b(n), c(n);
    rep(i,0,n) cin >> a[i] >> b[i] >> c[i];

    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> v;
    rep(i,0,n) {
        v.push({a[i], c[i]});
        v.push({b[i]+1, -c[i]});
    }
    
    ll pre = -1, sum = 0;
    ll cost = 0;
    while (!v.empty()) {
        ll date = v.top().first;
        cost += min(C, sum) * (date - pre);
        pre = date;
        while (!v.empty() && v.top().first == date) {
            sum += v.top().second;
            v.pop();
        }
    }
    cout << cost << endl;
    return 0;
}