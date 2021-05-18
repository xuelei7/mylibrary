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
    
    int n,m;
    cin >> n >> m;
    V<int> a(m), b(m);
    rep(i,0,m) {
        cin >> a[i] >> b[i];
    }
    int k;
    cin >> k;
    V<int> c(k), d(k);
    rep(i,0,k) {
        cin >> c[i] >> d[i];
    }

    int ans = 0;
    rep(i,0,(1<<k)) {
        int cnt = 0;
        bool ok[110] = {};
        rep(j,0,k) {
            if ((i>>j)&1) ok[c[j]] = 1;
            else ok[d[j]] = 1;
        }
        rep(j,0,m) {
            if (ok[a[j]] && ok[b[j]]) cnt++;
        }
        ans = max(ans, cnt);
    }
    cout << ans << endl;
    
    return 0;
}