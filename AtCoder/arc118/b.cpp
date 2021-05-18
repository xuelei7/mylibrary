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
    
    ll k,n,m;
    cin >> k >> n >> m;
    V<ll> a(k);
    rep(i,0,k) cin >> a[i];

    V<ll> b(k);
    priority_queue<pair<ll,ll>> pq;
    ll left = m;
    rep(i,0,k) {
        b[i] = m * a[i] / n;
        left -= b[i];
        pq.push({abs(n * b[i] - m * a[i]), i});
    }

    while (left-- && !pq.empty()) {
        auto tp = pq.top(); pq.pop();
        b[tp.second]++;
    }

    rep(i,0,k) {
        cout << b[i] << " \n"[i == k-1];
    }
    
    return 0;
}